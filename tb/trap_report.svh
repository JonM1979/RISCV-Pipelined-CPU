
// Readable trap cause
function automatic string trap_cause_name(input logic [3:0] cause);
    case (cause)
        CAUSE_ILLEGAL_INSTR:  return "ILLEGAL INSTRUCTION";
        CAUSE_BREAKPOINT:     return "EBREAK";
        CAUSE_ECALL:          return "ECALL";
        CAUSE_LOAD_MISALIGN:  return "LOAD ADDRESS MISALIGNED";
        CAUSE_STORE_MISALIGN: return "STORE ADDRESS MISALIGNED";
        CAUSE_LOAD_FAULT:     return "LOAD ACCESS FAULT";
        CAUSE_STORE_FAULT:    return "STORE ACCESS FAULT";
        default:              return "UNKNOWN";
    endcase
endfunction

// Called when the core reports a precise trap at the commit point.
task automatic report_trap;
begin
    $display("\n==================== TRAP ====================");
    $display("Cause      : %0d (%s)", trap_cause, trap_cause_name(trap_cause));
    $display("Faulting PC: 0x%08h", trap_pc);
    $display("Instruction: %s", disasm(uut.mem_wb_instr));
    $display("----------------------------------------------");
    $display("Architectural state at trap (non-zero registers):");
    for (int i = 1; i < 32; i++) begin
        if (uut.rf.regs[i] !== 32'd0)
            $display("  x%0d = 0x%08h (%0d)", i, uut.rf.regs[i], uut.rf.regs[i]);
    end
    $display("==============================================\n");

    $fdisplay(summary_file, "\n[TRAP]");
    $fdisplay(summary_file, "Cause                    : %0d (%s)",
              trap_cause, trap_cause_name(trap_cause));
    $fdisplay(summary_file, "Faulting PC              : 0x%08h", trap_pc);

    final_summary();

    if (expect_trap) begin
        if (expected_cause >= 0 && trap_cause != expected_cause[3:0]) begin
            $fdisplay(summary_file, "\n[TEST RESULT]");
            $fdisplay(summary_file, "Result                   : FAIL (wrong cause)");
            close_output_files();
            $fatal(1, "Wrong trap cause: expected %0d (%s), got %0d (%s)",
                   expected_cause, trap_cause_name(expected_cause[3:0]),
                   trap_cause,     trap_cause_name(trap_cause));
        end
        $display("PASS: expected trap raised (cause %0d: %s)",
                 trap_cause, trap_cause_name(trap_cause));

        // Reported in the same form as every other test so the regression
        // runner can detect it without special-casing trap tests.
        $fdisplay(summary_file, "\n[TEST RESULT]");
        $fdisplay(summary_file, "Test Name                : %s", test_name);
        $fdisplay(summary_file, "Result                   : PASS");
        close_output_files();
        $finish;
    end
    else begin
        $fdisplay(summary_file, "\n[TEST RESULT]");
        $fdisplay(summary_file, "Test Name                : %s", test_name);
        $fdisplay(summary_file, "Result                   : FAIL (unexpected trap)");
        close_output_files();
        $fatal(1, "Unexpected trap at PC 0x%08h (cause %0d: %s)",
               trap_pc, trap_cause, trap_cause_name(trap_cause));
    end
end
endtask
