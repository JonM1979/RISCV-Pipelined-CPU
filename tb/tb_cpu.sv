`include "defines.svh"
`include "disassemble.svh"

module tb_cpu;

// TESTBENCH DECLARATIONS
`include "tb_declarations.svh"

// DUT (Device Under Test) Instantiation
cpu_top uut (
    .clk(clk),
    .reset(reset)
);

// INCLUDE TASKS FILES
`include "tb_helper_functions.svh"
`include "tb_performance_events.svh"

`include "summary_task.svh"
`include "instruction_trace.svh"
`include "data_trace.svh"
`include "tb_init_tasks.svh"
`include "tb_counter_update.svh"

// CLOCK GENERATOR
always #5 clk <= ~clk;

// SIMULATION CONTROL
initial begin

    open_output_files();
    initialize_counters();

    clk = 0;
    reset = 1;

    #10;
    reset = 0;

    // Safety timeout, if HALT instr never reaches WB
    // this prevents infinite simulation
    repeat (300) @(posedge clk);

    $fatal(1, "TIMEOUT: HALT instruction did not reach WB stage");

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

        // End only after HALT is visibly in WB in the trace
        if (uut.mem_wb_instr == HALT_INSTR) begin
            $fdisplay(instruction_file, "\nHALT reached WB stage. Ending simulation.");
            $fdisplay(trace_file, "\nHALT reached WB stage. Ending simulation.");

            final_summary();
            close_output_files();

            $finish;
        end
    end
end

endmodule
