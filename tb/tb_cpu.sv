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
// Clock generator
////////////////////////////////////////////////////////
always #5 clk <= ~clk;

////////////////////////////////////////////////////////
// Simulation control
////////////////////////////////////////////////////////
initial begin
    clk = 0;
    reset = 1;
    cycle = 0;

    #10;
    reset = 0;

    #100;
    $finish;
end

////////////////////////////////////////////////////////
// Corrected Pipeline-Aware Display + Checks
////////////////////////////////////////////////////////
always_ff @(posedge clk) begin
    if (!reset) begin
        cycle <= cycle + 1;

        //////////////////////////////////////////////////////
        // ✅ Better pipeline visibility
        //////////////////////////////////////////////////////
        
        $display(
        "C=%0d | IF=%h | ID=%h | EX(rs1=%0d rs2=%0d) | RAW(rd1=%0d rd2=%0d) | FWD_A=%0d FWD_B=%0d | SEL_A=%b SEL_B=%b | EX_OUT=%0d | WB(rd=%0d data=%0d)",
        cycle,
        uut.instr,
        uut.if_id_instr,
        uut.id_ex_rs1,
        uut.id_ex_rs2,
        uut.id_ex_rd1,
        uut.id_ex_rd2,
        uut.forward_a,
        uut.forward_b,
        uut.forward_a_sel,
        uut.forward_b_sel,
        uut.alu_result,
        uut.mem_wb_rd,
        uut.mem_wb_result
        );


        //////////////////////////////////////////////////////
        // ✅ Pipeline validity check (correct version)
        //////////////////////////////////////////////////////
        if (cycle > 0) begin
            // Check for invalid (X) values only
            if (^uut.if_id_instr === 1'bx) begin
                $fatal("ERROR: IF/ID contains invalid (X) value");
            end
        end
    end
end

endmodule
