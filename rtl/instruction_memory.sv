module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

// Initialize instruction memory with a simple program
initial begin
    // Example placeholder instructions (hex values)
    mem[0] = 32'h00500093; // ADDI x1, x0, 5
    mem[1] = 32'h00500113; // ADDI  x2, x0, 5

    mem[2] = 32'h00208463; // BEQ x1, x2, +8

    // Load back into x3 from memory [x1 + 0]
    mem[3] = 32'h00100193; // ADDI x3, x0, 1 (should be skipped)

    mem[4] = 32'h00900193; // ADDI x3, x0, 9 (should execute)

    mem[5] = 32'h00000000; // NOP (or end of program)
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];

endmodule
