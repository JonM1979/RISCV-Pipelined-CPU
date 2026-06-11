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

always_ff @(posedge clk) begin
    if (!reset) begin
        cycle <= cycle + 1;

        $display("Cycle=%0d | PC=%h | INSTR=%h | rs1=%0d rs2=%0d rd=%0d | R1=%0d R2=%0d",
                  cycle, uut.pc, uut.instr, uut.rs1, uut.rs2, uut.rd,
                  uut.rd1, uut.rd2);
    end
end

endmodule
