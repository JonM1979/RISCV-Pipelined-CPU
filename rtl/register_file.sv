module register_file(
    input logic clk,
    input logic we,     // Write enable
    input logic [4:0] rs1, rs2, rd,
    input logic [31:0] wd,  // write data
    output logic [31:0] rd1, rd2 // read data
);

// 32 registers
logic [31:0] regs [0:31];

// Read ports (combinational)
// This also makes sure that x0 is hardwired to 
// always read as 0                             
assign rd1 = (rs1 == 5'd0) ? 32'd0 : regs[rs1];
assign rd2 = (rs2 == 5'd0) ? 32'd0 : regs[rs2];

// Write port (sequential)
always_ff @( posedge clk ) begin
    if(we && rd != 5'd0) begin // Write to register if enabled and not x0
        regs[rd] <= wd;
    end
end

endmodule                         
