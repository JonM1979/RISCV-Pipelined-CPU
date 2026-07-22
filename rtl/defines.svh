
`ifndef DEFINES_SVH
`define DEFINES_SVH

////////////////////////////////
// OPCODE Definitions

    localparam logic [6:0] OPCODE_R_TYPE = 7'b0110011; // R-type instruction opcode
    localparam logic [6:0] OPCODE_I_TYPE = 7'b0010011; // I-type instruction opcode
    localparam logic [6:0] OPCODE_LOAD   = 7'b0000011; // Load instruction opcode
    localparam logic [6:0] OPCODE_STORE  = 7'b0100011; // Store instruction opcode
    localparam logic [6:0] OPCODE_BRANCH = 7'b1100011; // Branch instruction opcode
    localparam logic [6:0] OPCODE_JALR   = 7'b1100111; // JALR instruction opcode
    localparam logic [6:0] OPCODE_JAL    = 7'b1101111; // JAL instruction opcode
    localparam logic [6:0] OPCODE_LUI    = 7'b0110111; // LUI instruction opcode

////////////////////////////////

////////////////////////////////
// Funct3 Values

    // R-Type and I-Type Instructions
    localparam logic [2:0] FUNCT3_ADD_SUB   = 3'b000; // Addition and Subtraction funct3 for RType 
    localparam logic [2:0] FUNCT3_SLL    = 3'b001; // Shift left funct3
    localparam logic [2:0] FUNCT3_SLT    = 3'b010; // Set less than funct3
    localparam logic [2:0] FUNCT3_SLTU   = 3'b011; // Set less than unsigned funct3
    localparam logic [2:0] FUNCT3_XOR    = 3'b100; // Exclusive or funct3
    localparam logic [2:0] FUNCT3_SR    = 3'b101; // Covers Shift right logical and arithmetic funct3 
    localparam logic [2:0] FUNCT3_OR     = 3'b110; // Or funct3
    localparam logic [2:0] FUNCT3_AND    = 3'b111; // And funct3

    // I-Type Load, S-Type Store, and B-Type Branch Instructions
    localparam logic [2:0] FUNCT3_LW_SW     = 3'b010; // Load and Store word funct3
    localparam logic [2:0] FUNCT3_BEQ    = 3'b000; // Branch if equal funct3
    localparam logic [2:0] FUNCT3_BNE    = 3'b001; // Branch if not equal funct3
    localparam logic [2:0] FUNCT3_BLT    = 3'b100; // Branch if less than funct3
    localparam logic [2:0] FUNCT3_BGE    = 3'b101; // Branch if greater

    // JALR
    localparam logic [2:0] FUNCT3_JALR   = 3'b000; // JALR funct3

////////////////////////////////

////////////////////////////////
// Funct7 Values

    localparam logic [6:0] FUNCT7_ADD    = 7'b0000000; // Addition funct7
    localparam logic [6:0] FUNCT7_SUB    = 7'b0100000; // Subtraction funct7
    localparam logic [6:0] FUNCT7_SRL    = 7'b0000000; // Shift right logical funct7
    
////////////////////////////////

////////////////////////////////
// ALU Control Signals
    localparam logic [3:0] ALU_ADD      = 4'd0;
    localparam logic [3:0] ALU_SUB      = 4'd1;
    localparam logic [3:0] ALU_SLL      = 4'd2;
    localparam logic [3:0] ALU_SLT      = 4'd3;
    localparam logic [3:0] ALU_XOR      = 4'd4;
    localparam logic [3:0] ALU_SRL      = 4'd5;
    localparam logic [3:0] ALU_OR       = 4'd6;
    localparam logic [3:0] ALU_AND      = 4'd7;

    // For LUI instruction, the ALU will just pass the immediate value to the output
    localparam logic [3:0] ALU_COPY_B   = 4'd8; 

    // Used when an instruction does not need the ALU result
    // ex: branches use branch_control.sv for comparison/redirect
    localparam logic [3:0] ALU_NOP      = 4'd15;
////////////////////////////////

`endif
