// tb_helper_functions.svh

// Function to return the name of the forwarding selection signal
function automatic string fwd_sel_name(input logic [1:0] sel);
    case (sel)
        2'b00: return "REGFILE";
        2'b01: return "MEM/WB";
        2'b10: return "EX/MEM";
        default: return "UNKNOWN";
    endcase
endfunction

// Function to return the name of the ALU operation for rs1 usage
function automatic bit instr_uses_rs1(input logic [6:0] opcode);
    case (opcode)
        OPCODE_R_TYPE,
        OPCODE_I_TYPE,
        OPCODE_LOAD,
        OPCODE_STORE,
        OPCODE_BRANCH,
        OPCODE_JALR: return 1'b1;

        default: return 1'b0;
    endcase
endfunction

// Function to return the name of the ALU operation for rs2 usage
function automatic bit instr_uses_rs2(input logic [6:0] opcode);
    case (opcode)
        OPCODE_R_TYPE,
        OPCODE_STORE,
        OPCODE_BRANCH: return 1'b1;

        default: return 1'b0;
    endcase
endfunction
