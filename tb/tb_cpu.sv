`include "defines.svh"
`include "disassemble.svh"

module tb_cpu;

// TESTBENCH DECLARATIONS
`include "tb_declarations.svh"

// DUT (Device Under Test) Instantiation
cpu_top uut (
    .clk(clk),
    .reset(reset),

    .trap_valid(trap_valid),
    .trap_cause(trap_cause),
    .trap_pc(trap_pc)
);

// INCLUDE TASKS FILES
`include "tb_helper_functions.svh"
`include "tb_performance_events.svh"

`include "summary_task.svh"
`include "instruction_trace.svh"
`include "data_trace.svh"
`include "tb_init_tasks.svh"
`include "tb_counter_update.svh"
`include "check_full_instruction_test.svh"
`include "check_all_hazards_test.svh"
`include "check_dispatch.svh"
`include "self_check_test.svh"
`include "trap_report.svh"
`include "riscv_compliance.svh"

// CLOCK GENERATOR
always #5 clk <= ~clk;

// SIMULATION CONTROL
initial begin

    open_output_files();

    if(!$value$plusargs("TEST=%s", test_name)) begin
        test_name = "none";
    end

    $display("Running test: %s", test_name);

    // Tests whose name begins with "trap_" are expected to raise a trap.
    // The expected cause is supplied with +EXPECT_CAUSE=<n>.
    if (test_name.len() >= 5 && test_name.substr(0, 4) == "trap_") begin
        expect_trap = 1'b1;
        if (!$value$plusargs("EXPECT_CAUSE=%d", expected_cause)) begin
            expected_cause = -1; // any cause accepted
        end
    end

    // Tests whose name begins with "riscvtest_" are official riscv-tests
    // images, compiled against env-mini's CSR-free harness. They always end
    // via their own concluding ECALL, interpreted through check_riscv_compliance_trap().
    if (test_name.len() >= 10 && test_name.substr(0, 9) == "riscvtest_") begin
        is_riscv_test = 1'b1;
    end
    initialize_counters();

    clk = 0;
    reset = 1;

    #10;
    reset = 0;

    // Safety timeout, if HALT instr never reaches WB
    // this prevents infinite simulation.
    // Configurable via +MAX_CYCLES=<n> since riscv-tests images are
    // substantially longer than this project's own hand-written tests.
    if (!$value$plusargs("MAX_CYCLES=%d", max_cycles)) begin
        max_cycles = 300;
    end
    repeat (max_cycles) @(posedge clk);

    $fatal(1, "TIMEOUT: neither HALT nor a terminating trap reached WB stage");

end

// COUNTER UPDATES
always_ff @(posedge clk) begin
    if (!reset) begin
        update_counters();
    end
end

// TRACE + SIMULATION END
// print on negative edge after values of
// registers, signals, etc. have updated
always @(negedge clk) begin
    if (!reset) begin
        instruction_trace();
        data_trace();

        // A trap ends the run immediately. riscv-tests images are routed to
        // the compliance checker, which interprets the ecall/a0 convention;
        // everything else uses report_trap(), which treats a trap as a
        // failure unless the test explicitly expects it.
        if (trap_valid) begin
            if (is_riscv_test) begin
                check_riscv_compliance_trap();
            end
            else begin
                report_trap();
            end
        end

        // End only after HALT is visibly in WB in the trace
        if (uut.mem_wb_instr == HALT_INSTR) begin
            $fdisplay(instruction_file, "\nHALT reached WB stage. Ending simulation.");
            $fdisplay(trace_file, "\nHALT reached WB stage. Ending simulation.");

            final_summary();
            run_selected_check();
            close_output_files();

            $finish;
        end
    end
end

endmodule
