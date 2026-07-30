
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
    localparam logic [6:0] OPCODE_AUIPC  = 7'b0010111; // AUIPC
    localparam logic [6:0] OPCODE_MISCMEM= 7'b0001111; // FENCE (executed as NOP)
    localparam logic [6:0] OPCODE_SYSTEM = 7'b1110011; // ECALL/EBREAK

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

    // Loads
    localparam logic [2:0] FUNCT3_LB      = 3'b000;
    localparam logic [2:0] FUNCT3_LH      = 3'b001;
    localparam logic [2:0] FUNCT3_LW      = 3'b010;
    localparam logic [2:0] FUNCT3_LBU     = 3'b100;
    localparam logic [2:0] FUNCT3_LHU     = 3'b101;

    // Stores
    localparam logic [2:0] FUNCT3_SB      = 3'b000;
    localparam logic [2:0] FUNCT3_SH      = 3'b001;
    localparam logic [2:0] FUNCT3_SW      = 3'b010;

    // Kept for backward compatibility with existing testbench disassembler
    localparam logic [2:0] FUNCT3_LW_SW   = 3'b010;

    // Branches
    localparam logic [2:0] FUNCT3_BEQ     = 3'b000;
    localparam logic [2:0] FUNCT3_BNE     = 3'b001;
    localparam logic [2:0] FUNCT3_BLT     = 3'b100;
    localparam logic [2:0] FUNCT3_BGE     = 3'b101;
    localparam logic [2:0] FUNCT3_BLTU    = 3'b110;
    localparam logic [2:0] FUNCT3_BGEU    = 3'b111;

    // JALR
    localparam logic [2:0] FUNCT3_JALR    = 3'b000;

    // FENCE / SYSTEM
    localparam logic [2:0] FUNCT3_FENCE   = 3'b000;
    localparam logic [2:0] FUNCT3_PRIV    = 3'b000; // ECALL/EBREAK

////////////////////////////////

////////////////////////////////
// Funct7 Values

    localparam logic [6:0] FUNCT7_BASE   = 7'b0000000; // ADD, SRL, SLL, etc.
    localparam logic [6:0] FUNCT7_ALT    = 7'b0100000; // SUB, SRA

    // Legacy aliases retained for the testbench disassembler
    localparam logic [6:0] FUNCT7_ADD    = 7'b0000000;
    localparam logic [6:0] FUNCT7_SUB    = 7'b0100000;
    
////////////////////////////////

////////////////////////////////
// ALU Control Signals
    localparam logic [3:0] ALU_ADD      = 4'd0;
    localparam logic [3:0] ALU_SUB      = 4'd1;
    localparam logic [3:0] ALU_SLL      = 4'd2;
    localparam logic [3:0] ALU_SLT      = 4'd3;
    localparam logic [3:0] ALU_SLTU     = 4'd4;
    localparam logic [3:0] ALU_XOR      = 4'd5;
    localparam logic [3:0] ALU_SRL      = 4'd6;
    localparam logic [3:0] ALU_SRA      = 4'd7;
    localparam logic [3:0] ALU_OR       = 4'd8;
    localparam logic [3:0] ALU_AND      = 4'd9;

    // LUI passes the immediate straight through
    localparam logic [3:0] ALU_COPY_B   = 4'd10;

    // Used when an instruction does not need an ALU result
    localparam logic [3:0] ALU_NOP      = 4'd15;
////////////////////////////////

////////////////////////////////
// Memory access width encoding (drives byte enables + load extension)
    localparam logic [1:0] MEM_SZ_BYTE  = 2'b00;
    localparam logic [1:0] MEM_SZ_HALF  = 2'b01;
    localparam logic [1:0] MEM_SZ_WORD  = 2'b10;
////////////////////////////////

////////////////////////////////
// Trap causes (subset of RISC-V machine cause codes)
    localparam logic [3:0] CAUSE_NONE            = 4'd0;
    localparam logic [3:0] CAUSE_ILLEGAL_INSTR   = 4'd2;
    localparam logic [3:0] CAUSE_BREAKPOINT      = 4'd3;
    localparam logic [3:0] CAUSE_LOAD_MISALIGN   = 4'd4;
    localparam logic [3:0] CAUSE_STORE_MISALIGN  = 4'd6;
    localparam logic [3:0] CAUSE_ECALL           = 4'd11;
    localparam logic [3:0] CAUSE_LOAD_FAULT      = 4'd5;
    localparam logic [3:0] CAUSE_STORE_FAULT     = 4'd7;
////////////////////////////////

////////////////////////////////
// Memory sizing (words). Address bits used = $clog2(DEPTH)+2
    localparam int IMEM_WORDS = 1024;
    localparam int DMEM_WORDS = 1024;
////////////////////////////////

`endif
