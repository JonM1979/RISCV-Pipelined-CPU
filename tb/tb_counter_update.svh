// tb_counter_update.svh

// Task to update performance counters based on events in the CPU
task automatic update_counters;
begin

    // Basic cycle count
    cycle_count <= cycle_count + 1;

    // Retired instruction count and instruction mix
    if (retire_valid) begin
        retired_count <= retired_count + 1;

        case (uut.mem_wb_opcode)

            OPCODE_R_TYPE: begin
                rtype_count <= rtype_count + 1;
            end

            OPCODE_I_TYPE: begin
                itype_count <= itype_count + 1;
            end

            OPCODE_LOAD: begin
                load_count <= load_count + 1;
            end

            OPCODE_STORE: begin
                store_count <= store_count + 1;
            end

            OPCODE_BRANCH: begin
                branch_instr_count <= branch_instr_count + 1;
            end

            OPCODE_JAL: begin
                jal_instr_count <= jal_instr_count + 1;
            end

            default: begin
                // Do nothing
            end

        endcase
    end

    // Stall / hazard counters
    if (uut.stall) begin
        stall_count <= stall_count + 1;
        load_use_stall_count <= load_use_stall_count + 1;
    end

    // Control hazard counters
    if (uut.control_taken) begin
        control_count <= control_count + 1;
        flush_count <= flush_count + 1;
    end

    if (uut.branch_cond_taken) begin
        branch_taken_count <= branch_taken_count + 1;
    end

    if (uut.jal_taken) begin
        jump_taken_count <= jump_taken_count + 1;
    end

    // Forwarding counters
    if (ex_mem_forward_a_event) begin
        ex_mem_forward_a_count <= ex_mem_forward_a_count + 1;
    end

    if (ex_mem_forward_b_event) begin
        ex_mem_forward_b_count <= ex_mem_forward_b_count + 1;
    end

    if (mem_wb_forward_a_event) begin
        mem_wb_forward_a_count <= mem_wb_forward_a_count + 1;
    end

    if (mem_wb_forward_b_event) begin
        mem_wb_forward_b_count <= mem_wb_forward_b_count + 1;
    end

    total_forward_count <= total_forward_count
                         + int'(ex_mem_forward_a_event)
                         + int'(ex_mem_forward_b_event)
                         + int'(mem_wb_forward_a_event)
                         + int'(mem_wb_forward_b_event);

    // Sanity checks
    if (^uut.if_id_instr === 1'bx) begin
        $fatal(1, "ERROR: IF/ID contains invalid X value at cycle %0d", cycle_count);
    end

    if (uut.rf.regs[0] !== 32'd0) begin
        $fatal(1, "ERROR: x0 changed! Expected x0=0, got %0d", uut.rf.regs[0]);
    end
end
endtask