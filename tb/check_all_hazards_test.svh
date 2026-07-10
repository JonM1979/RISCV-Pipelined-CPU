task automatic expect_reg(
    input int unsigned reg_index,
    input logic [31:0] expected,
    input string label
);
begin
    if (uut.rf.regs[reg_index] !== expected) begin
        $fatal(1,
            "%s failed: x%0d expected %0d (0x%08h), got %0d (0x%08h)",
            label,
            reg_index,
            expected,
            expected,
            uut.rf.regs[reg_index],
            uut.rf.regs[reg_index]
        );
    end
end
endtask


task automatic expect_mem(
    input int unsigned mem_index,
    input logic [31:0] expected,
    input string label
);
begin
    if (uut.dmem.mem[mem_index] !== expected) begin
        $fatal(1,
            "%s failed: mem[%0d] expected %0d (0x%08h), got %0d (0x%08h)",
            label,
            mem_index,
            expected,
            expected,
            uut.dmem.mem[mem_index],
            uut.dmem.mem[mem_index]
        );
    end
end
endtask


task automatic expect_counter(
    input int unsigned actual,
    input int unsigned expected,
    input string label
);
begin
    if (actual != expected) begin
        $fatal(1,
            "%s failed: expected %0d, got %0d",
            label,
            expected,
            actual
        );
    end
end
endtask


task automatic expect_counter_nonzero(
    input int unsigned actual,
    input string label
);
begin
    if (actual == 0) begin
        $fatal(1,
            "%s failed: expected nonzero count, got 0",
            label
        );
    end
end
endtask


task automatic check_hazard_all_test;
begin
    $display("\n==================== HAZARD ALL TEST CHECKS ====================");

    //////////////////////////////////////////////////////
    // Architectural state checks
    //////////////////////////////////////////////////////

    expect_reg(0,  32'd0,   "x0 hardwired zero");

    expect_reg(1,  32'd5,   "x1 base value");
    expect_reg(2,  32'd10,  "x2 base value");

    // EX/MEM forwarding checks
    expect_reg(3,  32'd15,  "x3 ADD result");
    expect_reg(4,  32'd25,  "EX/MEM forward A result");

    expect_reg(5,  32'd15,  "x5 ADD result");
    expect_reg(6,  32'd25,  "EX/MEM forward B result");

    // MEM/WB forwarding checks
    expect_reg(7,  32'd15,  "x7 ADD result");
    expect_reg(8,  32'd25,  "MEM/WB forward A result");

    expect_reg(9,  32'd15,  "x9 ADD result");
    expect_reg(10, 32'd25,  "MEM/WB forward B result");

    // Load-use hazard checks
    expect_reg(11, 32'd10,  "x11 LW result");
    expect_reg(12, 32'd15,  "Load-use rs1 result");

    expect_reg(13, 32'd10,  "x13 LW result");
    expect_reg(14, 32'd15,  "Load-use rs2 result");

    // Store-data forwarding checks
    expect_reg(15, 32'd33,  "x15 store-forward source");
    expect_reg(16, 32'd44,  "x16 store-forward source");

    // Branch forwarding and flush checks
    expect_reg(17, 32'd1,   "x17 branch source");
    expect_reg(18, 32'd18,  "BEQ flush result");

    expect_reg(19, 32'd2,   "x19 branch source");
    expect_reg(20, 32'd20,  "BNE flush result");

    // JAL checks
    expect_reg(21, 32'd128, "JAL link x21");
    expect_reg(22, 32'd22,  "JAL target result");

    // JALR target forwarding and flush checks
    expect_reg(23, 32'd148, "JALR target address source");
    expect_reg(24, 32'd144, "JALR link x24");
    expect_reg(25, 32'd25,  "JALR target result");

    // x0 protection follow-up
    expect_reg(26, 32'd26,  "x26 after x0 protection check");

    //////////////////////////////////////////////////////
    // Memory checks
    //////////////////////////////////////////////////////

    expect_mem(0, 32'd10, "mem[0] base store/load");
    expect_mem(1, 32'd33, "mem[1] store-data forwarding");
    expect_mem(2, 32'd44, "mem[2] delayed store-data forwarding");

    //////////////////////////////////////////////////////
    // Existing hazard/control counter checks
    //////////////////////////////////////////////////////

    // Two load-use hazards:
    //   lw x11 -> add x12
    //   lw x13 -> add x14
    expect_counter(stall_count,          2, "Total stall cycles");
    expect_counter(load_use_stall_count, 2, "Load-use stall count");

    // Two taken branches:
    //   BEQ
    //   BNE
    expect_counter(branch_taken_count,   2, "Taken branch count");

    // One JAL and one JALR
    expect_counter(jal_taken_count,      1, "Taken JAL count");
    expect_counter(jalr_taken_count,     1, "Taken JALR count");

    // Control redirects:
    //   BEQ + BNE + JAL + JALR = 4
    expect_counter(control_count,        4, "Control redirect count");
    expect_counter(flush_count,          4, "Flush count");

    //////////////////////////////////////////////////////
    // Existing forwarding counter sanity checks
    //////////////////////////////////////////////////////
    // These prove the test exercised forwarding paths.
    // Exact forwarding totals may change if the program is rearranged,
    // so nonzero checks are safer here.
    //////////////////////////////////////////////////////

    expect_counter_nonzero(ex_mem_forward_a_count, "EX/MEM forward A coverage");
    expect_counter_nonzero(ex_mem_forward_b_count, "EX/MEM forward B coverage");
    expect_counter_nonzero(mem_wb_forward_a_count, "MEM/WB forward A coverage");
    expect_counter_nonzero(mem_wb_forward_b_count, "MEM/WB forward B coverage");
    expect_counter_nonzero(total_forward_count,    "Total forwarding coverage");

    //////////////////////////////////////////////////////
    // Retired/instruction mix sanity checks
    //////////////////////////////////////////////////////

    expect_counter(retired_count, 36, "Retired instruction count");

    if ((rtype_count +
         itype_count +
         load_count +
         store_count +
         branch_instr_count +
         jal_instr_count +
         jalr_instr_count +
         lui_instr_count) != retired_count) begin

        $fatal(1,
            "Instruction mix total does not match retired count. mix=%0d retired=%0d",
            rtype_count +
            itype_count +
            load_count +
            store_count +
            branch_instr_count +
            jal_instr_count +
            jalr_instr_count +
            lui_instr_count,
            retired_count
        );
    end

    $display("PASS: hazard_all_test succeeded");
    $display("================================================================\n");

    $fdisplay(summary_file, "\n[TEST RESULT]");
    $fdisplay(summary_file, "Test Name                : hazard_all_test");
    $fdisplay(summary_file, "Result                   : PASS");
end
endtask
