// tb_performance_events.svh

// Performance Counter Event Signals
logic retire_valid;

logic id_ex_valid_for_forwarding;
logic id_ex_uses_rs1;
logic id_ex_uses_rs2;

logic ex_mem_forward_a_event;
logic ex_mem_forward_b_event;
logic mem_wb_forward_a_event;
logic mem_wb_forward_b_event;

// checks if instruction in MEM/WB stage is valid and not a HALT instruction
assign retire_valid =
    (uut.mem_wb_instr != 32'd0) &&
    (uut.mem_wb_instr != HALT_INSTR);

// checks if instruction in ID/EX stage is valid and not a HALT instruction
assign id_ex_valid_for_forwarding =
    (uut.id_ex_instr != 32'd0) &&
    (uut.id_ex_instr != HALT_INSTR);

// checks if instruction in ID/EX stage uses rs1
assign id_ex_uses_rs1 =
    id_ex_valid_for_forwarding &&
    instr_uses_rs1(uut.id_ex_opcode);

// checks if instruction in ID/EX stage uses rs2
assign id_ex_uses_rs2 =
    id_ex_valid_for_forwarding &&
    instr_uses_rs2(uut.id_ex_opcode);

// checks if forwarding from EX/MEM stage to ID/EX stage for rs1 is happening
assign ex_mem_forward_a_event =
    id_ex_uses_rs1 &&
    (uut.forward_a_sel == 2'b10);

// checks if forwarding from EX/MEM stage to ID/EX stage for rs2 is happening
assign ex_mem_forward_b_event =
    id_ex_uses_rs2 &&
    (uut.forward_b_sel == 2'b10);

// checks if forwarding from MEM/WB stage to ID/EX stage for rs1 is happening
assign mem_wb_forward_a_event =
    id_ex_uses_rs1 &&
    (uut.forward_a_sel == 2'b01);

// checks if forwarding from MEM/WB stage to ID/EX stage for rs2 is happening
assign mem_wb_forward_b_event =
    id_ex_uses_rs2 &&
    (uut.forward_b_sel == 2'b01);