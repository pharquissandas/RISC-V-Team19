Name: Preet Harquissandas \
CID: 02589338 \
GitHub username: pharquissandas

## Table of Contents
- [Summary](#summary)
- [Contributions](#contributions)
  - [Reduced RISC-V CPU](#reduced-risc-v-cpu)
  - [Single-Cycle RV32I Design](#single-cycle-rv32i-design)
  - [Pipelined RV32I Design](#pipelined-rv32i-design)
  - [Full RV32I Design](#full-rv32i-design)
  - [Other](#other)
- [Self-Reflection](#self-reflection)
- [Additional Notes](#additional-notes)

## Summary
I was deeply involved in nearly every phase of our design, from the foundational Lab 4 and single-cycle architectures through to the final pipelining stage. My core contributions included significant work on the control unit, instruction memory, and the top file for the single-cycle and pipelined designs. I ensured the robustness of the entire system by implementing most of the testbenches and adding features such as the branch predictor.

As the repository master, my responsibility was managing our Git repository; I was responsible for handling all merging and branching, resolving conflicts, as well as setting up the repository structure.

## Contributions
### Reduced RISC-V CPU
When we started Lab 4, we wanted to split up the work evenly to ensure everyone's work was smooth sailing, and as the repo-master, I decided to delegate parts of the reduced RISC-V CPU to each of our members using the diagram. Hence, I ended up working with the control unit, the instruction memory, and the sign extend unit.

### Control Unit
My tasks for the Control Unit included:
* Opcode Decoding: Designing the combinational logic to decode the opcode from the fetched instruction.
* Signal Generation: Implementing logic to generate all the necessary control signals such as `RegWrite`, `ALUsrc`, `ALUctrl`, and `PCsrc`.
[commit https://github.com/pharquissandas/RISC-V-T19/commit/1fa77a0fecea4949b321e9a90991a9beef985d96]

### Instruction Memory
My tasks for the Instruction Memory included:
* Address Mapping: Designing the memory component that uses the Program Counter value as the read address.
* Instruction Fetch: Making sure the module correctly fetches and outputs a 32-bit instruction to be used by the Control Unit and Register File.
[commit https://github.com/pharquissandas/RISC-V-T19/commit/ead1aaad1bf962329ddfa14dffb50cd69831e4c8]

### Sign Extend Unit
My tasks for the Sign Extend Unit included:
* Value Conversion: Implementing logic to correctly convert a shorter-width immediate field from the instruction into a full 32-bit value (`ImmOp`).
* Sign Preservation: Ensuring sign extension was correctly performed by replicating the most significant bit across the upper portion of the 32-bit word to preserve the magnitude and sign of signed immediate operands.
[commit https://github.com/pharquissandas/RISC-V-T19/commit/fa70067a8bb9b5d0cb9897bae69a39b1cbf83850]

### Single-Cycle RV32I Design
We went into the single-cycle design thinking strategically, where we thought it would be best to incorporate all the RV32I instructions first, so that we do not need to change the widths of bits later, once we eventually end up adding all the RV32I instructions as part of the 3rd extension. Hence, Mikhail and I split up the workload and completed the tasks; however, to integrate our modules, we needed consistency with bit widths and names, and so we ended up refactoring the ALU, the Control Unit, the Instruction Memory, and the top module together.

### ALU (refactor)
To include all the RV32I instructions, the first step was to increase the width of the `ALUControl` input signal from 3 bits to 4 bits, which allowed 16 possible codes, providing us with the necessary unique codes to encode the additional operations like XOR shifts, SLTU, and LUI. The second step was to add the logic for missing operations (XOR, SLTU, SLL, SRL, SRA, LUI). The final step was to revert the `Zero` signal assignment from a continuous `assign` statement back to a procedural assignment within the `always_comb` block.
[commit https://github.com/pharquissandas/RISC-V-T19/commit/24ef56489af87d1d3de3a645ac508def9d05a538]

### Control Unit (refactor)
Essentially, there was a major architectural upgrade from a very basic processor only supporting ADDI and BNE to a near-complete RV32I instruction set implementation. The new module supports the entire $\text{RV32I}$ base integer instruction set, including: R-type, I-type Arithmetic/Logic, Load I-type, Store S-type, Branch B-type, Jump J-type, and Upper Immediate U-type. Furthermore, this introduced hierarchical decoding using `funct3` and `funct7` fields in addition to the opcode.
[commit https://github.com/pharquissandas/RISC-V-T19/commit/cf6d7b6df7c5a62373bf16329480c28ed68ac781#diff-2f77de39a340b3167ec191e7fbc21567c1378d94d4f1265ed6bd788b98e6e39e]

### Testbenches
Here I added testbenches
[commit https://github.com/pharquissandas/RISC-V-T19/commit/354eebc87c0115990f2d5e72130384fd24c12863]

### Pipelined RV32I Design

### Full RV32I Design

### Other

## Self-Reflection

## Additional Notes