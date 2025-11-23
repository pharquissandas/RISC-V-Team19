module signext (
    /* verilator lint_off UNUSED */
    input  logic [31:0] instr,        // full 32-bit instruction word
    /* verilator lint_on UNUSED */
    input  logic        ImmSrc,       // 0 = I-type immediate, 1 = B-type immediate
    output logic [31:0] ImmOp         // sign-extended immediate output
);

    logic [31:0] immI; // I-type immediate
    logic [31:0] immB; // B-type immediate

    assign immI = {{20{instr[31]}}, instr[31:20]};

    assign immB = {{19{instr[31]}},
                   instr[31],        // imm[12]
                   instr[7],         // imm[11]
                   instr[30:25],     // imm[10:5]
                   instr[11:8],      // imm[4:1]
                   1'b0              // imm[0]
                  };

    // select appropriate immediate based on instruction type
    assign ImmOp = (ImmSrc == 0) ? immI : immB;

endmodule


