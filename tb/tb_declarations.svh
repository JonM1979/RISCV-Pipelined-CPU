
// -------------CLOCK / RESET / COUNTERS-----------------
logic clk;
logic reset;

// -------------DATA SIGNALS FOR CPU PERFORMANCE-----------------
// Test variables
string test_name;

// Basic performance counters
int unsigned cycle_count;
int unsigned retired_count;
int unsigned stall_count;
int unsigned control_count;

// Branch prediction statistics
int unsigned branch_count; // conditional branches resolved
int unsigned branch_mispredicts; // of those, predicted wrongly
int unsigned jalr_count_bp; // JALR is never predicted 

// Hazard/Control counters
int unsigned branch_taken_count;
int unsigned jal_taken_count;
int unsigned jalr_taken_count;

// Instruction mix counters
int unsigned rtype_count;
int unsigned itype_count;
int unsigned load_count;
int unsigned store_count;
int unsigned branch_instr_count;
int unsigned jal_instr_count;
int unsigned jalr_instr_count;
int unsigned lui_instr_count;
int unsigned auipc_instr_count;
int unsigned fence_instr_count;
int unsigned system_instr_count;

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

// Trap interface
logic        trap_valid;
logic [3:0]  trap_cause;
logic [31:0] trap_pc;

// Set by a test that intends to trap (e.g. an illegal-instruction test)
bit expect_trap = 1'b0;
int expected_cause = -1;
bit is_riscv_test = 1'b0;
int max_cycles;
