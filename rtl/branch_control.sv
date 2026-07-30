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

// JALR target is (rs1 + imm) with bit 0 cleared, per the RISC-V spec
assign jalr_target = (forward_a + id_ex_imm) & 32'hffff_fffe;

assign jal_taken = id_ex_is_jal;
assign jalr_taken = id_ex_is_jalr;

// Branch Condition Calculations
always_comb begin
    branch_cond_taken = 1'b0; // Default: not taken

    if(id_ex_is_branch) begin
        case(id_ex_funct3)

            FUNCT3_BEQ:  branch_cond_taken = (forward_a == forward_b);
            FUNCT3_BNE:  branch_cond_taken = (forward_a != forward_b);

            FUNCT3_BLT:  branch_cond_taken = ($signed(forward_a) <  $signed(forward_b));
            FUNCT3_BGE:  branch_cond_taken = ($signed(forward_a) >= $signed(forward_b));

            FUNCT3_BLTU: branch_cond_taken = (forward_a < forward_b);
            FUNCT3_BGEU: branch_cond_taken = (forward_a >= forward_b);

            default: branch_cond_taken = 1'b0; // For unsupported funct3 values, default to not taken
        endcase
    end
end

// Control Flow Decision

assign control_taken = branch_cond_taken || jal_taken || jalr_taken;

always_comb begin
    if (branch_cond_taken || jal_taken)
        control_target = pc_rel_target; // both are PC-relative
    else if (jalr_taken)
        control_target = jalr_target;
    else
        control_target = 32'd0;         // no redirect active
end

endmodule
