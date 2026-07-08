// tb_init_tasks.svh

// open output files
task automatic open_output_files;
begin
    trace_file       = $fopen("trace.log", "w");
    instruction_file = $fopen("instruction_trace.log", "w");
    summary_file     = $fopen("summary.log", "w");

    if (trace_file == 0)
        $fatal(1, "Could not open trace.log");

    if (summary_file == 0)
        $fatal(1, "Could not open summary.log");

    if (instruction_file == 0)
        $fatal(1, "Could not open instruction_trace.log");
end
endtask

// close output files
task automatic close_output_files;
begin
    $fclose(trace_file);
    $fclose(summary_file);
    $fclose(instruction_file);
end
endtask

task automatic initialize_counters;

begin
    cycle_count   = 0;
    retired_count = 0;
    stall_count   = 0;
    control_count = 0;

    load_use_stall_count = 0;
    branch_taken_count   = 0;
    flush_count          = 0;
    jal_taken_count      = 0;
    jalr_taken_count     = 0;

    rtype_count        = 0;
    itype_count        = 0;
    load_count         = 0;
    store_count        = 0;
    branch_instr_count = 0;
    jal_instr_count    = 0;
    jalr_instr_count   = 0;
    lui_instr_count     = 0;

    ex_mem_forward_a_count = 0;
    ex_mem_forward_b_count = 0;
    mem_wb_forward_a_count = 0;
    mem_wb_forward_b_count = 0;
    total_forward_count    = 0;
end
endtask
