
module cpu_top(
    input logic clk,
    input logic reset
);

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
    else
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
    end else begin
        //if_id_pc <= pc; // Pass PC to next stage
        if_id_instr <= instr; // Pass instruction to next stage
    end
end

///////////////////////////////////////////
// Instruction Decode + Register Read (ID)
///////////////////////////////////////////

// Instruction fields
logic [4:0] rs1, rs2, rd; // Register indices
assign rs1 = if_id_instr[19:15]; // Extract rs1 from instruction
assign rs2 = if_id_instr[24:20]; // Extract rs2 from instruction
assign rd  = if_id_instr[11:7];  // Extract register destination from instruction


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
// ID/EX Pipeline Registers
///////////////////////////////////////////
logic [31:0] id_ex_rd1, id_ex_rd2;
logic [31:0] id_ex_imm;
logic [4:0] id_ex_rd;
logic [6:0] id_ex_opcode;
logic [4:0] id_ex_rs1, id_ex_rs2;

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
    end 
    else 
    begin
        id_ex_rd1 <= rd1; // Pass register data to EX stage
        id_ex_rd2 <= rd2; // Pass register data to EX stage
        id_ex_imm <= { {20{if_id_instr[31]}}, if_id_instr[31:20] }; // Sign-extend immediate for I-type instructions
        id_ex_rd <= rd; // Pass destination register index to EX stage
        id_ex_opcode <= if_id_instr[6:0]; // Pass opcode to EX stage
        id_ex_rs1 <= rs1; // Pass source register index to EX stage
        id_ex_rs2 <= rs2; // Pass source register index to EX stage
    end
end

///////////////////////////////////////////
// Fowarding Unit (for data hazard resolution)
///////////////////////////////////////////

logic [31:0] forward_a, forward_b;
logic [1:0] forward_a_sel, forward_b_sel;

always_comb begin
    // Default
    forward_a_sel = 2'b00;
    forward_b_sel = 2'b00;

    /////////////////////////////////
    // Forward A (rs1)
    /////////////////////////////////
    if (ex_mem_rd != 5'd0 &&
        ex_mem_rd == id_ex_rs1 &&
        (ex_mem_opcode == 7'b0010011 || ex_mem_opcode == 7'b0110011)) begin

        forward_a_sel = 2'b10;

    end else if (mem_wb_rd != 5'd0 &&
                 mem_wb_rd == id_ex_rs1 &&
                 (mem_wb_opcode == 7'b0010011 || mem_wb_opcode == 7'b0110011)) begin

        forward_a_sel = 2'b01;
    end

    /////////////////////////////////
    // Forward B (rs2)
    /////////////////////////////////
    if (ex_mem_rd != 5'd0 &&
        ex_mem_rd == id_ex_rs2 &&
        (ex_mem_opcode == 7'b0010011 || ex_mem_opcode == 7'b0110011)) begin

        forward_b_sel = 2'b10;

    end else if (mem_wb_rd != 5'd0 &&
                 mem_wb_rd == id_ex_rs2 &&
                 (mem_wb_opcode == 7'b0010011 || mem_wb_opcode == 7'b0110011)) begin

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

logic ex_is_imm; // Indicates if the instruction uses an immediate operand
assign ex_is_imm = (id_ex_opcode == 7'b0010011); // ADDI opcode

// ALU
alu alu_inst(
    .a(forward_a),
    .b(ex_is_imm ? id_ex_imm : forward_b),
    .result(alu_result)
);
///////////////////////////////////////////
// EX/MEM Pipeline Registers
///////////////////////////////////////////

logic [31:0] ex_mem_result;
logic [4:0] ex_mem_rd;
logic [6:0] ex_mem_opcode;

always_ff @( posedge clk )
begin
    if(reset) 
    begin
        ex_mem_result <= 0;
        ex_mem_rd <= 0;
        ex_mem_opcode <= 0;
    end else 
    begin
        ex_mem_result <= alu_result; // Pass ALU result to MEM stage
        ex_mem_rd <= id_ex_rd; // Pass destination
        ex_mem_opcode <= id_ex_opcode; // Pass opcode to MEM stage
    end
end


///////////////////////////////////////////
// MEM Stage (Memory Access)
///////////////////////////////////////////

///////////////////////////////////////////
// MEM/WB Pipeline Registers
///////////////////////////////////////////

logic [31:0] mem_wb_result;
logic [4:0] mem_wb_rd;
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
        mem_wb_result <= ex_mem_result; // Pass result to WB stage
        mem_wb_rd <= ex_mem_rd; // Pass destination register index to WB stage
        mem_wb_opcode <= ex_mem_opcode; // Pass opcode to WB stage
    end
end

///////////////////////////////////////////
// Writeback Stage (WB)
///////////////////////////////////////////

// Enable writeback for ADD/ADDI instructions
assign wb_we = (mem_wb_opcode == 7'b0010011) || (mem_wb_opcode == 7'b0110011); // Always write back for this simple example

// Destination Register
assign wb_rd = mem_wb_rd; // Write back to the destination register

// Data to write back
assign wb_data = mem_wb_result; // Write back MEM stage result

endmodule
