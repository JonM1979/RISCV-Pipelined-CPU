module cpu_top(
    input logic clk,
    input logic reset
);

// Internal register signals
logic [31:0] a,b;
logic [31:0] result;

// Instantiate ALU
alu alu_inst(
    .a(a),
    .b(b),
    .result(result)
);

////////////////
// Sequential Logic (updates on clock edge)
////////////////

always_ff @( posedge clk ) begin
    if(reset) begin
        a <= 10;
        b <= 20;
    end else begin
        a <= a + 1;
        b <= b + 1;
    end
end

////////
// Debug Output (prints every cycle)
///////

always_ff @( posedge clk ) begin
    $$display("Cycle: A=%0d B=%0d RESULT=%0d", a, b, resutlt);
end

endmodule