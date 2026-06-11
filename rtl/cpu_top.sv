module cpu_top(
    input logic clk,
    input logic reset
);

// Internal register signals
logic [31:0] pc; // Program Counter
logic [31:0] instr; // Current instruction
logic [4:0] rs1, rs2, rd; // Register indices
logic [31:0] rd1, rd2; // Register read data

assign rs1 = instr[19:15]; // Extract rs1 from instruction
assign rs2 = instr[24:20]; // Extract rs2 from instruction
assign rd  = instr[11:7];  // Extract rd from instruction

logic wb_we;
logic [31:0] wb_data;
logic [4:0] wb_rd;

// Instantiate Register File
register_file rf(
    .clk(clk),
    .we(wb_we),
    .rs1(rs1),
    .rs2(rs2),
    .rd(wb_rd),
    .wd(wb_data),
    .rd1(rd1),
    .rd2(rd2)
);

// Instantiate Instruction Memory
instruction_memory imem_inst(
    .addr(pc),
    .instr(instr)
);

assign wb_we = 0;
assign wb_rd = 0;
assign wb_data = 0;

////////////////
// Sequential Logic (updates on clock edge)
////////////////
always_ff @( posedge clk ) begin
    if(reset)
        pc <= 0; // Reset program counter
    else
        pc <= pc + 4; // Increment program counter (assuming 4-byte instructions)

end

endmodule
