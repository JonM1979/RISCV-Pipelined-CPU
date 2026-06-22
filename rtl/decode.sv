
`include "defines.svh"

module decode(

    input logic [31:0] instr, // Instruction to decode

    // fields
    output logic [6:0] opcode, // Opcode field
    output logic [2:0] funct3,  // funct3 field
    output logic [6:0] funct7,  // funct7 field
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

    // execution control
    output logic [3:0] alu_ctrl
);

////////////////////////////////
// Field Extraction

    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];
    assign funct7 = instr[31:25];
    assign rd = instr[11:7];
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];

//////////////////////////////////

/////////////////////////////
// Instruction Type Detection

    assign is_load = (opcode == OPCODE_LOAD);
    assign is_store = (opcode == OPCODE_STORE);
    assign is_branch = (opcode == OPCODE_BRANCH);
    assign is_rtype = (opcode == OPCODE_R_TYPE);
    assign is_itype = (opcode == OPCODE_I_TYPE);
    assign is_jal = (opcode == OPCODE_JAL);

////////////////////////////

////////////////////////////////
// Immediate Generation

    logic [31:0] imm_i, imm_s, imm_b, imm_u, imm_j;

    assign imm_i = { {20{instr[31]}}, instr[31:20] }; // I-type immediate

    assign imm_s = { {20{instr[31]}}, instr[31:25], instr[11:7] }; // S-type immediate

    assign imm_b = { {19{instr[31]}}, instr[31], instr[7], instr[30:25], instr[11:8], 1'b0 }; // B-type immediate

    assign imm_u = { instr[31:12], 12'b0 }; // U-type immediate 

    assign imm_j = { {11{instr[31]}}, instr[31], instr[19:12], instr[20], instr[30:21], 1'b0 }; // J-type immediate

    // Select Immediate
    always_comb
    begin 
        case (opcode)

        OPCODE_I_TYPE,
        OPCODE_LOAD: 
            imm = imm_i; // I-type and Load instructions
        
        OPCODE_STORE:
            imm = imm_s; // S-type instructions
        
        OPCODE_BRANCH:
            imm = imm_b; // B-type instructions

        OPCODE_U_TYPE:
            imm = imm_u; // U-type instructions
        
        OPCODE_JAL:
            imm = imm_j; // J-type instructions

        default:
            imm = 32'b0; // Default case    
    endcase
end

// ALU Controller 
always_comb begin
    alu_ctrl = ALU_ADD;

    if(is_rtype) begin
        case(funct3)

            FUNCT3_ADD_SUB:
                begin
                    if(funct7 == FUNCT7_SUB)
                        alu_ctrl = ALU_SUB;
                    else
                        alu_ctrl = ALU_ADD;
                end
                
                FUNCT3_SLL: alu_ctrl = ALU_SLL;
                FUNCT3_SLT: alu_ctrl = ALU_SLT;
                FUNCT3_SLTU:    alu_ctrl = ALU_SLTU;
                FUNCT3_XOR:  alu_ctrl = ALU_XOR;


                FUNCT3_SR:
                    begin      
                        if(funct7 == FUNCT7_SUB)
                            alu_ctrl = ALU_SRA;
                        else
                            alu_ctrl = ALU_SRL;
            
                end      

                FUNCT3_OR: alu_ctrl = ALU_OR;
                FUNCT3_AND: alu_ctrl = ALU_AND;

                default: alu_ctrl = ALU_ADD;
        endcase
    end

    else if (is_itype || is_load || is_store ) 
    begin
        alu_ctrl = ALU_ADD; // address calc + ADDI
    end
end

endmodule 
