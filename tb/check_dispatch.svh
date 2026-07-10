task automatic run_selected_check;
begin
    
    if (test_name == "full_instruction_test") begin
        check_full_instruction_test();
    end
    else if (test_name == "all_hazards_test") begin
        check_hazard_all_test();
    end
    else begin
        $display("WARNING: No automatic check registered for test '%s'", test_name);

        $fdisplay(summary_file, "\n[TEST RESULT]");
        $fdisplay(summary_file, "Test Name                : %s", test_name);
        $fdisplay(summary_file, "Result                   : NOT CHECKED");
    end
end
endtask
