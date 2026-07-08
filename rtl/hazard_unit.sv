// contains code for the hazard detection unit in the pipeline

`include "defines.svh"

module hazard_unit(
    input logic [6:0] id_ex_opcode, // whether the instruction in ID/EX stage is a load
    input logic [4:0] id_ex_rd, // destination register in ID/EX stage

    input logic [4:0] id_rs1, id_rs2, // source registers in ID stage

    input logic id_uses_rs1, id_uses_rs2, // whether the instruction in ID stage uses rs1/rs2

    output logic stall // whether to stall the pipeline
);

always_comb begin
    // Default: no stall
    stall = 1'b0;

    // Check for load-use hazard
    if((id_ex_opcode == OPCODE_LOAD) && (id_ex_rd != 5'd0) &&
    (
        (id_uses_rs1 && (id_ex_rd == id_rs1) || 
        id_uses_rs2 && (id_ex_rd == id_rs2))
    )) 
    begin
        stall = 1'b1; // Stall the pipeline
    end
end

endmodule
