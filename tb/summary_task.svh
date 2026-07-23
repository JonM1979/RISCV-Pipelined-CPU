// summary_tasks.svh

// Summary of CPU performance statistics measuring performance
function automatic real calc_cpi;
begin
    if (retired_count != 0)
        return cycle_count * 1.0 / retired_count;
    else
        return 0.0;
end
endfunction


function automatic real calc_ipc;
begin
    if (cycle_count != 0)
        return retired_count * 1.0 / cycle_count;
    else
        return 0.0;
end
endfunction


function automatic real calc_stall_rate;
begin
    if (cycle_count != 0)
        return stall_count * 100.0 / cycle_count;
    else
        return 0.0;
end
endfunction


function automatic real calc_control_redirect_rate;
begin
    if (retired_count != 0)
        return control_count * 100.0 / retired_count;
    else
        return 0.0;
end
endfunction


function automatic real calc_memory_instruction_rate;
begin
    if (retired_count != 0)
        return (load_count + store_count) * 100.0 / retired_count;
    else
        return 0.0;
end
endfunction


task automatic final_summary;
begin
    $fdisplay(summary_file, "\n==================== FINAL SUMMARY ====================");

    $fdisplay(summary_file, "\n[GENERAL PERFORMANCE]");
    $fdisplay(summary_file, "Cycles                   : %0d", cycle_count);
    $fdisplay(summary_file, "Retired Instructions     : %0d", retired_count);
    $fdisplay(summary_file, "CPI                      : %0f", calc_cpi());
    $fdisplay(summary_file, "IPC                      : %0f", calc_ipc());

    $fdisplay(summary_file, "\n[PIPELINE HAZARDS]");
    $fdisplay(summary_file, "Stall Cycles             : %0d", stall_count);
    $fdisplay(summary_file, "Stall Rate               : %0f%%", calc_stall_rate());

    $fdisplay(summary_file, "\n[CONTROL FLOW]");
    $fdisplay(summary_file, "Taken Branches           : %0d", branch_taken_count);
    $fdisplay(summary_file, "Taken JALs               : %0d", jal_taken_count);
    $fdisplay(summary_file, "Taken JALRs              : %0d", jalr_taken_count);
    $fdisplay(summary_file, "Taken Jumps Total        : %0d", jal_taken_count + jalr_taken_count);
    $fdisplay(summary_file, "Control Redirects/Flushes: %0d", control_count);
    $fdisplay(summary_file, "Control Redirect Rate    : %0f%%", calc_control_redirect_rate());

    $fdisplay(summary_file, "\n[INSTRUCTION MIX]");
    $fdisplay(summary_file, "R-Type Instructions      : %0d", rtype_count);
    $fdisplay(summary_file, "I-Type Instructions      : %0d", itype_count);
    $fdisplay(summary_file, "Load Instructions        : %0d", load_count);
    $fdisplay(summary_file, "Store Instructions       : %0d", store_count);
    $fdisplay(summary_file, "Branch Instructions      : %0d", branch_instr_count);
    $fdisplay(summary_file, "JAL Instructions         : %0d", jal_instr_count);
    $fdisplay(summary_file, "JALR Instructions        : %0d", jalr_instr_count);
    $fdisplay(summary_file, "LUI Instructions         : %0d", lui_instr_count);
    $fdisplay(summary_file, "Instruction Mix Total    : %0d",
            rtype_count +
            itype_count +
            load_count +
            store_count +
            branch_instr_count +
            jal_instr_count +
            jalr_instr_count +
            lui_instr_count);

    $fdisplay(summary_file, "\n[MEMORY ACTIVITY]");
    $fdisplay(summary_file, "Memory Instructions      : %0d", load_count + store_count);
    $fdisplay(summary_file, "Memory Instruction Rate  : %0f%%", calc_memory_instruction_rate());

    $fdisplay(summary_file, "\n[FORWARDING ACTIVITY]");
    $fdisplay(summary_file, "EX/MEM Forward A Count   : %0d", ex_mem_forward_a_count);
    $fdisplay(summary_file, "EX/MEM Forward B Count   : %0d", ex_mem_forward_b_count);
    $fdisplay(summary_file, "MEM/WB Forward A Count   : %0d", mem_wb_forward_a_count);
    $fdisplay(summary_file, "MEM/WB Forward B Count   : %0d", mem_wb_forward_b_count);
    $fdisplay(summary_file, "Total Forward Events     : %0d", total_forward_count);

    $fdisplay(summary_file, "\n=======================================================\n");

    $display("\nSUMMARY:");
    $display("Cycles=%0d | Retired=%0d | CPI=%0f | IPC=%0f",
             cycle_count, retired_count, calc_cpi(), calc_ipc());
    $display("Stalls=%0d | Branches Taken=%0d | JALs=%0d | JALRs=%0d | Forwards=%0d",
            stall_count,
            branch_taken_count,
            jal_taken_count,
            jalr_taken_count,
            total_forward_count);
end
endtask
