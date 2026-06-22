module data_memory(
    input logic clk,
    input logic mem_we, // write enable
    input logic mem_re, // read enable
    input logic [31:0] addr,
    input logic [31:0] write_data,
    output logic [31:0] read_data
);

// 256-word data memory
logic [31:0] mem [0:255];

// Initialize memory with zeros
initial begin
    for (int i = 0; i < 256; i++) 
    begin
        mem[i] = 0;
    end
end

// Write (on clock)
always_ff @(posedge clk) begin
    if (mem_we) begin
        mem[addr[9:2]] <= write_data; // Word-aligned address
    end
end

// Read (combinational)
always_comb 
begin
    if (mem_re) 
        read_data = mem[addr[9:2]]; // Word-aligned address
    else
        read_data = 32'b0; // Return zero if not reading
end

endmodule
