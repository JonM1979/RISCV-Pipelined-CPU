module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

// Initialize instruction memory with a simple program
initial begin
    // Example placeholder instructions (hex values)
    mem[0] = 32'h00100093; // ADDI x1, x0, 1
    mem[1] = 32'h00200113; // ADDI  x2, x0, 2

    // Store x2 into memory [x1 + 0]
    mem[2] = 32'h0020A023; // SW x2, 0(x1)

    // Load back into x3 from memory [x1 + 0]
    mem[3] = 32'h0000A183; // LW  x3, 0(x1)

    // Check Load result 
    mem[4] = 32'h003181B3; // ADD x3, x3, x3 (x3 should be 4 after this instruction)

    mem[5] = 32'h00000000; // NOP (or end of program)
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];

endmodule
