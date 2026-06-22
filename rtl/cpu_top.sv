
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

// Sequential Logic (updates on clock edge)
always_ff @( posedge clk ) 
begin
    if(reset)
        pc <= 0; // Reset program counter
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

always_ff @( posedge clk ) 
begin
    if(reset) begin
        //if_id_pc <= 0;
        if_id_instr <= 0;
    end 
    else if (!stall)
    begin
        if_id_instr <= instr;  // Pass instruction to next stage
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
logic [31:0] decoded_imm;

logic is_load, is_store, is_branch, is_rtype, is_itype, is_jtype, is_jal;


decode dec(
    .instr(if_id_instr),

    .opcode(opcode),
    .funct3(funct3),
    .funct7(funct7),
    .rd(rd),
    .rs1(rs1),
    .rs2(rs2),

    .imm(decoded_imm),

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
    end 
    else if (stall)
    begin
        // INSERT NOP
        id_ex_rd1 <= 0;
        id_ex_rd2 <= 0;
        id_ex_imm <= 0;
        id_ex_rd <= 0;
        id_ex_opcode <= 0; // NOP
        id_ex_rs1 <= 0;
        id_ex_rs2 <= 0;
        id_ex_alu_ctrl <= 0;
    end else
    begin
    
        id_ex_rd1 <= rd1;
        id_ex_rd2 <= rd2;

        id_ex_imm <= decoded_imm;


        id_ex_rd <= rd;
        id_ex_opcode <= opcode;
        id_ex_rs1 <= rs1;
        id_ex_rs2 <= rs2;
    end
end

///////////////////////////////////////////
// Fowarding Unit (for data hazard resolution)
///////////////////////////////////////////

logic [31:0] forward_a, forward_b;
logic [1:0] forward_a_sel, forward_b_sel;


logic [31:0] ex_mem_result;
logic [4:0]  ex_mem_rd;
logic [31:0] mem_wb_result;
logic [4:0]  mem_wb_rd;



always_comb begin
    forward_a_sel = 2'b00;
    forward_b_sel = 2'b00;

    // A
    if (mem_wb_rd != 0 && mem_wb_rd == id_ex_rs1)
        forward_a_sel = 2'b01;
    else if (ex_mem_rd != 0 && ex_mem_rd == id_ex_rs1)
        forward_a_sel = 2'b10;

    // B
    if (mem_wb_rd != 0 && mem_wb_rd == id_ex_rs2)
        forward_b_sel = 2'b01;
    else if (ex_mem_rd != 0 && ex_mem_rd == id_ex_rs2)
        forward_b_sel = 2'b10;
end


///////////////////////////////////////////
// Forwarding MUX
///////////////////////////////////////////

always_comb begin
    forward_a = id_ex_rd1;
    forward_b = id_ex_rd2;

    case (forward_a_sel)
        2'b10: forward_a = ex_mem_result;
        2'b01: forward_a = mem_wb_result;
        default: forward_a = id_ex_rd1;
    endcase

    case (forward_b_sel)
        2'b10: forward_b = ex_mem_result;
        2'b01: forward_b = mem_wb_result;
        default: forward_b = id_ex_rd2;
    endcase

end

///////////////////////////////////////////
// Execute Stage (EX)
///////////////////////////////////////////

// ALU Signals
logic [31:0] alu_result;

logic ex_is_imm, ex_is_load, ex_is_store; // Indicates if the instruction uses an immediate operand
assign ex_is_imm = (id_ex_opcode == OPCODE_I_TYPE); // ADDI opcode
assign ex_is_load = (id_ex_opcode == OPCODE_LOAD); // LW opcode
assign ex_is_store = (id_ex_opcode == OPCODE_STORE); // SW opcode

// ALU
alu alu_inst(
    .a(forward_a),
    .b( ex_is_imm || ex_is_load || ex_is_store ? id_ex_imm : forward_b),
    .alu_ctrl(id_ex_alu_ctrl),
    .result(alu_result)
);

///////////////////////////////////////////
// EX/MEM Pipeline Registers
///////////////////////////////////////////

logic [6:0] ex_mem_opcode;
logic [31:0] ex_mem_store_data; // For store instructions, we need to pass the value to be stored

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        ex_mem_result <= 0;
        ex_mem_rd <= 0;
        ex_mem_opcode <= 0;
        ex_mem_store_data <= 0;
    end else 
    begin
        ex_mem_result <= alu_result; // Pass ALU result to MEM stage
        ex_mem_rd <= id_ex_rd; // Pass destination
        ex_mem_opcode <= id_ex_opcode; // Pass opcode to MEM stage
        ex_mem_store_data <= forward_b; // Pass the value to be stored for store instructions
    end
end


///////////////////////////////////////////
// MEM Stage (Memory Access)
///////////////////////////////////////////
logic mem_we; // Memory write enable
logic mem_re; // Memory read enable
logic is_mem_load, is_mem_store;
logic [31:0] mem_read_data; // Data read from memory

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

logic [6:0] mem_wb_opcode;

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        mem_wb_result <= 0;
        mem_wb_rd <= 0;
        mem_wb_opcode <= 0;
    end else 
    begin
        if(is_mem_load)
            mem_wb_result <= mem_read_data; // Pass memory read data to WB stage for load instructions
        else
            mem_wb_result <= ex_mem_result; // Pass ALU result to WB stage for non-load instructions
        mem_wb_rd <= ex_mem_rd; // Pass destination register index to WB stage
        mem_wb_opcode <= ex_mem_opcode; // Pass opcode to WB stage
    end
end

///////////////////////////////////////////
// Writeback Stage (WB)
///////////////////////////////////////////

// Enable writeback for ADD/ADDI instructions
assign wb_we = 
    (mem_wb_opcode == OPCODE_R_TYPE) || // ADDI
    (mem_wb_opcode == OPCODE_I_TYPE) || // ADD
    (mem_wb_opcode == OPCODE_LOAD);   // Load


// Destination Register
assign wb_rd = mem_wb_rd; // Write back to the destination register

// Data to write back
assign wb_data = mem_wb_result; // Write back MEM stage result

endmodule
