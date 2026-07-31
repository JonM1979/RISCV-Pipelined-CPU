// Direction predictor: table of 2-bit saturating counters indexed by PC.
//
// Only the *direction* is predicted here. Branch and JAL targets are
// PC-relative and the offset is encoded in the instruction word, so the
// target can be computed combinationally in IF without a BTB. JALR is
// register-relative and is left unpredicted -- it resolves in EX like before.
//
// Counter states:
//   00 strongly not taken   01 weakly not taken
//   10 weakly taken         11 strongly taken
//
// The high bit is the prediction. Requiring two consecutive mispredictions to
// flip the direction is what makes this beat a static predictor on loops: the
// single not-taken exit of a loop no longer flips the prediction for the next
// entry.

`include "defines.svh"

module branch_predictor #(
    parameter int ENTRIES = 256
)(
    input  logic clk,
    input  logic reset,

    // Query port (IF stage)
    input  logic [31:0] query_pc,
    output logic        predict_taken,

    // Update port (EX stage, when a conditional branch resolves)
    input  logic        update_en,
    input  logic [31:0] update_pc,
    input  logic        update_taken
);

localparam int IDX_BITS = $clog2(ENTRIES);

// Index with the low PC bits above the byte offset. Instructions are word
// aligned, so bits [1:0] carry no information.
logic [IDX_BITS-1:0] query_index;
logic [IDX_BITS-1:0] update_index;

assign query_index  = query_pc [IDX_BITS+1:2];
assign update_index = update_pc[IDX_BITS+1:2];

// Upper PC bits and the byte offset play no part in indexing
logic unused_pc_bits;
assign unused_pc_bits = |{query_pc[31:IDX_BITS+2],  query_pc[1:0],
                          update_pc[31:IDX_BITS+2], update_pc[1:0]};

logic [1:0] counters [0:ENTRIES-1];

// Prediction is the high bit of the counter
assign predict_taken = counters[query_index][1];

// Saturating update
logic [1:0] current;
assign current = counters[update_index];

// The table is cleared one entry per cycle after reset. Reset is held long
// enough by the testbench to walk the whole table, and an un-initialised
// entry only costs a misprediction, never correctness.
logic [IDX_BITS:0] init_index;
logic              init_done;

assign init_done = init_index[IDX_BITS];

always_ff @(posedge clk) begin
    if (reset)
        init_index <= '0;
    else if (!init_done)
        init_index <= init_index + 1'b1;
end

always_ff @(posedge clk) begin
    if (!init_done) begin
        // Start weakly not-taken. Forward branches are more often not taken,
        // and this keeps a cold table from redirecting fetch the first time
        // it sees a branch.
        counters[init_index[IDX_BITS-1:0]] <= 2'b01;
    end
    else if (update_en) begin
        if (update_taken)
            counters[update_index] <= (current == 2'b11) ? 2'b11 : current + 2'b01;
        else
            counters[update_index] <= (current == 2'b00) ? 2'b00 : current - 2'b01;
    end
end

endmodule
