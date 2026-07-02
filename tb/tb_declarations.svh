
// -------------CLOCK / RESET / COUNTERS-----------------
logic clk;
logic reset;

// -------------DATA SIGNALS FOR CPU PERFORMANCE-----------------

// Basic performance counters
int unsigned cycle_count;
int unsigned retired_count;
int unsigned stall_count;
int unsigned control_count;

// Hazard/Control counters
int unsigned load_use_stall_count;
int unsigned branch_taken_count;
int unsigned jump_taken_count;
int unsigned flush_count;

// Instruction mix counters
int unsigned rtype_count;
int unsigned itype_count;
int unsigned load_count;
int unsigned store_count;
int unsigned branch_instr_count;
int unsigned jal_instr_count;

// Forwarding counters
int unsigned ex_mem_forward_a_count;
int unsigned ex_mem_forward_b_count;
int unsigned mem_wb_forward_a_count;
int unsigned mem_wb_forward_b_count;
int unsigned total_forward_count;

// HALT INSTRUCTION BITS
localparam logic [31:0] HALT_INSTR = 32'h00500013; // ADDI x0, x0, 5

// OUTPUT FILE HANDLES
integer summary_file;
integer instruction_file;
integer trace_file;
