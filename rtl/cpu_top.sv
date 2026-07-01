
`include "defines.svh"

module cpu_top(
    input logic clk,
    input logic reset
);

logic stall; // Signal to indicate pipeline stall

///////////////////////////////////////////
// Instruction Fetch (IF)
///////////////////////////////////////////

logic [31:0] pc; // Program Counter
logic [31:0] instr; // Current instruction

// Jump and Branch Control Signals
logic control_taken;
logic [31:0] control_target;

// Sequential Logic (updates on clock edge)
always_ff @( posedge clk ) begin
    if(reset)
        pc <= 0; // Reset program counter
    else if(control_taken)
        pc <= control_target;
    else if (!stall) // Only update PC if not stalling
        pc <= pc + 4; // Increment program counter (assuming 4-byte instructions)
end

// Instantiate Instruction Memory
instruction_memory imem_inst(
    .addr(pc),
    .instr(instr)
);

///////////////////////////////////////////
// IF/ID Pipeline Register
///////////////////////////////////////////
logic [31:0] if_id_instr;

// Branch Signals
logic [31:0] if_id_pc;

always_ff @( posedge clk ) 
begin
    if(reset) begin
        if_id_instr <= 0;
        if_id_pc <= 0;
    end 
    else if (control_taken) begin
        if_id_instr <= 0; // flush if branch taken
        if_id_pc <= 0; // Flush
    end
    else if (!stall) begin
        if_id_instr <= instr;  // Pass instruction to next stage
        if_id_pc <= pc;
    end
end

///////////////////////////////////////////
// Instruction Decode + Register Read (ID)
///////////////////////////////////////////

// Instruction fields
logic [6:0] opcode;
logic [2:0] funct3;
logic [6:0] funct7;
logic [4:0] rs1, rs2, rd; // Register indices
logic [31:0] imm;
logic [3:0] alu_ctrl;

// decode outputs
logic is_load, is_store, is_branch, is_rtype, is_itype, is_jal;


decode dec(
    .instr(if_id_instr),

    .opcode(opcode),
    .funct3(funct3),
    .funct7(funct7),
    .rd(rd),
    .rs1(rs1),
    .rs2(rs2),

    .imm(imm),

    .is_load(is_load),
    .is_store(is_store),
    .is_branch(is_branch),
    .is_rtype(is_rtype),
    .is_itype(is_itype),
    .is_jal(is_jal),


    .alu_ctrl(alu_ctrl)
);

// Register file connections
logic [31:0] rd1, rd2; // Register read data

// Writeback controls (comes from WB stage)
logic wb_we;
logic [31:0] wb_data;
logic [4:0] wb_rd;

// Register File instance
register_file rf(
    .clk(clk),
    .we(wb_we),
    .rs1(rs1),
    .rs2(rs2),
    .rd(wb_rd),
    .wd(wb_data),
    .rd1(rd1),
    .rd2(rd2)
);

///////////////////////////////////////////
// STALL LOGIC (for load-use hazard)
///////////////////////////////////////////
logic [6:0] id_ex_opcode;
logic [4:0] id_ex_rd;

assign stall = 
    (id_ex_opcode == OPCODE_LOAD) && // Load instruction in EX stage
    (
        (id_ex_rd != 0) &&
        (
            (id_ex_rd == rs1) || // Load destination matches current instruction's rs1
            (id_ex_rd == rs2)    // Load destination matches current instruction's rs2
        )
    );
///////////////////////////////////////////
// ID/EX Pipeline Registers
///////////////////////////////////////////
logic [31:0] id_ex_rd1, id_ex_rd2;
logic [31:0] id_ex_imm;
logic [4:0] id_ex_rs1, id_ex_rs2;
logic [3:0] id_ex_alu_ctrl;
logic [31:0] id_ex_instr;

// carrying instruction class info into EX
logic id_ex_is_itype;
logic id_ex_is_load;
logic id_ex_is_store;
logic id_ex_is_branch;
logic id_ex_is_jal;

// Branch Logic 
logic [31:0] id_ex_pc;
logic [2:0] id_ex_funct3;

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        id_ex_rd1 <= 0;
        id_ex_rd2 <= 0;
        id_ex_imm <= 0;
        id_ex_rd <= 0;
        id_ex_opcode <= 0;
        id_ex_rs1 <= 0;
        id_ex_rs2 <= 0;
        id_ex_alu_ctrl <= 0;
        id_ex_pc <=0;
        id_ex_funct3 <= 0;
        id_ex_is_jal <= 0;
        id_ex_is_itype <=0;
        id_ex_is_store <= 0;
        id_ex_is_load <= 0;
        id_ex_is_branch <= 0;
        id_ex_instr <= 0;
    end
    else if (control_taken) begin
        // INSERT NOP
        id_ex_rd1 <= 0;
        id_ex_rd2 <= 0;
        id_ex_imm <= 0;
        id_ex_rd <= 0;
        id_ex_opcode <= 0;
        id_ex_rs1 <= 0;
        id_ex_rs2 <= 0;
        id_ex_alu_ctrl <= 0;
        id_ex_pc <=0;
        id_ex_funct3 <= 0;
        id_ex_is_jal <= 0;
        id_ex_is_itype <=0;
        id_ex_is_store <= 0;
        id_ex_is_load <= 0;
        id_ex_is_branch <= 0;
        id_ex_instr <= 0;
    end
    else if (stall) begin
        
        id_ex_rd1 <= 0;
        id_ex_rd2 <= 0;
        id_ex_imm <= 0;
        id_ex_rd <= 0;
        id_ex_opcode <= 0;
        id_ex_rs1 <= 0;
        id_ex_rs2 <= 0;
        id_ex_alu_ctrl <= 0;
        id_ex_pc <=0;
        id_ex_funct3 <= 0;
        id_ex_is_jal <= 0;
        id_ex_is_itype <=0;
        id_ex_is_store <= 0;
        id_ex_is_load <= 0;
        id_ex_is_branch <= 0;
        id_ex_instr <= 0;
    end
    else begin
    
        id_ex_rd1 <= (wb_we && (wb_rd != 0) && (wb_rd == rs1)) ? wb_data : rd1;
        id_ex_rd2 <= (wb_we && (wb_rd != 0) && (wb_rd == rs2)) ? wb_data : rd2;
        id_ex_instr <= if_id_instr;

        id_ex_imm <= imm;

        id_ex_rd <= rd;
        id_ex_opcode <= opcode;
        id_ex_rs1 <= rs1;
        id_ex_rs2 <= rs2;

        id_ex_alu_ctrl <= alu_ctrl;

        // Branch 
        id_ex_pc <= if_id_pc;
        id_ex_funct3 <= funct3;

        
        id_ex_is_itype  <= is_itype;
        id_ex_is_load   <= is_load;
        id_ex_is_store  <= is_store;
        id_ex_is_branch <= is_branch;

        // Jump
        id_ex_is_jal <= is_jal;
    end
end

///////////////////////////////////////////
// Fowarding Unit (for data hazard resolution)
///////////////////////////////////////////

logic [31:0] forward_a, forward_b;
logic [1:0] forward_a_sel, forward_b_sel;

// EX/MEM State declarations needed forwarding
logic [31:0] ex_mem_result;
logic [4:0]  ex_mem_rd;
logic [6:0]  ex_mem_opcode;
logic [31:0] ex_mem_forward_data;
logic ex_mem_regwrite;

// MEM/WB Stage delcarations needed by forwaring
logic [31:0] mem_wb_result;
logic [4:0]  mem_wb_rd;
logic [6:0]  mem_wb_opcode;
logic [31:0] mem_wb_pc_plus_4;
logic mem_wb_is_jal;
logic [31:0] mem_wb_forward_data;
logic mem_wb_regwrite;

assign ex_mem_forward_data = ex_mem_is_jal ? ex_mem_pc_plus_4 : ex_mem_result;
assign mem_wb_forward_data = mem_wb_is_jal ? mem_wb_pc_plus_4 : mem_wb_result;

assign ex_mem_regwrite = 
    (ex_mem_opcode == OPCODE_R_TYPE) ||
    (ex_mem_opcode == OPCODE_I_TYPE) ||
    (ex_mem_opcode == OPCODE_JAL);
// LOAD is excluded because load data is not valid yet in EX/MEM

assign mem_wb_regwrite =
    (mem_wb_opcode == OPCODE_R_TYPE) ||
    (mem_wb_opcode == OPCODE_I_TYPE) ||
    (mem_wb_opcode == OPCODE_LOAD)   ||
    (mem_wb_opcode == OPCODE_JAL);

// Forwarding priority:
// EX/MEM first for ALU ops
// MEM/WB second
// never forwards loads from EX/MEM because loaded data is not ready there 
always_comb begin
    forward_a_sel = 2'b00;
    forward_b_sel = 2'b00;

    // A
    if (ex_mem_regwrite && (ex_mem_rd != 0) && (ex_mem_rd == id_ex_rs1)) begin
        forward_a_sel = 2'b10;
    end
    else if (mem_wb_regwrite && (mem_wb_rd != 0) && (mem_wb_rd == id_ex_rs1)) begin
        forward_a_sel = 2'b01;
    end

    // B
    if (ex_mem_regwrite && (ex_mem_rd != 0) && (ex_mem_rd == id_ex_rs2)) begin
        forward_b_sel = 2'b10;
    end
    else if (mem_wb_regwrite && (mem_wb_rd != 0) && (mem_wb_rd == id_ex_rs2)) begin
        forward_b_sel = 2'b01;
    end
end

///////////////////////////////////////////
// Forwarding MUX
///////////////////////////////////////////

always_comb begin
    forward_a = id_ex_rd1;
    forward_b = id_ex_rd2;

    case (forward_a_sel)
        2'b10: forward_a = ex_mem_forward_data;
        2'b01: forward_a = mem_wb_forward_data;
        default: forward_a = id_ex_rd1;
    endcase

    case (forward_b_sel)
        2'b10: forward_b = ex_mem_forward_data;
        2'b01: forward_b = mem_wb_forward_data;
        default: forward_b = id_ex_rd2;
    endcase

end

///////////////////////////////////////////
// Execute Stage (EX)
///////////////////////////////////////////

// ALU Signals
logic [31:0] alu_result;

// operand B selection uses immediate for I-Type / load / store
logic ex_use_imm;
assign ex_use_imm = id_ex_is_itype || id_ex_is_load || id_ex_is_store;

// branch / jump control
logic branch_cond_taken, jal_taken;
logic [31:0] branch_target, jal_target, ex_pc_plus_4;


assign ex_pc_plus_4 = id_ex_pc + 32'd4;
assign branch_target = id_ex_pc + id_ex_imm;
assign jal_target = id_ex_pc + id_ex_imm;
assign jal_taken = id_ex_is_jal;


// Branch Logic
always_comb begin
    branch_cond_taken = 1'b0;

    if(id_ex_is_branch) begin
        case(id_ex_funct3)
            FUNCT3_BEQ:
                if(forward_a == forward_b)
                    branch_cond_taken = 1'b1;
            
            FUNCT3_BNE:
                if(forward_a != forward_b)
                    branch_cond_taken = 1'b1;
            
            default:
                branch_cond_taken = 1'b0;
        endcase
    end
end

assign control_taken = branch_cond_taken || jal_taken;
assign control_target = branch_cond_taken ? branch_target : jal_target;

// ALU
alu alu_inst(
    .a(forward_a),
    .b(ex_use_imm ? id_ex_imm : forward_b),
    .alu_ctrl(id_ex_alu_ctrl),
    .result(alu_result)
);

///////////////////////////////////////////
// EX/MEM Pipeline Registers
///////////////////////////////////////////

logic [31:0] ex_mem_store_data; // For store instructions, we need to pass the value to be stored
logic [31:0] ex_mem_pc_plus_4;
logic ex_mem_is_jal;
logic [31:0] ex_mem_instr;

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        ex_mem_result <= 0;
        ex_mem_rd <= 0;
        ex_mem_opcode <= 0;
        ex_mem_store_data <= 0;
        ex_mem_pc_plus_4 <= 0;
        ex_mem_is_jal <= 0;
        ex_mem_instr <= 0;
    end else 
    begin
        ex_mem_result <= alu_result; // Pass ALU result to MEM stage
        ex_mem_rd <= id_ex_rd; // Pass destination
        ex_mem_opcode <= id_ex_opcode; // Pass opcode to MEM stage
        ex_mem_store_data <= forward_b; // Pass the value to be stored for store instructions
        ex_mem_pc_plus_4 <= ex_pc_plus_4;
        ex_mem_is_jal <= id_ex_is_jal;
        ex_mem_instr <= id_ex_instr;
    end
end


///////////////////////////////////////////
// MEM Stage (Memory Access)
///////////////////////////////////////////
logic mem_we; // Memory write enable
logic mem_re; // Memory read enable
logic is_mem_load, is_mem_store;
logic [31:0] mem_read_data; // Data read from memory
logic [31:0] mem_wb_instr;

assign is_mem_load = (ex_mem_opcode == OPCODE_LOAD); // Load opcode
assign is_mem_store = (ex_mem_opcode == OPCODE_STORE); // Store opcode

assign mem_we = is_mem_store; // Enable memory write for store instructions
assign mem_re = is_mem_load; // Enable memory read for load instructions

// Data Memory instance
data_memory dmem(
    .clk(clk),
    .mem_we(mem_we),
    .mem_re(mem_re),
    .addr(ex_mem_result), // Use ALU result as memory address
    .write_data(ex_mem_store_data), // Use forwarded data for store instructions
    .read_data(mem_read_data) // Capture data read from memory
);

///////////////////////////////////////////
// MEM/WB Pipeline Registers
///////////////////////////////////////////

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        mem_wb_result <= 0;
        mem_wb_rd <= 0;
        mem_wb_opcode <= 0;
        mem_wb_pc_plus_4 <= 0;
        mem_wb_is_jal <= 0;
        mem_wb_instr <= 0;
    end else 
    begin
        if(is_mem_load)
            mem_wb_result <= mem_read_data; // Pass memory read data to WB stage for load instructions
        else
            mem_wb_result <= ex_mem_result; // Pass ALU result to WB stage for non-load instructions

        mem_wb_rd <= ex_mem_rd; // Pass destination register index to WB stage
        mem_wb_opcode <= ex_mem_opcode; // Pass opcode to WB stage
        mem_wb_pc_plus_4 <= ex_mem_pc_plus_4;
        mem_wb_is_jal <= ex_mem_is_jal;
        mem_wb_instr <= ex_mem_instr;
    end
end

///////////////////////////////////////////
// Writeback Stage (WB)
///////////////////////////////////////////

// Enable writeback for ADD/ADDI instructions
assign wb_we = 
    (mem_wb_opcode == OPCODE_R_TYPE) || // ADDI
    (mem_wb_opcode == OPCODE_I_TYPE) || // ADD
    (mem_wb_opcode == OPCODE_LOAD) ||   // Load
    (mem_wb_opcode == OPCODE_JAL);


// Destination Register
assign wb_rd = mem_wb_rd; // Write back to the destination register

// Data to write back
assign wb_data = mem_wb_forward_data;

endmodule
