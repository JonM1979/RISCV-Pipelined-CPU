// instruction_trace.svh

// prints assembly instruction moving through pipeline for debugging
task automatic instruction_trace;
begin

    $fdisplay(instruction_file,"==================INSTRUCTION TRACE====================");

    $fdisplay(instruction_file,"Cycle = %0d", cycle_count);

    $fdisplay(instruction_file,
                " IF : %s ",
                disasm(uut.instr)
    );

    $fdisplay(instruction_file,
                " ID : %s ",
                disasm(uut.if_id_instr)
    );

    $fdisplay(instruction_file,
                " EX : %s ",
                disasm(uut.id_ex_instr)
    );

    $fdisplay(instruction_file,
                " MEM: %s ",
                disasm(uut.ex_mem_instr)
        );

        $fdisplay(instruction_file,
                " WB : %s\n ",
                disasm(uut.mem_wb_instr)
        );
end
endtask
