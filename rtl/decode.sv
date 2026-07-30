// Full RV32I instruction decoder.
//
// Beyond field extraction and ALU control, this block is the single point
// where an instruction is classified as legal or illegal. Every encoding the
// datapath cannot execute correctly is reported through illegal_instr so the
// pipeline can suppress its side effects rather than silently committing a
// wrong result.

`include "defines.svh"

module decode(

    input logic [31:0] instr, // Instruction to decode

    // fields
    output logic [6:0] opcode, // Opcode field
    output logic [2:0] funct3,  // funct3 field
    output logic [4:0] rd, rs1, rs2, // Register fields

    // Decoded immediate values
    output logic [31:0] imm,

    // Control signals
    output logic is_load,
    output logic is_store,
    output logic is_branch,
    output logic is_rtype,
    output logic is_itype,
    output logic is_jal,
    output logic is_jalr,
    output logic is_lui,
    output logic is_auipc,
    output logic is_ecall,
    output logic is_ebreak,

    // Source register usage to drive hazard detection and forwarding
    output logic uses_rs1,
    output logic uses_rs2, 

    // Architectural write enable, generated once here and pipelined onward
    output logic reg_write,

    // Memory access control
    output logic [1:0] mem_size,     // MEM_SZ_BYTE / HALF / WORD
    output logic       mem_unsigned, // 1 = zero-extend loaded value (LBU/LHU)

    // Execution control
    output logic [3:0] alu_ctrl,

    // Raised when the encoding is not a legal RV32I instruction this core
    // can execute. Qualified with pipeline validity by the caller.
    output logic illegal_instr
);

////////////////////////////////
// Field Extraction
// funct7 and is_rtype are consumed only within this module (ALU control and
// legality checking). They are not exported, but remain visible to the
// waveform and to the testbench trace as decode-internal signals.

    logic [6:0] funct7;
    logic is_rtype;

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];
    assign rd = instr[11:7];
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];


/////////////////////////////
// Instruction Type Detection

    assign is_load = (opcode == OPCODE_LOAD);
    assign is_store = (opcode == OPCODE_STORE);
    assign is_branch = (opcode == OPCODE_BRANCH);
    assign is_rtype = (opcode == OPCODE_R_TYPE);
    assign is_itype = (opcode == OPCODE_I_TYPE);
    assign is_jal = (opcode == OPCODE_JAL);
    assign is_jalr = (opcode == OPCODE_JALR) && (funct3 == FUNCT3_JALR);
    assign is_lui = (opcode == OPCODE_LUI);
    assign is_auipc  = (opcode == OPCODE_AUIPC);

    // ECALL and EBREAK share opcode/funct3 and differ only in imm[11:0]
    assign is_ecall  = (opcode == OPCODE_SYSTEM) && (funct3 == FUNCT3_PRIV) &&
                       (instr[31:20] == 12'h000);
    assign is_ebreak = (opcode == OPCODE_SYSTEM) && (funct3 == FUNCT3_PRIV) &&
                       (instr[31:20] == 12'h001);


////////////////////////////////
// Source Register Usage

always_comb begin
    uses_rs1 = 1'b0;
    uses_rs2 = 1'b0;

    case (opcode)
        OPCODE_R_TYPE: begin
            uses_rs1 = 1'b1;
            uses_rs2 = 1'b1;
        end

        OPCODE_STORE, OPCODE_BRANCH: begin
            uses_rs1 = 1'b1;
            uses_rs2 = 1'b1;
        end

        OPCODE_I_TYPE, OPCODE_LOAD: begin
            uses_rs1 = 1'b1;
            uses_rs2 = 1'b0;
        end

        OPCODE_JALR: begin
            // Only a well-formed JALR actually reads rs1
            uses_rs1 = (funct3 == FUNCT3_JALR);
            uses_rs2 = 1'b0;
        end

        // LUI, AUIPC, JAL, FENCE, SYSTEM read no source registers
        default: begin
            uses_rs1 = 1'b0;
            uses_rs2 = 1'b0;
        end
    endcase
end

////////////////////////////////
// Register Write Enable
//
// Generated once here and pipelined down the stages. Previously each stage
// re-derived this from the opcode, which duplicated the instruction list in
// several places and made adding an instruction error prone.

always_comb begin
    case (opcode)
        OPCODE_R_TYPE,
        OPCODE_I_TYPE,
        OPCODE_LOAD,
        OPCODE_LUI,
        OPCODE_AUIPC,
        OPCODE_JAL:   reg_write = 1'b1;

        OPCODE_JALR:  reg_write = (funct3 == FUNCT3_JALR);

        default:      reg_write = 1'b0;
    endcase
end

////////////////////////////////
// Memory Access Width / Extension

always_comb begin
    mem_size     = MEM_SZ_WORD;
    mem_unsigned = 1'b0;

    // the different sizes of data that each load deals with 
    if (is_load) begin
        case (funct3)
            FUNCT3_LB:  begin mem_size = MEM_SZ_BYTE; mem_unsigned = 1'b0; end
            FUNCT3_LH:  begin mem_size = MEM_SZ_HALF; mem_unsigned = 1'b0; end
            FUNCT3_LW:  begin mem_size = MEM_SZ_WORD; mem_unsigned = 1'b0; end
            FUNCT3_LBU: begin mem_size = MEM_SZ_BYTE; mem_unsigned = 1'b1; end
            FUNCT3_LHU: begin mem_size = MEM_SZ_HALF; mem_unsigned = 1'b1; end
            default:    begin mem_size = MEM_SZ_WORD; mem_unsigned = 1'b0; end
        endcase
    end
    // the different sizes of data that each store deals with 
    else if (is_store) begin
        case (funct3)
            FUNCT3_SB: mem_size = MEM_SZ_BYTE;
            FUNCT3_SH: mem_size = MEM_SZ_HALF;
            FUNCT3_SW: mem_size = MEM_SZ_WORD;
            default:   mem_size = MEM_SZ_WORD;
        endcase
    end
end



////////////////////////////////
// Immediate Generation

    // extraction of imm bits and setting which bits to use 
    logic [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;

    assign imm_i = { {20{instr[31]}}, instr[31:20] };
    assign imm_s = { {20{instr[31]}}, instr[31:25], instr[11:7] };
    assign imm_b = { {19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0 };
    assign imm_u = { instr[31:12], 12'b0 };
    assign imm_j = { {11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0 };

always_comb begin
    case (opcode)
        OPCODE_I_TYPE,
        OPCODE_LOAD,
        OPCODE_JALR:   imm = imm_i;

        OPCODE_STORE:  imm = imm_s;
        OPCODE_BRANCH: imm = imm_b;

        OPCODE_LUI,
        OPCODE_AUIPC:  imm = imm_u;

        OPCODE_JAL:    imm = imm_j;

        default:       imm = 32'b0;
    endcase
end

// ALU Controller 
always_comb begin
    alu_ctrl = ALU_ADD;

    if (is_rtype) begin
        case (funct3)
            FUNCT3_ADD_SUB: alu_ctrl = (funct7 == FUNCT7_ALT) ? ALU_SUB : ALU_ADD;
            FUNCT3_SLL:     alu_ctrl = ALU_SLL;
            FUNCT3_SLT:     alu_ctrl = ALU_SLT;
            FUNCT3_SLTU:    alu_ctrl = ALU_SLTU;
            FUNCT3_XOR:     alu_ctrl = ALU_XOR;
            FUNCT3_SR:      alu_ctrl = (funct7 == FUNCT7_ALT) ? ALU_SRA : ALU_SRL;
            FUNCT3_OR:      alu_ctrl = ALU_OR;
            FUNCT3_AND:     alu_ctrl = ALU_AND;
            default:        alu_ctrl = ALU_ADD;
        endcase
    end
    else if (is_itype) begin
        case (funct3)
            FUNCT3_ADD_SUB: alu_ctrl = ALU_ADD;   // ADDI
            FUNCT3_SLT:     alu_ctrl = ALU_SLT;   // SLTI
            FUNCT3_SLTU:    alu_ctrl = ALU_SLTU;  // SLTIU
            FUNCT3_XOR:     alu_ctrl = ALU_XOR;   // XORI
            FUNCT3_OR:      alu_ctrl = ALU_OR;    // ORI
            FUNCT3_AND:     alu_ctrl = ALU_AND;   // ANDI
            FUNCT3_SLL:     alu_ctrl = ALU_SLL;   // SLLI
            // SRLI vs SRAI selected by the funct7 field of the immediate
            FUNCT3_SR:      alu_ctrl = (funct7 == FUNCT7_ALT) ? ALU_SRA : ALU_SRL;
            default:        alu_ctrl = ALU_ADD;
        endcase
    end
    else if (is_load || is_store || is_jalr || is_auipc) begin
        alu_ctrl = ALU_ADD;    // effective address / target / PC+imm
    end
    else if (is_lui) begin
        alu_ctrl = ALU_COPY_B;
    end
    else begin
        // Branches compare in branch_control; JAL/FENCE/SYSTEM need no ALU result
        alu_ctrl = ALU_NOP;
    end
end

////////////////////////////////
// Illegal Instruction Detection
//
// Each opcode validates the encoding fields it actually constrains. Anything
// that falls through is not a legal RV32I instruction for this core.

    logic legal_encoding;

always_comb begin
    legal_encoding = 1'b0;

    case (opcode)
        OPCODE_R_TYPE: begin
            // Only ADD/SUB and SRL/SRA may use the alternate funct7
            if ((funct3 == FUNCT3_ADD_SUB) || (funct3 == FUNCT3_SR))
                legal_encoding = (funct7 == FUNCT7_BASE) || (funct7 == FUNCT7_ALT);
            else
                legal_encoding = (funct7 == FUNCT7_BASE);
        end

        OPCODE_I_TYPE: begin
            // Shift immediates constrain the upper bits; others accept any imm
            if (funct3 == FUNCT3_SLL)
                legal_encoding = (funct7 == FUNCT7_BASE);
            else if (funct3 == FUNCT3_SR)
                legal_encoding = (funct7 == FUNCT7_BASE) || (funct7 == FUNCT7_ALT);
            else
                legal_encoding = 1'b1;
        end

        OPCODE_LOAD: begin
            legal_encoding = (funct3 == FUNCT3_LB)  || (funct3 == FUNCT3_LH) ||
                             (funct3 == FUNCT3_LW)  || (funct3 == FUNCT3_LBU) ||
                             (funct3 == FUNCT3_LHU);
        end

        OPCODE_STORE: begin
            legal_encoding = (funct3 == FUNCT3_SB) || (funct3 == FUNCT3_SH) ||
                             (funct3 == FUNCT3_SW);
        end

        OPCODE_BRANCH: begin
            // funct3 010 and 011 are not assigned in RV32I
            legal_encoding = (funct3 != 3'b010) && (funct3 != 3'b011);
        end

        OPCODE_JALR:   legal_encoding = (funct3 == FUNCT3_JALR);

        OPCODE_JAL,
        OPCODE_LUI,
        OPCODE_AUIPC:  legal_encoding = 1'b1;

        OPCODE_MISCMEM: legal_encoding = (funct3 == FUNCT3_FENCE);

        OPCODE_SYSTEM:  legal_encoding = is_ecall || is_ebreak;

        default:        legal_encoding = 1'b0;
    endcase
end

    assign illegal_instr = !legal_encoding;

endmodule 
