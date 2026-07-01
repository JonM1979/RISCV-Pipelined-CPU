// disassemble.svh

// helper function to print machine code into 
// readable instructions
function automatic string disasm(input logic [31:0] instr);

    logic [6:0] opcode;
    logic [2:0] funct3;
    logic [6:0] funct7;
    logic [4:0] rd, rs1, rs2;
    logic signed [31:0] imm_i;
    logic signed [31:0] imm_s;
    logic signed [31:0] imm_b;
    logic signed [31:0] imm_j;

    opcode = instr[6:0];
    funct3 = instr[14:12];
    funct7 = instr[31:25];
    rd     = instr[11:7];
    rs1    = instr[19:15];
    rs2    = instr[24:20];

    imm_i = {{20{instr[31]}}, instr[31:20]};
    imm_s = {{20{instr[31]}}, instr[31:25], instr[11:7]};
    imm_b = {{19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0};
    imm_j = {{11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0};

    if (instr == 32'h00000000)
        return "BUBBLE/FLUSH";

    if (instr == 32'h00000013)
        return "HALT/NOP: ADDI x0, x0, 0";

    if (instr == 32'h00500013)
        return "HALT: ADDI x0, x0, 5";

    case (opcode)

        OPCODE_I_TYPE: begin
            case (funct3)
                FUNCT3_ADD_SUB:
                    return $sformatf("ADDI x%0d, x%0d, %0d", rd, rs1, imm_i);

                default:
                    return $sformatf("I-TYPE? instr=%08h", instr);
            endcase
        end

        OPCODE_R_TYPE: begin
            case (funct3)

                FUNCT3_ADD_SUB: begin
                    if (funct7 == FUNCT7_SUB)
                        return $sformatf("SUB x%0d, x%0d, x%0d", rd, rs1, rs2);
                    if(funct7 == FUNCT7_ADD)
                        return $sformatf("ADD x%0d, x%0d, x%0d", rd, rs1, rs2);
                end

                FUNCT3_SLL:
                    return $sformatf("SLL x%0d, x%0d, x%0d", rd, rs1, rs2);

                FUNCT3_SLT:
                    return $sformatf("SLT x%0d, x%0d, x%0d", rd, rs1, rs2);

                FUNCT3_SLTU:
                    return $sformatf("SLTU x%0d, x%0d, x%0d", rd, rs1, rs2);

                FUNCT3_XOR:
                    return $sformatf("XOR x%0d, x%0d, x%0d", rd, rs1, rs2);

                FUNCT3_SR: begin
                    if (funct7 == FUNCT7_SUB)
                        return $sformatf("SRA x%0d, x%0d, x%0d", rd, rs1, rs2);
                    else
                        return $sformatf("SRL x%0d, x%0d, x%0d", rd, rs1, rs2);
                end

                FUNCT3_OR:
                    return $sformatf("OR x%0d, x%0d, x%0d", rd, rs1, rs2);

                FUNCT3_AND:
                    return $sformatf("AND x%0d, x%0d, x%0d", rd, rs1, rs2);

                default:
                    return $sformatf("R-TYPE? instr=%08h", instr);
            endcase
        end

        OPCODE_LOAD: begin
            case (funct3)
                FUNCT3_LW_SW:
                    return $sformatf("LW x%0d, %0d(x%0d)", rd, imm_i, rs1);

                default:
                    return $sformatf("LOAD? instr=%08h", instr);
            endcase
        end

        OPCODE_STORE: begin
            case (funct3)
                FUNCT3_LW_SW:
                    return $sformatf("SW x%0d, %0d(x%0d)", rs2, imm_s, rs1);

                default:
                    return $sformatf("STORE? instr=%08h", instr);
            endcase
        end

        OPCODE_BRANCH: begin
            case (funct3)
                FUNCT3_BEQ:
                    return $sformatf("BEQ x%0d, x%0d, %0d", rs1, rs2, imm_b);

                FUNCT3_BNE:
                    return $sformatf("BNE x%0d, x%0d, %0d", rs1, rs2, imm_b);

                FUNCT3_BLT:
                    return $sformatf("BLT x%0d, x%0d, %0d", rs1, rs2, imm_b);

                FUNCT3_BGE:
                    return $sformatf("BGE x%0d, x%0d, %0d", rs1, rs2, imm_b);

                default:
                    return $sformatf("BRANCH? instr=%08h", instr);
            endcase
        end

        OPCODE_JAL:
            return $sformatf("JAL x%0d, %0d", rd, imm_j);

        default:
            return $sformatf("UNKNOWN instr=%08h", instr);

    endcase

endfunction
