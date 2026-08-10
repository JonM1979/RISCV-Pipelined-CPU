# RISC-V Pipelined CPU

[![CPU Regression](https://github.com/JonM1979/RISCV-Pipelined-CPU/actions/workflows/ci.yml/badge.svg)](https://github.com/JonM1979/RISCV-Pipelined-CPU/actions/workflows/ci.yml)

A 5-stage pipelined RV32I RISC-V CPU written in SystemVerilog, implementing
the complete RV32I base integer instruction set with data forwarding, hazard
detection, dynamic branch prediction, precise exceptions, and sub-word memory
access. The project includes a custom two-pass assembler, a Verilator-based
simulation and regression flow, a SystemVerilog Assertion suite bound to the
design, 40 passing tests from the official RISC-V Foundation compliance
suite, and continuous integration.

## Processor Diagram 
<img width="1906" height="1184" alt="RISCV-CPU-Diagram" src="https://github.com/user-attachments/assets/545d18ab-e303-470c-b414-f9fd501ce02c" />
The processor follows a Harvard-style architecture with forwarding. I focused on showing the main signals of the processor and tried to follow a standard pipelined processor diagram to make the diagram easier to read. I left out signals responsible for the trap/exception logic, as the diagram was becoming too full to include them as well. I distinguished control signals by coloring the lines blue and leaving data lines in black. The one detail that I would like to highlight is how choosing the next PC works. The branch predictor only guesses which direction it will take, but when the predictor is wrong and control_taken is correct, then that PC must win; this is represented by having the dual MUX cascade in the IF stage. For further design details, please see the Design Notes below. 

## Features

- **5-stage pipeline** — IF, ID, EX, MEM, WB
- **Full RV32I base integer ISA** (40 instructions) — every legal encoding
  executes correctly; anything else raises a precise illegal-instruction trap
  rather than being silently mis-executed
- **Data hazard handling** — EX/MEM and MEM/WB forwarding, load-use stall
  detection on either source operand, and a same-cycle writeback-to-decode
  register file bypass for the case where a register is written and read on
  the same clock edge
- **Dynamic branch prediction** — a 256-entry, 2-bit saturating-counter
  branch history table predicts direction in IF. Branch and `JAL` targets are
  computed combinationally from the PC-relative immediate already in the
  instruction word, so no branch target buffer is needed; only direction is
  predicted. `JALR`'s target depends on a register value not known until EX,
  so it is intentionally left unpredicted. A correctly predicted taken branch
  costs zero cycles; a misprediction flushes exactly the wrong-path
  instructions and nothing else
- **Precise exceptions** — illegal instructions, misaligned loads/stores,
  out-of-range loads/stores, `ECALL`, and `EBREAK` are detected in the stage
  where the fault becomes visible, carried alongside the faulting instruction,
  and trapped only at commit (writeback). Every instruction older than the
  fault has already completed; nothing younger takes effect
- **Sub-word memory access** — `LB`/`LH`/`LW`/`LBU`/`LHU` with correct sign or
  zero extension, and `SB`/`SH`/`SW` with per-lane byte enables, alongside
  full-word access
- **SystemVerilog Assertions** — 38 properties and 11 cover points, `bind`-ed
  into the design so no verification logic reaches synthesis, checking
  pipeline invariants (x0 protection, PC/redirect alignment, trap precision,
  stall/redirect mutual exclusivity, forwarding priority, mux/select
  agreement, ALU and memory-access encoding legality) on every cycle of every
  test
- **Custom two-pass assembler** — standard RISC-V syntax, ABI register names,
  and common pseudo-instructions (`li`, `mv`, `not`, `neg`, `seqz`, `snez`,
  `j`, `jr`, `ret`, `beqz`, `bnez`)
- **Official compliance testing** — 40 of 42 applicable tests from
  `riscv-software-src/riscv-tests` (`rv32ui`) pass, vendored byte-identical to
  upstream and compiled through the real RISC-V GNU toolchain
- **Continuous integration** — every push and pull request is linted (both an
  RTL-only synthesis view and a full-build view, zero warnings required) and
  run through the complete regression suite

## Supported Instructions

All 40 instructions of the RV32I base integer instruction set.

| Type | Instructions |
|---|---|
| R-type (register-register) | `ADD` `SUB` `SLL` `SLT` `SLTU` `XOR` `SRL` `SRA` `OR` `AND` |
| I-type (register-immediate) | `ADDI` `SLTI` `SLTIU` `XORI` `ORI` `ANDI` `SLLI` `SRLI` `SRAI` |
| Loads | `LB` `LH` `LW` `LBU` `LHU` |
| Stores | `SB` `SH` `SW` |
| Branches | `BEQ` `BNE` `BLT` `BGE` `BLTU` `BGEU` |
| Jumps | `JAL` `JALR` |
| Upper immediate | `LUI` `AUIPC` |
| Memory ordering | `FENCE` (executes as a no-op; this core has no memory reordering to fence against) |
| Environment | `ECALL` `EBREAK` |

Any encoding that does not correspond to a legal instruction above raises a
precise `ILLEGAL INSTRUCTION` trap.

## Exceptions

| Cause | Trigger |
|---|---|
| Illegal Instruction | Encoding is not valid RV32I |
| Breakpoint | `EBREAK` executed |
| Environment Call | `ECALL` executed |
| Load/Store Address Misaligned | Access width not aligned to its size |
| Load/Store Access Fault | Address outside the memory window |

Trap cause values match the RISC-V privileged specification's machine cause
codes.

## Repository Structure

```
rtl/                    Processor RTL and the SVA assertion module
tb/                     Verilator testbench, tracing, and checkers
tools/                  asm_to_hex.py, the two-pass RV32I assembler
tools/riscv-tests-mini/ Harness for building official riscv-tests sources
programs/               Test programs (.s, .hex, and official riscv-tests .S)
sim/                    Build/run scripts
.github/                CI workflow
```

## Getting Started

Three ways to get a working environment, all ending in the same place:
Verilator and the RISC-V GNU toolchain installed and ready for `sim/run_all.sh`.

### Option 1 — GitHub Codespaces (zero setup)

Click **Code → Codespaces → Create codespace on main**. The configuration in
`.devcontainer/` installs everything automatically and runs a smoke test
before handing you a terminal. Nothing to install by hand.

### Option 2 — Local machine with Docker (identical automatic setup)

If you have [Docker Desktop](https://www.docker.com/products/docker-desktop/)
running and VS Code's
[Dev Containers extension](https://marketplace.visualstudio.com/items?itemName=ms-vscode-remote.remote-containers)
installed, open this repo folder in VS Code and choose **"Reopen in
Container"** when prompted. This runs the exact same `.devcontainer/setup.sh`
locally that Codespaces runs in the cloud — identical result, on your own
hardware, on any OS Docker Desktop supports.

### Option 3 — Local machine, no containers

**Linux (Ubuntu/Debian).** Verified directly: both Verilator and the RISC-V
GNU toolchain live in Ubuntu's `universe` repository component, which some
minimal installs don't enable by default.

```bash
sudo add-apt-repository universe
sudo apt-get update
sudo apt-get install -y verilator gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf
```

**macOS.** Verilator installs cleanly via Homebrew:

```bash
brew install verilator
```

For the RISC-V toolchain, Homebrew offers a core formula (`riscv64-elf-gcc`)
and a community tap
([`riscv-software-src/riscv`](https://github.com/riscv-software-src/homebrew-riscv),
`brew install riscv-tools`) that more closely matches the
`riscv64-unknown-elf-*` binary names this project's scripts call directly.
This path is not verified end-to-end here — if the installed binary names
don't match, symlinking them (e.g. `riscv64-elf-gcc` →
`riscv64-unknown-elf-gcc`) should bridge the gap. Option 2 (Docker) sidesteps
this naming question entirely and is the more reliable path on macOS.

**Windows.** Native Windows isn't a practical target for Verilator. Install
[WSL2](https://learn.microsoft.com/en-us/windows/wsl/install) with an Ubuntu
distribution, then follow the Linux instructions above from inside WSL.

After any of these, verify both tools are on the `PATH`:

```bash
verilator --version
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 --version
```

## How to Run

All commands are run from the `sim/` directory.

**Single test:**
```bash
cd sim
./run.sh ../programs/full_instruction_test.s
```

**A test that is expected to trap**, passing the expected cause number:
```bash
./run.sh ../programs/trap_ebreak.s 3
```

**A pre-assembled illegal-encoding image** (the assembler will not emit an
illegal encoding by design, so these are provided as raw hex):
```bash
./run.sh ../programs/trap_illegal_rtype.hex 2
```

**An official riscv-tests source**, compiled through the real RISC-V GNU
toolchain rather than the project's own assembler:
```bash
./run.sh ../programs/riscv-tests/rv32ui/add.S
```

**Full regression suite:**
```bash
./run_all.sh              # everything (53 tests)
./run_all.sh functional   # this project's own functional tests
./run_all.sh trap         # this project's own trap tests
./run_all.sh compliance   # official riscv-tests
```

Each run produces `trace.log`, `instruction_trace.log`, and `summary.log`
(CPI, IPC, stall/redirect counts, branch prediction accuracy and MPKI,
instruction mix, and forwarding activity). `run_all.sh` additionally produces
combined `*_all.log` files and `regression.log` across the whole suite.

`run.sh` only rebuilds the Verilator simulation when the RTL or testbench
source has actually changed since the last build, rather than on every
invocation — the compiled simulator has no test program baked into it; it
reads `program.hex`/`data.hex` and its `+TEST=`/`+EXPECT_CAUSE=` plusargs at
runtime, so a different test never requires recompiling the same hardware
model. Set `FORCE_REBUILD=1` to force a rebuild regardless.

## Verification

### This project's own tests (13)

| Test | Type | Checks |
|---|---|---|
| `full_instruction_test.s` | Self-checking | Every supported instruction executes correctly |
| `all_hazards_test.s` | Self-checking | Forwarding (EX/MEM, MEM/WB), load-use stalls, store-data forwarding, branch/JAL/JALR flushing, x0 write protection |
| `rv32i_arith_test.s` | Self-checking | `SLTU`/`SLTIU`, `SRA`/`SRAI`, `BLTU`/`BGEU`, `AUIPC`, `SUB`, unsigned arithmetic wraparound |
| `mem_subword_test.s` | Self-checking | Byte/halfword loads and stores, sign vs. zero extension, byte-lane isolation |
| `trap_load_misaligned.s` | Expected trap (cause 4) | Misaligned load detection |
| `trap_store_misaligned.s` | Expected trap (cause 6) | Misaligned store detection |
| `trap_load_fault.s` | Expected trap (cause 5) | Out-of-range load detection |
| `trap_ebreak.s` | Expected trap (cause 3) | `EBREAK` |
| `trap_ecall.s` | Expected trap (cause 11) | `ECALL` |
| `trap_illegal_rtype.hex` | Expected trap (cause 2) | Reserved R-type `funct7` |
| `trap_illegal_branch.hex` | Expected trap (cause 2) | Unassigned branch `funct3` |
| `trap_illegal_load.hex` | Expected trap (cause 2) | Unassigned load `funct3` |
| `trap_illegal_opcode.hex` | Expected trap (cause 2) | Unrecognized opcode |

### Official RISC-V compliance tests (40)

Vendored, byte-identical to `riscv-software-src/riscv-tests`, under
`programs/riscv-tests/`. All arithmetic, logic, shift, comparison, branch,
jump, upper-immediate, and load/store instructions:

`add` `addi` `and` `andi` `auipc` `beq` `bge` `bgeu` `blt` `bltu` `bne` `jal`
`jalr` `lui` `or` `ori` `simple` `sll` `slli` `slt` `slti` `sltiu` `sltu`
`sra` `srai` `srl` `srli` `sub` `xor` `xori` `lb` `lbu` `lh` `lhu` `lw` `sb`
`sh` `sw` `ld_st` `st_ld`

The official sources use C-preprocessor `#include`s and GNU assembler macros
that the project's assembler cannot parse, so they are compiled through
the real RISC-V GNU toolchain against `env-mini` — a CSR-free stand-in for
the official test harness (`env/p/riscv_test.h`), since this processor has no CSR
support. Each test's own concluding `ECALL` is the pass/fail signal (`a0 = 0`
for pass), read directly from the register file at the moment of the trap —
no software trap-vector required, because this processor's own hardware
trap mechanism already reaches that `ECALL` precisely.

Two tests are excluded, for two different reasons:

- **`ma_data`** — excluded permanently, by design. It tests that a
  *misaligned* load returns the correct data value, i.e. it targets a processor
  that either supports misaligned access in hardware or traps and resumes via
  a handler. This processor does neither: it raises a precise misalignment trap
  and halts, a deliberate architectural choice (see Known Limitations). This
  test cannot pass regardless of implementation effort.
- **`fence_i`** — excluded as out of scope. It requires `FENCE.I`, a distinct
  instruction from plain `FENCE` that this processor does not implement.

All 53 tests pass with SVA assertions enabled (`--assert`), meaning the
pipeline invariants held on every cycle each test ran, not only that the
final architectural state was correct.

## Design Notes

**Why traps are taken at writeback, not at detection.** The pipeline has up
to five instructions in flight. A trap taken immediately upon detection would
leave older instructions mid-flight and could let younger, wrong-path
instructions take effect. Writeback is the point where instructions commit in
order, so an exception flag carried alongside its instruction and only acted
on at writeback is automatically precise. Everything older has already
committed, and register writes and memory stores are suppressed the moment an
exception is known, so nothing younger takes effect either.

**Why no branch target buffer.** Branch and `JAL` targets are PC-relative and
fully determined by the instruction word plus the current PC, so the target
can be computed combinationally in IF without a target cache. Only the branch
direction benefits from prediction. `JALR`'s target depends on a register
value not known until EX, so it is intentionally left unpredicted and always
resolves there.

**Why forwarding excludes loads even though they are architectural writers.**
A load will write a register, but its data does not exist until the memory
access completes in MEM — forwarding from EX/MEM for a load would forward its
address, not its data. The load-use stall already prevents a dependent
instruction from reaching EX while the load is in EX/MEM, but the forwarding
enable is deliberately narrower than the general write-enable as well, so a
bug in the stall logic cannot silently become a bug in forwarded data.

**Why the official compliance tests need a custom harness rather than the
official one.** The official `env/p/riscv_test.h` drives pass/fail through a
trap handler that reads the `mcause` CSR and writes to a memory-mapped
`tohost` address — both of which require CSR support this processor does not
implement. The test *bodies* themselves use no CSR instructions at all, so
`env-mini` replaces only the harness, keeping the same `ecall`/`a0` pass/fail
convention the official tests already use.

## Known Limitations

- No CSRs (Control and Status Registers); traps halt the core rather than
  vectoring to a handler
- Single-issue, in-order; no superscalar or out-of-order execution
- No caches; instruction and data memories are single-cycle
- `ma_data` and `fence_i` excluded from the official compliance suite, for
  the architectural and scope reasons described above
