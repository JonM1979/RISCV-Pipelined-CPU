module tb_cpu;

logic [31:0] cycle;
logic clk;
logic reset;

// Instantiate CPU
cpu_top uut (
    .clk(clk),
    .reset(reset)
);

////////////////////////////////////////////////////////
// Clock generator (toggles every 5 time units)
////////////////////////////////////////////////////////
always #5 clk <= ~clk;

// Cycle counter and debug output
always_ff @( posedge clk ) begin
        cycle <= cycle + 1;
        $display("Cycle: %0d", cycle);
end

////////////////////////////////////////////////////////
// Simulation control
////////////////////////////////////////////////////////
initial begin
    clk = 0;
    reset = 1;
    cycle = 0;


    #10;       // wait 10 time units
    reset = 0; // release reset

    #100;      // run simulation

    $finish;
end

always_ff @( posedge clk ) begin
        cycle <= cycle + 1;
        $display("Cycle: %0d", cycle);
end

endmodule
