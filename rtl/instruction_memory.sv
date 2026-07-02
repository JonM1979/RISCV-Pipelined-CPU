module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

// Initialize instruction memory with a simple program
initial begin
    mem[ 0] = 32'h000010b7; // lui x1, 0x1
    mem[ 1] = 32'h00300113; // addi x2, x0, 3
    mem[ 2] = 32'h002081b3; // add x3, x1, x2
    mem[ 3] = 32'h40218233; // sub x4, x3, x2
    mem[ 4] = 32'h00500293; // addi x5, x0, 5
    mem[ 5] = 32'h00a00313; // addi x6, x0, 10
    mem[ 6] = 32'h0062e3b3; // or x7, x5, x6
    mem[ 7] = 32'h0062f433; // and x8, x5, x6
    mem[ 8] = 32'h0063c4b3; // xor x9, x7, x6
    mem[ 9] = 32'h0062a533; // slt x10, x5, x6
    mem[10] = 32'h00a295b3; // sll x11, x5, x10
    mem[11] = 32'h00a5d633; // srl x12, x11, x10
    mem[12] = 32'h00228693; // addi x13, x5, 2
    mem[13] = 32'h0073f713; // andi x14, x7, 7
    mem[14] = 32'h00876793; // ori x15, x14, 8
    mem[15] = 32'h0037c813; // xori x16, x15, 3
    mem[16] = 32'h0062a893; // slti x17, x5, 6
    mem[17] = 32'h00229913; // slli x18, x5, 2
    mem[18] = 32'h00295993; // srli x19, x18, 2
    mem[19] = 32'h01002023; // sw x16, 0(x0)
    mem[20] = 32'h00002a03; // lw x20, 0(x0)
    mem[21] = 32'h00528463; // beq x5, x5, beq_pass
    mem[22] = 32'h06f00a93; // addi x21, x0, 111
    mem[23] = 32'h00100a93; // addi x21, x0, 1
    mem[24] = 32'h00629463; // bne x5, x6, bne_pass
    mem[25] = 32'h06f00b13; // addi x22, x0, 111
    mem[26] = 32'h00200b13; // addi x22, x0, 2
    mem[27] = 32'h0062c463; // blt x5, x6, blt_pass
    mem[28] = 32'h06f00b93; // addi x23, x0, 111
    mem[29] = 32'h00300b93; // addi x23, x0, 3
    mem[30] = 32'h00535463; // bge x6, x5, bge_pass
    mem[31] = 32'h06f00c13; // addi x24, x0, 111
    mem[32] = 32'h00400c13; // addi x24, x0, 4
    mem[33] = 32'h00800cef; // jal x25, jal_pass
    mem[34] = 32'h06f00d13; // addi x26, x0, 111
    mem[35] = 32'h01a00d13; // addi x26, x0, 26
    mem[36] = 32'h09c00e13; // addi x28, x0, 156
    mem[37] = 32'h000e0ee7; // jalr x29, 0(x28)
    mem[38] = 32'h06f00f13; // addi x30, x0, 111
    mem[39] = 32'h01e00f13; // addi x30, x0, 30
    mem[40] = 32'h00500013; // HALT: addi x0, x0, 5
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];


endmodule
