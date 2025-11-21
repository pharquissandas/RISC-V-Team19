module control (
    /* verilator lint_off UNUSED */
    input  logic [31:0] instr,
    /* verilator lint_on UNUSED */
    input  logic       EQ,        // equality flag from ALU (1 if operands are equal)
    output logic       RegWrite,
    output logic       ALUsrc,
    output logic       ALUctrl,   // 0 = add, 1 = sub
    output logic       ImmSrc,    // 0 = I-type, 1 = B-type
    output logic       PCsrc      // select next PC: 0 = PC+4, 1 = branch target
);

    // internal signals
    logic branch;
    logic [6:0] opcode;
    assign opcode = instr[6:0];   // extract opcode (bits [6:0])

    // combinational logic: decode opcode to generate control signals
    always_comb begin
        RegWrite = 0;
        ALUsrc   = 0;
        ALUctrl  = 0;
        ImmSrc   = 0;
        branch   = 0;

        case (opcode)
            7'b0010011: begin  // ADDI
                RegWrite = 1;
                ALUsrc   = 1;  // immediate
                ALUctrl  = 0;  // add
                ImmSrc   = 0;  // I-type
                branch   = 0;
            end

            7'b1100011: begin  // BNE
                RegWrite = 0;
                ALUsrc   = 0;
                ALUctrl  = 1;  // subtract
                ImmSrc   = 1;  // B-type immediate
                branch   = 1;
            end

            default: begin
                RegWrite = 0;
                ALUsrc   = 0;
                ALUctrl  = 0;
                ImmSrc   = 0;
                branch   = 0;
            end
        endcase
    end

    // determine next PC: branch taken if branch instruction AND operands not equal
    assign PCsrc = branch & (~EQ);

endmodule

