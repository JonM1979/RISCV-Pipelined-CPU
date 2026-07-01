module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

// Initialize instruction memory with a simple program
initial begin
    mem[ 0] = 32'h00a00093; // ADDI x1, x0, 10
    mem[ 1] = 32'h01400113; // ADDI x2, x0, 20

    // EX/MEM forwarding
    mem[ 2] = 32'h002081b3; // ADD x3, x1, x2        # x3=30
    mem[ 3] = 32'h00118233; // ADD x4, x3, x1        # uses x3 immediately, x4=40

    // MEM/WB / older-result forwarding
    mem[ 4] = 32'h00100293; // ADDI x5, x0, 1        # filler
    mem[ 5] = 32'h00218333; // ADD x6, x3, x2        # x6=50

    // Dual forwarding / chained ALU dependencies
    mem[ 6] = 32'h006203b3; // ADD x7, x4, x6        # x7=90
    mem[ 7] = 32'h00438433; // ADD x8, x7, x4        # uses x7 immediately, x8=130

    // Store-data forwarding
    mem[ 8] = 32'h00802223; // SW x8, 4(x0)          # store forwarded x8=130
    mem[ 9] = 32'h00402483; // LW x9, 4(x0)          # x9=130

    // Load-use hazard: should cause one stall
    mem[10] = 32'h00148533; // ADD x10, x9, x1       # load-use, x10=140

    // Branch operand forwarding / taken branch
    mem[11] = 32'h00500593; // ADDI x11, x0, 5
    mem[12] = 32'h00b58463; // BEQ x11, x11, +8      # taken, skip x12=99
    mem[13] = 32'h06300613; // ADDI x12, x0, 99      # should be skipped
    mem[14] = 32'h00c00613; // ADDI x12, x0, 12      # x12=12

    // Load-to-branch hazard: should stall, then branch taken
    mem[15] = 32'h00c02423; // SW x12, 8(x0)         # mem[2]=12
    mem[16] = 32'h00802683; // LW x13, 8(x0)         # x13=12
    mem[17] = 32'h00c68463; // BEQ x13, x12, +8      # load-branch hazard, taken
    mem[18] = 32'h04d00713; // ADDI x14, x0, 77      # should be skipped
    mem[19] = 32'h00e00713; // ADDI x14, x0, 14      # x14=14

    // JAL flush + link-register dependency
    mem[20] = 32'h00c007ef; // JAL x15, +12          # x15=PC+4=84, skip x16/x17
    mem[21] = 32'h04200813; // ADDI x16, x0, 66      # should be skipped
    mem[22] = 32'h04d00893; // ADDI x17, x0, 77      # should be skipped
    mem[23] = 32'h00178913; // ADDI x18, x15, 1      # x18=85

    // x0 protection check
    mem[24] = 32'h07b00013; // ADDI x0, x0, 123      # x0 must stay 0
    mem[25] = 32'h01300993; // ADDI x19, x0, 19      # x19=19 if x0 protected

    // HALT marker
    mem[26] = 32'h00500013; // HALT: ADDI x0, x0, 5
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];


endmodule
