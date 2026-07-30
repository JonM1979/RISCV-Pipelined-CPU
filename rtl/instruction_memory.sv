// Instruction memory. Word addressed, initialised from program.hex.

`include "defines.svh"

module instruction_memory #(
    parameter int DEPTH_WORDS = IMEM_WORDS
)(
    input  logic [31:0] addr,
    output logic [31:0] instr
);

localparam int ADDR_MSB = $clog2(DEPTH_WORDS) + 1;

logic [31:0] mem [0:DEPTH_WORDS-1];

// Address bits above the memory window and the two byte-offset bits are not
// used for indexing. Referencing them keeps lint clean without changing behaviour.
logic unused_addr_bits;
assign unused_addr_bits = |{addr[31:ADDR_MSB+1], addr[1:0]};

initial begin
    // Default instruction memory to bubbles
    for (int i = 0; i < DEPTH_WORDS; i++) begin
        mem[i] = 32'h00000000;
    end

    $readmemh("program.hex", mem);
end

assign instr = mem[addr[ADDR_MSB:2]];


endmodule
