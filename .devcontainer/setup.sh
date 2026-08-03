#!/bin/bash
# .devcontainer/setup.sh
#
# Runs automatically once, when a Codespace (or any devcontainer-compatible
# environment) is created from this repository. Installs everything needed
# to build and run the CPU's simulation and compliance test suite, with no
# manual steps required afterward.
#
# Both Verilator and the RISC-V GNU toolchain live exclusively in Ubuntu's
# "universe" repository component, which many minimal base images do not
# enable by default -- that gap is exactly what caused this project to fail
# to build on a fresh test environment, and exactly what this script exists
# to close.
set -e

echo "============================================================"
echo "Setting up RISCV-Pipelined-CPU development environment"
echo "============================================================"

echo ""
echo "=== Enabling Ubuntu's universe repository ==="
# apt-get update can return non-zero if ANY configured repository fails to
# fetch, even one unrelated to the packages this script needs (a stale
# vendor repo entry, a transient network blip, etc). That must not abort
# setup -- what matters is whether the specific packages below install
# successfully, which is checked explicitly.
sudo apt-get update -qq || true

# add-apt-repository is not reliable on Ubuntu 24.04+'s newer deb822-format
# sources file (/etc/apt/sources.list.d/ubuntu.sources) -- it can report
# success while silently leaving the file unchanged. Edit the Components
# line directly instead, which works whether this image uses the modern
# deb822 format or the older single-file sources.list format.
UBUNTU_SOURCES="/etc/apt/sources.list.d/ubuntu.sources"
if [ -f "$UBUNTU_SOURCES" ]; then
    sudo sed -i 's/^Components: main$/Components: main universe restricted multiverse/' "$UBUNTU_SOURCES"
fi
if [ -f /etc/apt/sources.list ]; then
    sudo sed -i '/^deb /{/universe/! s/$/ universe/}' /etc/apt/sources.list
fi

sudo apt-get update -qq || true

# Confirm universe is actually reachable now, rather than trusting the edit
# above worked -- this is exactly the kind of thing that silently failed
# when this script used add-apt-repository instead.
if ! apt-cache policy verilator 2>/dev/null | grep -q "Candidate:"; then
    echo "WARNING: verilator has no candidate version even after enabling"
    echo "universe. The apt sources on this image may use a format this"
    echo "script does not recognize -- check /etc/apt/sources.list.d/ manually."
fi

echo ""
echo "=== Installing Verilator ==="
sudo apt-get install -y verilator

echo ""
echo "=== Installing the RISC-V GNU toolchain ==="
sudo apt-get install -y gcc-riscv64-unknown-elf binutils-riscv64-unknown-elf

echo ""
echo "=== Verifying tool installation ==="
verilator --version
riscv64-unknown-elf-gcc -march=rv32i -mabi=ilp32 --version | head -1
python3 --version

echo ""
echo "=== Making project scripts executable ==="
chmod +x sim/run.sh sim/run_all.sh tools/riscv-tests-mini/build_and_convert.sh

# From here on, do not abort the whole setup on a failure -- report the
# result instead. A smoke-test failure should be visible, not hide the
# Codespace from opening at all.
set +e

echo ""
echo "=== Smoke test: this project's own test suite ==="
( cd sim && ./run_all.sh functional )
FUNCTIONAL_RESULT=$?
( cd sim && ./run_all.sh trap )
TRAP_RESULT=$?

echo ""
echo "=== Smoke test: RISC-V GNU toolchain path (one official compliance test) ==="
( cd sim && ./run.sh ../programs/riscv-tests/rv32ui/add.S )
COMPLIANCE_RESULT=$?

echo ""
echo "============================================================"
if [ $FUNCTIONAL_RESULT -eq 0 ] && [ $TRAP_RESULT -eq 0 ] && [ $COMPLIANCE_RESULT -eq 0 ]; then
    echo "Setup complete -- all smoke tests passed."
    echo ""
    echo "Try the full regression suite:"
    echo "  cd sim && ./run_all.sh all"
    echo ""
    echo "Or just the official RISC-V compliance suite:"
    echo "  cd sim && ./run_all.sh compliance"
else
    echo "Setup finished installing tools, but at least one smoke test"
    echo "did not pass. Run the following manually from sim/ to see details:"
    echo "  ./run_all.sh all"
fi
echo "============================================================"
