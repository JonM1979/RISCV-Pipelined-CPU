// data_trace.svh

// prints useful data signals for debugging every cycle
task automatic data_trace;
begin

    // --------------CYCLE HEADER---------------------
    $fdisplay(trace_file,
        "\n============================================================"
    );

    $fdisplay(trace_file,
        "CYCLE %0d",
        cycle_count
    );

    $fdisplay(trace_file,
        "PC=%08h | STALL=%0b | CTRL_REDIRECT=%0b | TARGET=%08h",
        uut.pc,
        uut.stall,
        uut.control_taken,
        uut.control_target
    );

    $fdisplay(trace_file,
        "BRANCH_TAKEN=%0b | JAL_TAKEN=%0b | JALR_TAKEN=%0b | HALT_IN_WB=%0b",
        uut.branch_cond_taken,
        uut.jal_taken,
        uut.jalr_taken,
        (uut.mem_wb_instr == HALT_INSTR)
    );

    // --------------IF STAGE---------------------
    $fdisplay(trace_file,
        "\n[IF] Instruction Fetch"
    );

    $fdisplay(trace_file,
        "  Fetch PC          : %08h",
        uut.pc
    );

    $fdisplay(trace_file,
        "  Instruction Word  : %08h",
        uut.instr
    );

    $fdisplay(trace_file,
        "  Instruction       : %s",
        disasm(uut.instr)
    );

    // --------------ID STAGE---------------------
    $fdisplay(trace_file,
        "\n[ID] Decode / Register Read"
    );

    $fdisplay(trace_file,
        "  Instruction PC    : %08h",
        uut.if_id_pc
    );

    $fdisplay(trace_file,
        "  Instruction Word  : %08h",
        uut.if_id_instr
    );

    $fdisplay(trace_file,
        "  Instruction       : %s",
        disasm(uut.if_id_instr)
    );

    $fdisplay(trace_file,
        "  Opcode            : %02h",
        uut.opcode
    );

    $fdisplay(trace_file,
        "  Funct3 / Funct7   : %0h / %02h",
        uut.funct3,
        uut.funct7
    );

    $fdisplay(trace_file,
        "  Source Reg 1      : x%0d",
        uut.rs1
    );

    if (uut.uses_rs2) begin
        $fdisplay(trace_file,
            "  Source Reg 2      : x%0d",
            uut.rs2
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Source Reg 2      : unused"
        );
    end

    $fdisplay(trace_file,
        "  Destination Reg   : x%0d",
        uut.rd
    );

    $fdisplay(trace_file,
        "  Immediate Value   : %0d",
        uut.imm
    );

    $fdisplay(trace_file,
        "  Type Flags        : R=%0b I=%0b LOAD=%0b STORE=%0b BRANCH=%0b JAL=%0b JALR=%0b LUI=%0b",
        uut.is_rtype,
        uut.is_itype,
        uut.is_load,
        uut.is_store,
        uut.is_branch,
        uut.is_jal,
        uut.is_jalr,
        uut.is_lui
    );

    $fdisplay(trace_file,
        "  ALU Control       : %0h",
        uut.alu_ctrl
    );

    // --------------EX STAGE---------------------
    $fdisplay(trace_file,
        "\n[EX] Execute / ALU / Forwarding"
    );

    $fdisplay(trace_file,
        "  Instruction PC    : %08h",
        uut.id_ex_pc
    );

    $fdisplay(trace_file,
        "  Instruction Word  : %08h",
        uut.id_ex_instr
    );

    $fdisplay(trace_file,
        "  Instruction       : %s",
        disasm(uut.id_ex_instr)
    );

    $fdisplay(trace_file,
        "  Source Reg 1      : x%0d",
        uut.id_ex_rs1
    );

    if (uut.id_ex_uses_rs2) begin
        $fdisplay(trace_file,
            "  Source Reg 2      : x%0d",
            uut.id_ex_rs2
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Source Reg 2      : unused"
        );
    end

    $fdisplay(trace_file,
        "  Raw Reg Data 1    : %0d",
        uut.id_ex_rd1
    );

    if (uut.id_ex_uses_rs2) begin
        $fdisplay(trace_file,
            "  Raw Reg Data 2    : %0d",
            uut.id_ex_rd2
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Raw Reg Data 2    : unused"
        );
    end

    $fdisplay(trace_file,
        "  Immediate Value   : %0d",
        uut.id_ex_imm
    );

    $fdisplay(trace_file,
        "  Forwarded A       : %0d",
        uut.forward_a
    );

    if (uut.id_ex_uses_rs2) begin
        $fdisplay(trace_file,
            "  Forwarded B       : %0d",
            uut.forward_b
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Forwarded B       : unused"
        );
    end

    $fdisplay(trace_file,
        "  Forward Select A  : %b (%s)",
        uut.forward_a_sel,
        fwd_sel_name(uut.forward_a_sel)
    );

    if (uut.id_ex_uses_rs2) begin
        $fdisplay(trace_file,
            "  Forward Select B  : %b (%s)",
            uut.forward_b_sel,
            fwd_sel_name(uut.forward_b_sel)
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Forward Select B  : unused"
        );
    end

    $fdisplay(trace_file,
        "  Uses Immediate    : %0b",
        uut.ex_use_imm
    );

    $fdisplay(trace_file,
        "  ALU Result        : %0d (0x%08h)",
        uut.alu_result,
        uut.alu_result
    );

    // HAZARD / FLUSH INFO
    if (uut.stall) begin
        $fdisplay(trace_file,
            "\n[HAZARD] Load-Use Stall Detected"
        );

        $fdisplay(trace_file,
            "  EX Load Dest Reg  : x%0d",
            uut.id_ex_rd
        );

        $fdisplay(trace_file,
            "  ID Source Reg 1   : x%0d",
            uut.rs1
        );

        $fdisplay(trace_file,
            "  ID Source Reg 2   : x%0d",
            uut.rs2
        );
    end

    if (uut.control_taken) begin
        $fdisplay(trace_file,
            "\n[CONTROL] Pipeline Flush / Redirect"
        );

        $fdisplay(trace_file,
            "  Branch Taken      : %0b",
            uut.branch_cond_taken
        );

        $fdisplay(trace_file,
            "  JAL Taken         : %0b",
            uut.jal_taken
        );

        $fdisplay(trace_file,
            "  JALR Taken        : %0b",
            uut.jalr_taken
        );

        $fdisplay(trace_file,
            "  Redirect Target   : %08h",
            uut.control_target
        );
    end

    // --------------MEM STAGE---------------------
    $fdisplay(trace_file,
        "\n[MEM] Memory Access / Pass-Through"
    );

    $fdisplay(trace_file,
        "  Instruction Word  : %08h",
        uut.ex_mem_instr
    );

    $fdisplay(trace_file,
        "  Instruction       : %s",
        disasm(uut.ex_mem_instr)
    );

    $fdisplay(trace_file,
        "  Stage Opcode      : %02h",
        uut.ex_mem_opcode
    );

    if (uut.mem_re || uut.mem_we) begin
        $fdisplay(trace_file,
            "  Memory Access     : YES"
        );

        $fdisplay(trace_file,
            "  Effective Address : %08h",
            uut.ex_mem_result
        );

        $fdisplay(trace_file,
            "  Memory Read En    : %0b",
            uut.mem_re
        );

        $fdisplay(trace_file,
            "  Memory Write En   : %0b",
            uut.mem_we
        );

        $fdisplay(trace_file,
            "  Store Write Data  : %0d",
            uut.ex_mem_store_data
        );

        $fdisplay(trace_file,
            "  Load Read Data    : %0d",
            uut.mem_read_data
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Memory Access     : NO"
        );

        $fdisplay(trace_file,
            "  ALU Pass-Through  : %0d (0x%08h)",
            uut.ex_mem_result,
            uut.ex_mem_result
        );
    end

    // --------------WB STAGE---------------------
    $fdisplay(trace_file,
        "\n[WB] Writeback / Commit"
    );

    $fdisplay(trace_file,
        "  Instruction Word  : %08h",
        uut.mem_wb_instr
    );

    $fdisplay(trace_file,
        "  Instruction       : %s",
        disasm(uut.mem_wb_instr)
    );

    $fdisplay(trace_file,
        "  Writeback Opcode  : %02h",
        uut.mem_wb_opcode
    );

    $fdisplay(trace_file,
        "  Is Link Writeback  : %0b",
        uut.mem_wb_is_link
    );

    $fdisplay(trace_file,
        "  Link PC + 4        : %08h",
        uut.mem_wb_pc_plus_4
    );

    if (uut.wb_we && (uut.wb_rd != 5'd0)) begin
        $fdisplay(trace_file,
            "  Commit Valid      : YES"
        );

        $fdisplay(trace_file,
            "  Destination Reg   : x%0d",
            uut.wb_rd
        );

        $fdisplay(trace_file,
            "  Writeback Data    : %0d (0x%08h)",
            uut.wb_data,
            uut.wb_data
        );
    end
    else if (uut.wb_we && (uut.wb_rd == 5'd0)) begin
        $fdisplay(trace_file,
            "  Commit Valid      : NO"
        );

        $fdisplay(trace_file,
            "  Register Write    : blocked write to x0"
        );

        $fdisplay(trace_file,
            "  Attempted Data    : %0d (0x%08h)",
            uut.wb_data,
            uut.wb_data
        );
    end
    else begin
        $fdisplay(trace_file,
            "  Commit Valid      : NO"
        );

        $fdisplay(trace_file,
            "  Register Write    : none"
        );
    end

    $fdisplay(trace_file,
        "============================================================"
    );

end
endtask
