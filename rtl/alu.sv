
`include "defines.svh"

module alu(
    input logic [31:0] a,b,
    input logic [3:0] alu_ctrl,
    output logic [31:0] result
);

always_comb begin
    case (alu_ctrl)
        ALU_ADD:    result = a + b;
        ALU_SUB:    result = a - b;

        ALU_SLL:    result = a << b[4:0];
        ALU_SLT:    result = ($signed(a) < $signed(b)) ? 32'd1 : 32'd0;
        ALU_SLTU:   result = (a < b) ? 32'd1 : 32'd0;

        ALU_XOR:    result = a ^ b;
        
        ALU_SRL:    result = a >> b[4:0];
        ALU_SRA:    result = $signed(a) >>> b[4:0];

        ALU_OR:     result = a | b;
        ALU_AND:    result = a & b;

        default:    result = 32'd0;
    endcase
end



endmodule
