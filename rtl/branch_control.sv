// defines branching control logic for the pipeline

`include "defines.svh"

module branch_control(
    input logic id_ex_is_branch, // whether the instruction in ID/EX stage is a branch
    input logic id_ex_is_jal, // whether the instruction in ID/EX stage is a JAL
    input logic id_ex_is_jalr, // whether the instruction in ID/EX stage is a JALR

    input logic [2:0] id_ex_funct3, // funct3 field of the instruction in ID/EX stage

    input logic [31:0] id_ex_pc,
    input logic [31:0] id_ex_imm, // immediate value for branch target calculation

    input logic [31:0] forward_a, // forwarded value for rs1
    input logic [31:0] forward_b, // forwarded value for rs2

    output logic branch_cond_taken, // whether the branch condition is met
    output logic jal_taken,        
    output logic jalr_taken, 

    output logic control_taken, // whether any control flow instruction is taken
    output logic [31:0] control_target // target address for the taken control flow instruction

);

// Target Calculations
logic [31:0] pc_rel_target; // shared relative PC target for branches and JAL
logic [31:0] jalr_target; // target address for JALR

assign pc_rel_target = id_ex_pc + id_ex_imm;
assign jalr_target = (forward_a + id_ex_imm) & 32'hffff_fffe; 
// JALR target address is computed as (rs1 + imm) with the least significant bit cleared

assign jal_taken = id_ex_is_jal;
assign jalr_taken = id_ex_is_jalr;

// Branch Condition Calculations
always_comb begin
    branch_cond_taken = 1'b0; // Default: not taken

    if(id_ex_is_branch) begin
        case(id_ex_funct3)

            FUNCT3_BEQ: begin
                branch_cond_taken = (forward_a == forward_b);
            end

            FUNCT3_BNE: begin
                branch_cond_taken = (forward_a != forward_b);
            end

            FUNCT3_BLT: begin
                branch_cond_taken = ($signed(forward_a) < $signed(forward_b));
            end

            FUNCT3_BGE: begin
                branch_cond_taken = ($signed(forward_a) >= $signed(forward_b));
            end

            default: begin
                branch_cond_taken = 1'b0; // For unsupported funct3 values, default to not taken
            end
        endcase
    end
end

// Control Flow Decision

assign control_taken = branch_cond_taken || jal_taken || jalr_taken;

always_comb begin
    if(branch_cond_taken) begin
        control_target = branch_target;
    end 
    else if (jal_taken) begin
        control_target = jal_target;
    end 
    else if(jalr_taken) begin
        control_target = jalr_target;
    end 
    else begin
        control_target = 32'd0; // Default target when no control flow instruction is taken
    end
end

endmodule
