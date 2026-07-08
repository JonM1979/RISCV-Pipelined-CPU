
// contains forwarding unit logic for the pipeline

`include "defines.svh"

module forwarding_unit(
    input logic [4:0] id_ex_rs1, id_ex_rs2, // source registers in ID/EX stage

    input logic id_ex_uses_rs1,
    input logic id_ex_uses_rs2,

    input logic [4:0] ex_mem_rd, // destination register in EX/MEM stage
    input logic ex_mem_reg_write, // whether EX/MEM stage writes to a register

    input logic [4:0] mem_wb_rd, // destination register in MEM/WB stage
    input logic mem_wb_reg_write, // whether MEM/WB stage writes to a register

    output logic [1:0] forward_a_sel, // whether to forward for rs1
    output logic [1:0] forward_b_sel  // whether to forward for rs2

);

always_comb begin
    // Default: no forwarding
    forward_a_sel = 2'b00;
    forward_b_sel = 2'b00;

    // Forwarding for rs1/operand A
    if (id_ex_uses_rs1) begin
        if (ex_mem_reg_write && (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs1)) begin
            forward_a_sel = 2'b10; // Forward from EX/MEM stage
        end 
        else if (mem_wb_reg_write && (mem_wb_rd != 5'd0) && (mem_wb_rd == id_ex_rs1)) begin
            forward_a_sel = 2'b01; // Forward from MEM/WB stage
        end
    end

    // Forwarding for rs2/operand B
    if (id_ex_uses_rs2) begin
        if (ex_mem_reg_write && (ex_mem_rd != 5'd0) && (ex_mem_rd == id_ex_rs2)) begin
            forward_b_sel = 2'b10; // Forward from EX/MEM stage
        end 
        else if (mem_wb_reg_write && (mem_wb_rd != 5'd0) && (mem_wb_rd == id_ex_rs2)) begin
            forward_b_sel = 2'b01; // Forward from MEM/WB stage
        end
    end
end

endmodule
