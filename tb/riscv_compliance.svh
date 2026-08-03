// Interprets a trap using the official riscv-tests ecall pass/fail
// convention, rather than treating every trap as an automatic failure the
// way report_trap() does for this project's own trap_* tests.
//
// The convention, defined by env-mini/riscv_test.h (a CSR-free stand-in for
// the official env/p/riscv_test.h, which this core cannot run because it
// requires CSRs this core does not implement):
//
//   RVTEST_PASS executes `ecall` with a0 = 0.
//   RVTEST_FAIL executes `ecall` with a0 = (failing_testnum << 1) | 1.
//
// Any trap cause OTHER than ECALL means the CPU itself did something wrong
// while executing the test body: the official test bodies use only plain
// arithmetic, branch, and load/store instructions, so there is no legitimate
// reason for one to trap except through its own concluding ECALL.
task automatic check_riscv_compliance_trap;
    logic [31:0] a0;
begin
    a0 = uut.rf.regs[10];

    if (trap_cause != CAUSE_ECALL) begin
        final_summary();
        close_output_files();
        $fatal(1,
            "riscv-tests FAIL: %s -- unexpected trap cause %0d (%s) at PC 0x%08h. Expected the test's own concluding ECALL; the CPU likely mis-executed an instruction in the test body.",
            test_name, trap_cause, trap_cause_name(trap_cause), trap_pc);
    end

    if (a0 == 32'd0) begin
        $display("\n==================== RISCV-TESTS RESULT ====================");
        $display("PASS: %s (a0 = 0)", test_name);
        $display("==============================================================\n");

        $fdisplay(summary_file, "\n[TEST RESULT]");
        $fdisplay(summary_file, "Test Name                : %s", test_name);
        $fdisplay(summary_file, "Result                   : PASS");

        final_summary();
        close_output_files();
        $finish;
    end
    else begin
        final_summary();
        close_output_files();
        $fatal(1,
            "riscv-tests FAIL: %s failed at sub-test %0d (a0 = 0x%08h)",
            test_name, a0 >> 1, a0);
    end
end
endtask
