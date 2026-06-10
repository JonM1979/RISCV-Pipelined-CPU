module tb_cpu;

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
always #5 clk = ~clk;

////////////////////////////////////////////////////////
// Simulation control
////////////////////////////////////////////////////////
initial begin
    clk = 0;
    reset = 1;

    #10;       // wait 10 time units
    reset = 0; // release reset

    #100;      // run simulation

    $finish;
end

endmodule