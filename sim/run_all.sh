#!/usr/bin/env bash
set -euo pipefail

shopt -s nullglob

# ============================================================
# run_all.sh
#
# Runs the full CPU regression suite and collects every test's
# output into combined log files.
#
# Usage:
#   ./run_all.sh              run everything
#   ./run_all.sh functional   run only the functional tests
#   ./run_all.sh trap         run only the trap tests
#   ./run_all.sh compliance   run only the riscv-tests compliance tests
#
# Test manifest format:
#   "<program>|<expected_trap_cause>"
#
# An empty cause field means the program is expected to run to
# completion and report PASS through its checker. A non-empty
# cause means the program is expected to raise that trap; the
# testbench recognises the "trap_" filename prefix and enables
# expected-trap mode automatically.
#
# Programs ending in .hex are loaded directly rather than
# assembled. Illegal-instruction tests use that path because the
# assembler refuses to emit illegal encodings by design.
#
# Programs ending in .S (uppercase, matching upstream's own
# convention) are official riscv-tests sources, compiled through
# the real RISC-V GNU toolchain rather than tools/asm_to_hex.py --
# see tools/riscv-tests-mini/build_and_convert.sh.
#
# Combined outputs:
#   regression.log, summary_all.log, trace_all.log,
#   instruction_trace_all.log, program_all.hex
# ============================================================

# ---------------------------------------------------------------- manifest

FUNCTIONAL_TESTS=(
    "../programs/full_instruction_test.s|"
    "../programs/all_hazards_test.s|"
    "../programs/rv32i_arith_test.s|"
    "../programs/mem_subword_test.s|"
)

TRAP_TESTS=(
    # Memory access faults
    "../programs/trap_load_misaligned.s|4"
    "../programs/trap_store_misaligned.s|6"
    "../programs/trap_load_fault.s|5"

    # Environment instructions
    "../programs/trap_ebreak.s|3"
    "../programs/trap_ecall.s|11"

    # Illegal encodings (raw hex: the assembler cannot emit these)
    "../programs/trap_illegal_rtype.hex|2"
    "../programs/trap_illegal_branch.hex|2"
    "../programs/trap_illegal_load.hex|2"
    "../programs/trap_illegal_opcode.hex|2"
)

# Official RISC-V Foundation riscv-tests (isa/rv32ui/*.S), vendored unmodified
# into programs/riscv-tests/ -- byte-identical to upstream, verifiable with a
# plain diff against a fresh clone of riscv-software-src/riscv-tests.
#
# run.sh routes .S files through the real RISC-V GNU toolchain (see
# tools/riscv-tests-mini/build_and_convert.sh), compiled against env-mini, a
# CSR-free stand-in for the official harness (this core has no CSRs). Each
# test's own concluding ECALL is the pass/fail signal (a0 = 0 for pass),
# recognised via the "riscvtest_" test-name prefix that run.sh applies for
# any .S input.
#
# The load/store family (lb, lh, lw, sb, sh, sw, ld_st, st_ld, ma_data) and
# fence_i are not yet included: they require pre-populated data memory or an
# unimplemented instruction (FENCE.I) respectively. See
# RISCV_TESTS_STATUS.md for details and how to extend this list.
COMPLIANCE_TESTS=(
    "../programs/riscv-tests/rv32ui/add.S|"
    "../programs/riscv-tests/rv32ui/addi.S|"
    "../programs/riscv-tests/rv32ui/and.S|"
    "../programs/riscv-tests/rv32ui/andi.S|"
    "../programs/riscv-tests/rv32ui/auipc.S|"
    "../programs/riscv-tests/rv32ui/beq.S|"
    "../programs/riscv-tests/rv32ui/bge.S|"
    "../programs/riscv-tests/rv32ui/bgeu.S|"
    "../programs/riscv-tests/rv32ui/blt.S|"
    "../programs/riscv-tests/rv32ui/bltu.S|"
    "../programs/riscv-tests/rv32ui/bne.S|"
    "../programs/riscv-tests/rv32ui/jal.S|"
    "../programs/riscv-tests/rv32ui/jalr.S|"
    "../programs/riscv-tests/rv32ui/lui.S|"
    "../programs/riscv-tests/rv32ui/or.S|"
    "../programs/riscv-tests/rv32ui/ori.S|"
    "../programs/riscv-tests/rv32ui/simple.S|"
    "../programs/riscv-tests/rv32ui/sll.S|"
    "../programs/riscv-tests/rv32ui/slli.S|"
    "../programs/riscv-tests/rv32ui/slt.S|"
    "../programs/riscv-tests/rv32ui/slti.S|"
    "../programs/riscv-tests/rv32ui/sltiu.S|"
    "../programs/riscv-tests/rv32ui/sltu.S|"
    "../programs/riscv-tests/rv32ui/sra.S|"
    "../programs/riscv-tests/rv32ui/srai.S|"
    "../programs/riscv-tests/rv32ui/srl.S|"
    "../programs/riscv-tests/rv32ui/srli.S|"
    "../programs/riscv-tests/rv32ui/sub.S|"
    "../programs/riscv-tests/rv32ui/xor.S|"
    "../programs/riscv-tests/rv32ui/xori.S|"
)

MODE="${1:-all}"

case "$MODE" in
    functional) TESTS=("${FUNCTIONAL_TESTS[@]}") ;;
    trap)       TESTS=("${TRAP_TESTS[@]}") ;;
    compliance) TESTS=("${COMPLIANCE_TESTS[@]}") ;;
    all)        TESTS=("${FUNCTIONAL_TESTS[@]}" "${TRAP_TESTS[@]}" "${COMPLIANCE_TESTS[@]}") ;;
    *)
        echo "Usage: ./run_all.sh [all|functional|trap|compliance]"
        exit 1
        ;;
esac

if [ ${#TESTS[@]} -eq 0 ]; then
    echo "FAIL: No tests selected"
    exit 1
fi

# ---------------------------------------------------------------- setup

REGRESSION_LOG="regression.log"
COMBINED_SUMMARY="summary_all.log"
COMBINED_TRACE="trace_all.log"
COMBINED_INSTRUCTION_TRACE="instruction_trace_all.log"
COMBINED_PROGRAM_HEX="program_all.hex"
COMBINED_SIM_OUTPUT="sim_output_all.txt"

PASS_COUNT=0
FAIL_COUNT=0
TOTAL_COUNT=${#TESTS[@]}
FAILED_TESTS=()

# Individual output files created by run.sh.
RUN_OUTPUTS=(
    "summary.log"
    "trace.log"
    "instruction_trace.log"
    "program.hex"
    "sim_output.txt"
)

# Start fresh regression outputs.
rm -f "$REGRESSION_LOG" "$COMBINED_SUMMARY" "$COMBINED_TRACE" \
      "$COMBINED_INSTRUCTION_TRACE" "$COMBINED_PROGRAM_HEX" \
      "$COMBINED_SIM_OUTPUT"


# Remove stale individual outputs before starting.
for OUT in "${RUN_OUTPUTS[@]}"; do
    rm -f "$OUT"
done

log() {
    echo "$@" | tee -a "$REGRESSION_LOG"
}

append_section_header() {
    {
        echo ""
        echo "============================================================"
        echo "TEST: $2"
        echo "PROGRAM: $3"
        echo "============================================================"
        echo ""
    } >> "$1"
}

append_required_output() {
    local SRC="$1" DEST="$2" NAME="$3" PROG="$4"
    if [ ! -f "$SRC" ]; then
        log "WARN: $SRC was not created for $NAME"
        return 0
    fi
    append_section_header "$DEST" "$NAME" "$PROG"
    cat "$SRC" >> "$DEST"
    echo "" >> "$DEST"
}

append_optional_output() {
    local SRC="$1" DEST="$2" NAME="$3" PROG="$4"
    if [ -f "$SRC" ]; then
        append_section_header "$DEST" "$NAME" "$PROG"
        cat "$SRC" >> "$DEST"
        echo "" >> "$DEST"
    fi
}

# ---------------------------------------------------------------- banner

log "============================================================"
log "CPU Regression Test Suite"
log "============================================================"
log "Mode        : $MODE"
log "Total tests : $TOTAL_COUNT"
log ""

# Basic run.sh sanity check.
if [ ! -f "./run.sh" ]; then
    log "FAIL: ./run.sh not found. Run this script from the sim/ directory."
    exit 1
fi

if [ ! -x "./run.sh" ]; then
    log "INFO: making ./run.sh executable"
    chmod +x ./run.sh
fi

# ---------------------------------------------------------------- run loop

for ENTRY in "${TESTS[@]}"; do
    TEST="${ENTRY%%|*}"
    EXPECT_CAUSE="${ENTRY##*|}"

    # Strip any extension for the display name
    TEST_NAME=$(basename "$TEST")
    TEST_NAME="${TEST_NAME%.*}"

    log "------------------------------------------------------------"
    log "Running test: $TEST_NAME"
    log "Program     : $TEST"
    if [ -n "$EXPECT_CAUSE" ]; then
        log "Expecting   : trap with cause $EXPECT_CAUSE"
    fi
    log "------------------------------------------------------------"

    if [ ! -f "$TEST" ]; then
        log "FAIL: Test program not found: $TEST"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_TESTS+=("$TEST_NAME (missing)")
        continue
    fi

    for OUT in "${RUN_OUTPUTS[@]}"; do
        rm -f "$OUT"
    done

    # A failing simulation must not abort the whole regression; record it
    # and keep going so one bad test still yields a full report.
    RUN_OK=1
    if [ -n "$EXPECT_CAUSE" ]; then
        ./run.sh "$TEST" "$EXPECT_CAUSE" 2>&1 | tee -a "$REGRESSION_LOG" || RUN_OK=0
    else
        ./run.sh "$TEST" 2>&1 | tee -a "$REGRESSION_LOG" || RUN_OK=0
    fi

    # Verify the checker explicitly reported PASS. This keeps NOT CHECKED
    # tests from silently counting as passes.
    if [ "$RUN_OK" -eq 1 ] && [ -f "summary.log" ] &&
       grep -Eq "Result[[:space:]]*:[[:space:]]*PASS" summary.log; then
        log "PASS: $TEST_NAME"
        PASS_COUNT=$((PASS_COUNT + 1))
    else
        log "FAIL: $TEST_NAME did not report PASS"
        FAIL_COUNT=$((FAIL_COUNT + 1))
        FAILED_TESTS+=("$TEST_NAME")
    fi

    append_required_output "summary.log"           "$COMBINED_SUMMARY"           "$TEST_NAME" "$TEST"
    append_required_output "trace.log"             "$COMBINED_TRACE"             "$TEST_NAME" "$TEST"
    append_required_output "instruction_trace.log" "$COMBINED_INSTRUCTION_TRACE" "$TEST_NAME" "$TEST"
    append_required_output "program.hex"           "$COMBINED_PROGRAM_HEX"       "$TEST_NAME" "$TEST"
    append_optional_output "sim_output.txt"        "$COMBINED_SIM_OUTPUT"        "$TEST_NAME" "$TEST"

    for OUT in "${RUN_OUTPUTS[@]}"; do
        rm -f "$OUT"
    done

    log ""
done

# ---------------------------------------------------------------- report

log "============================================================"
if [ "$FAIL_COUNT" -eq 0 ]; then
    log "ALL TESTS PASSED"
else
    log "REGRESSION FAILED"
fi
log "Passed $PASS_COUNT / $TOTAL_COUNT tests"

if [ "$FAIL_COUNT" -gt 0 ]; then
    log ""
    log "Failing tests:"
    for T in "${FAILED_TESTS[@]}"; do
        log "  - $T"
    done
fi

log "============================================================"
log "Combined outputs:"
log "  $COMBINED_SUMMARY"
log "  $COMBINED_TRACE"
log "  $COMBINED_INSTRUCTION_TRACE"
log "  $COMBINED_PROGRAM_HEX"
if [ -f "$COMBINED_SIM_OUTPUT" ]; then
    log "  $COMBINED_SIM_OUTPUT"
fi
log "  $REGRESSION_LOG"
log "============================================================"

exit "$FAIL_COUNT"
