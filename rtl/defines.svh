
`ifndef DEFINES_SVH
`define DEFINES_SVH

////////////////////////////////
// OPCODE Definitions

    localparam OPCODE_R_TYPE = 7'b0110011; // R-type instruction opcode
    localparam OPCODE_I_TYPE = 7'b0010011; // I-type instruction opcode
    localparam OPCODE_LOAD   = 7'b0000011; // Load instruction opcode
    localparam OPCODE_STORE  = 7'b0100011; // Store instruction opcode
    localparam OPCODE_BRANCH = 7'b1100011; // Branch instruction opcode
    localparam OPCODE_U_TYPE = 7'b0110111; // U-type instruction opcode
    localparam OPCODE_JAL    = 7'b1101111; // JAL instruction opcode

////////////////////////////////

////////////////////////////////
// Funct3 Values

    // R-Type and I-Type Instructions
    localparam FUNCT3_ADD_SUB   = 3'b000; // Addition and Subtraction funct3 for RType 
    localparam FUNCT3_SLL    = 3'b001; // Shift left funct3
    localparam FUNCT3_SLT    = 3'b010; // Set less than funct3
    localparam FUNCT3_SLTU   = 3'b011; // Set less than unsigned funct3
    localparam FUNCT3_XOR    = 3'b100; // Exclusive or funct3
    localparam FUNCT3_SR    = 3'b101; // Covers Shift right logical and arithmetic funct3 
    localparam FUNCT3_OR     = 3'b110; // Or funct3
    localparam FUNCT3_AND    = 3'b111; // And funct3

    // I-Type Load, S-Type Store, and B-Type Branch Instructions
    localparam FUNCT3_LW_SW     = 3'b010; // Load and Store word funct3
    localparam FUNCT3_BEQ    = 3'b000; // Branch if equal funct3
    localparam FUNCT3_BNE    = 3'b001; // Branch if not equal funct3
    localparam FUNCT3_BLT    = 3'b100; // Branch if less than funct3
    localparam FUNCT3_BGE    = 3'b101; // Branch if greater

////////////////////////////////

////////////////////////////////
// Funct7 Values

    localparam FUNCT7_ADD    = 7'b0000000; // Addition funct7
    localparam FUNCT7_SUB    = 7'b0100000; // Subtraction funct7
    
////////////////////////////////

////////////////////////////////
// ALU Control Signals
    localparam ALU_ADD  = 4'b0000;
    localparam ALU_SUB  = 4'b0001;
    localparam ALU_SLL  = 4'b0010;
    localparam ALU_SLT  = 4'b0011;
    localparam ALU_SLTU = 4'b0100;
    localparam ALU_XOR  = 4'b0101;
    localparam ALU_SRL  = 4'b0110;
    localparam ALU_SRA  = 4'b0111;
    localparam ALU_OR   = 4'b1000;
    localparam ALU_AND  = 4'b1001;
////////////////////////////////

`endif
