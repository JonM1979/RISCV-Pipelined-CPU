module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

// Initialize instruction memory with a simple program
initial begin
    // Example placeholder instructions (hex values)
    mem[0] = 32'h00000013; // NOP (ADDI x0, x0, 0)
    mem[1] = 32'h00100093; // ADDI x1, x0, 1
    mem[2] = 32'h00200113; // ADDI x2, x0, 2
    mem[3] = 32'h003081b3; // ADD x3, x1, x3
    mem[4] = 32'h00000013; // NOP
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];

endmodule
