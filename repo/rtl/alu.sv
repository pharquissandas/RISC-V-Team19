module alu(

    input logic [31:0] alu_op1,  // first operand for the ALU
    input logic [31:0] alu_op2,  // second operand for the ALU
    input logic        alu_ctrl, // ALU control signal: selects operation
                                 // 0 -> addition (for addi)
                                 // 1 -> subtraction (for bne)

    output logic [31:0] alu_out, // ALU output result
    output logic        eq       // equality flag: 1 if alu_op1 == alu_op2
);

// internal signals to hold intermediate results
logic [31:0] equality; // difference between operands, used for comparison
logic [31:0] sum;      // sum of operands, used for addition

// combinational logic block (no clock)
always_comb begin

    // compute subtraction for branch comparison
    equality = alu_op1 - alu_op2;
    // compute addition for arithmetic instructions
    sum = alu_op1 + alu_op2;

    // select ALU output based on control signal
    if(alu_ctrl == 1'b0)
        alu_out = sum;             // alu_ctrl=0 -> addition (addi)
    else
        alu_out = equality;        // alu_ctrl=1 → subtraction (bne)

    // set equality flag: 1 if operands are equal, 0 otherwise
    if(equality == 32'b0)
        eq = 1;
    else
        eq = 0;

end
endmodule
