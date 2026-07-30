// Load-use hazard detection.
//
// A load produces its data in MEM, one stage too late for a consumer already
// in EX. Forwarding cannot cover that gap, so the dependent instruction is
// held in ID for one cycle and a bubble is injected into EX.

`include "defines.svh"

module hazard_unit(
    input  logic id_ex_is_load, // instruction in EX is a load
    input logic [4:0] id_ex_rd, // destination register in ID/EX stage

    input logic [4:0] id_rs1, id_rs2, // source registers in ID stage
    input logic id_uses_rs1, id_uses_rs2, // whether the instruction in ID stage uses rs1/rs2

    output logic stall // whether to stall the pipeline
);

logic rs1_conflict;
logic rs2_conflict;

// Writes to x0 are discarded, so they can never create a real dependency
assign rs1_conflict = id_uses_rs1 && (id_ex_rd == id_rs1);
assign rs2_conflict = id_uses_rs2 && (id_ex_rd == id_rs2);

assign stall = id_ex_is_load && (id_ex_rd != 5'd0) &&
               (rs1_conflict || rs2_conflict);

endmodule
