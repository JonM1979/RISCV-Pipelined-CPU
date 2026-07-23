task automatic check_self_check_test;
begin
    $display("\n==================== SELF-CHECK TEST CHECKS ====================");

    if (uut.rf.regs[0] !== 32'd0) begin
        $fatal(1,
            "x0 hardwired-zero check failed: expected 0, got %0d",
            uut.rf.regs[0]
        );
    end

    if (uut.rf.regs[31] !== 32'd1) begin
        $fatal(1,
            "Self-check program failed: x31 expected PASS value 1, got %0d",
            uut.rf.regs[31]
        );
    end

    $display("PASS: self-checking test succeeded");
    $display("===============================================================\n");

    $fdisplay(summary_file, "\n[TEST RESULT]");
    $fdisplay(summary_file, "Test Name                : %s", test_name);
    $fdisplay(summary_file, "Result                   : PASS");
end
endtask
