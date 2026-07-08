module instruction_memory(
    input logic [31:0] addr,
    output logic [31:0] instr
);

// Simple instruction memory array (256 instructions)
logic [31:0] mem [0:255];

integer i;

// Prevent unused-address-bit warnings.
logic unused_addr_bits;
assign unused_addr_bits = |{addr[31:10], addr[1:0]};

initial begin
    // Default instruction memory to bubbles
    for(i = 0; i < 256; i = i + 1) begin
        mem[i] = 32'h00000000;
    end

    // Load assembled program.
    $readmemh("program.hex", mem);
end

// Word-aligned instruction fetch (divide address by 4)
assign instr = mem[addr[9:2]];


endmodule
