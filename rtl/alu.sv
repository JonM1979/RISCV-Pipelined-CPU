
`include "defines.svh"

module alu(
    input logic [31:0] a,b,
    input logic [3:0] alu_ctrl,
    output logic [31:0] result
);

assign result = a + b;

endmodule
