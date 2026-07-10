task automatic check_full_instruction_test;
begin
    $display("\n==================== FULL INSTRUCTION TEST CHECKS ====================");

    if (uut.rf.regs[0]  !== 32'd0)
        $fatal(1, "x0 failed: expected 0, got %0d", uut.rf.regs[0]);

    if (uut.rf.regs[1]  !== 32'd4096)
        $fatal(1, "x1 LUI failed: expected 4096, got %0d", uut.rf.regs[1]);

    if (uut.rf.regs[2]  !== 32'd3)
        $fatal(1, "x2 ADDI failed: expected 3, got %0d", uut.rf.regs[2]);

    if (uut.rf.regs[3]  !== 32'd4099)
        $fatal(1, "x3 ADD failed: expected 4099, got %0d", uut.rf.regs[3]);

    if (uut.rf.regs[4]  !== 32'd4096)
        $fatal(1, "x4 SUB failed: expected 4096, got %0d", uut.rf.regs[4]);

    if (uut.rf.regs[5]  !== 32'd5)
        $fatal(1, "x5 ADDI failed: expected 5, got %0d", uut.rf.regs[5]);

    if (uut.rf.regs[6]  !== 32'd10)
        $fatal(1, "x6 ADDI failed: expected 10, got %0d", uut.rf.regs[6]);

    if (uut.rf.regs[7]  !== 32'd15)
        $fatal(1, "x7 OR failed: expected 15, got %0d", uut.rf.regs[7]);

    if (uut.rf.regs[8]  !== 32'd0)
        $fatal(1, "x8 AND failed: expected 0, got %0d", uut.rf.regs[8]);

    if (uut.rf.regs[9]  !== 32'd5)
        $fatal(1, "x9 XOR failed: expected 5, got %0d", uut.rf.regs[9]);

    if (uut.rf.regs[10] !== 32'd1)
        $fatal(1, "x10 SLT failed: expected 1, got %0d", uut.rf.regs[10]);

    if (uut.rf.regs[11] !== 32'd10)
        $fatal(1, "x11 SLL failed: expected 10, got %0d", uut.rf.regs[11]);

    if (uut.rf.regs[12] !== 32'd5)
        $fatal(1, "x12 SRL failed: expected 5, got %0d", uut.rf.regs[12]);

    if (uut.rf.regs[13] !== 32'd7)
        $fatal(1, "x13 ADDI failed: expected 7, got %0d", uut.rf.regs[13]);

    if (uut.rf.regs[14] !== 32'd7)
        $fatal(1, "x14 ANDI failed: expected 7, got %0d", uut.rf.regs[14]);

    if (uut.rf.regs[15] !== 32'd15)
        $fatal(1, "x15 ORI failed: expected 15, got %0d", uut.rf.regs[15]);

    if (uut.rf.regs[16] !== 32'd12)
        $fatal(1, "x16 XORI failed: expected 12, got %0d", uut.rf.regs[16]);

    if (uut.rf.regs[17] !== 32'd1)
        $fatal(1, "x17 SLTI failed: expected 1, got %0d", uut.rf.regs[17]);

    if (uut.rf.regs[18] !== 32'd20)
        $fatal(1, "x18 SLLI failed: expected 20, got %0d", uut.rf.regs[18]);

    if (uut.rf.regs[19] !== 32'd5)
        $fatal(1, "x19 SRLI failed: expected 5, got %0d", uut.rf.regs[19]);

    if (uut.rf.regs[20] !== 32'd12)
        $fatal(1, "x20 LW failed: expected 12, got %0d", uut.rf.regs[20]);

    if (uut.rf.regs[21] !== 32'd1)
        $fatal(1, "x21 BEQ failed: expected 1, got %0d", uut.rf.regs[21]);

    if (uut.rf.regs[22] !== 32'd2)
        $fatal(1, "x22 BNE failed: expected 2, got %0d", uut.rf.regs[22]);

    if (uut.rf.regs[23] !== 32'd3)
        $fatal(1, "x23 BLT failed: expected 3, got %0d", uut.rf.regs[23]);

    if (uut.rf.regs[24] !== 32'd4)
        $fatal(1, "x24 BGE failed: expected 4, got %0d", uut.rf.regs[24]);

    if (uut.rf.regs[25] !== 32'd136)
        $fatal(1, "x25 JAL link failed: expected 136, got %0d", uut.rf.regs[25]);

    if (uut.rf.regs[26] !== 32'd26)
        $fatal(1, "x26 JAL target failed: expected 26, got %0d", uut.rf.regs[26]);

    if (uut.rf.regs[27] !== 32'd0)
        $fatal(1, "x27 should remain 0, got %0d", uut.rf.regs[27]);

    if (uut.rf.regs[28] !== 32'd156)
        $fatal(1, "x28 JALR target address failed: expected 156, got %0d", uut.rf.regs[28]);

    if (uut.rf.regs[29] !== 32'd152)
        $fatal(1, "x29 JALR link failed: expected 152, got %0d", uut.rf.regs[29]);

    if (uut.rf.regs[30] !== 32'd30)
        $fatal(1, "x30 JALR target failed: expected 30, got %0d", uut.rf.regs[30]);

    if (uut.rf.regs[31] !== 32'd0)
        $fatal(1, "x31 should remain 0, got %0d", uut.rf.regs[31]);

    if (uut.dmem.mem[0] !== 32'd12)
        $fatal(1, "mem[0] SW/LW failed: expected 12, got %0d", uut.dmem.mem[0]);

    $display("PASS: full supported-instruction test succeeded");
    $display("=====================================================================\n");

    $fdisplay(summary_file, "\n[TEST RESULT]");
    $fdisplay(summary_file, "Test Name                : full_instruction_test");
    $fdisplay(summary_file, "Result                   : PASS");
end
endtask
