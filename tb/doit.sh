#!/bin/bash

# This script runs the testbench
# Usage: ./doit.sh <file1.cpp> <file2.cpp>

# Constants
SCRIPT_DIR=$(dirname "$(realpath "$0")")
TEST_FOLDER=$(realpath "$SCRIPT_DIR/tests")
RTL_FOLDER=$(realpath "$SCRIPT_DIR/../rtl") 
GREEN=$(tput setaf 2)
RED=$(tput setaf 1)
RESET=$(tput sgr0)

# Variables
passes=0
fails=0

# --- Define ALL RTL files once (Necessary for a complete build) ---
RTL_FILES=(${RTL_FOLDER}/*.sv)

# Handle terminal arguments
if [[ $# -eq 0 ]]; then
    # FIX: If no arguments provided, ONLY run the verify.cpp test
    # This avoids trying to compile f1_tb.cpp, gaussian_tb.cpp, etc.
    files=(${TEST_FOLDER}/verify.cpp)
else
    # If arguments provided, use them as input files (allows running specific tests)
    files=("$@") 
fi

#change directory to this directory
cd $SCRIPT_DIR

# Wipe previous test output
rm -rf test_out/*

# Iterate through files
for file in "${files[@]}"; do
    # Skip vbuddy.cpp as it's a helper, not a test entry point.
    if [[ "$(basename "$file")" == "vbuddy.cpp" ]]; then
        echo "Skipping helper file: $(basename "$file")"
        continue
    fi
    
    # Extract the base name (e.g., 'verify' from 'verify.cpp')
    name=$(basename "$file" _tb.cpp | cut -f1 -d\-) 

    # If verify.cpp, the test name for display is "top"
    if [ "$name" == "verify.cpp" ]; then
        name="top"
    fi

    echo "--- Compiling and Running Test: ${name} (from $(basename "$file")) ---"

    # Translate Verilog -> C++ including testbench
    # FIX: Put the entire verilator command on one line to avoid shell parsing errors 
    # with backslashes and array expansion, which caused "command not found".
    verilator -Wall --trace -cc "${RTL_FILES[@]}" --exe ${file} -y ${RTL_FOLDER} --prefix "Vdut" -o Vdut -CFLAGS "-std=c++17 -isystem /opt/homebrew/Cellar/googletest/1.17.0/include" -LDFLAGS "-L/opt/homebrew/Cellar/googletest/1.17.0/lib -lgtest -lgtest_main -lpthread" 

    # Check if Verilator succeeded (Vdut.mk generated)
    if [ ! -f "obj_dir/Vdut.mk" ]; then
        echo "${RED}Error: Verilator failed to compile ${name}. Aborting test.${RESET}"
        ((fails++))
        continue
    fi
    
    # Build C++ project with automatically generated Makefile
    make -j -C obj_dir/ -f Vdut.mk Vdut
    
    # Check if the executable was successfully built
    if [ ! -f "obj_dir/Vdut" ]; then
        echo "${RED}Error: Executable obj_dir/Vdut not found. Build failed.${RESET}"
        ((fails++))
        continue
    fi

    # Run executable simulation file
    ./obj_dir/Vdut

    # Check if the test succeeded or not
    if [ $? -eq 0 ]; then
        echo "${GREEN}Test ${name} PASSED.${RESET}"
        ((passes++))
    else
        echo "${RED}Test ${name} FAILED.${RESET}"
        ((fails++))
    fi

done

# Save obj_dir in test_out
mv obj_dir test_out/

# Print Summary
echo "========================================"
echo "Tests Passed: ${GREEN}${passes}${RESET}"
echo "Tests Failed: ${RED}${fails}${RESET}"
echo "========================================"