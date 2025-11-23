module data_unit #(
    parameter DATA_WIDTH = 32,
              ADDRESS_WIDTH = 5
) (
    input  logic                       clk,
    input  logic [ADDRESS_WIDTH-1:0]   AD1,    // rs1 address
    input  logic [ADDRESS_WIDTH-1:0]   AD2,    // rs2 address
    input  logic [ADDRESS_WIDTH-1:0]   AD3,    // rd address
    input  logic [DATA_WIDTH-1:0]      ImmOp,  // immediate value
    input  logic                       RegWrite, // write enable
    input  logic                       ALUctrl,  // ALU control
    input  logic                       ALUsrc,   // select imm or reg
    output logic                       EQ,       // ALU equality flag
    output logic [DATA_WIDTH-1:0]      a0        // x10 output
);

logic [DATA_WIDTH-1:0] ALUout;   // ALU result
logic [DATA_WIDTH-1:0] ALUop1;   // ALU operand 1
logic [DATA_WIDTH-1:0] ALUop2;   // ALU operand 2
logic [DATA_WIDTH-1:0] regOp2;   // register file operand 2

// register file: read rs1/rs2, write rd
reg_file reg_file (
    .clk(clk),
    .read_addr1(AD1),
    .read_addr2(AD2),
    .write_addr(AD3),
    .wd3(ALUout),
    .we3(RegWrite),
    .dout1(ALUop1),
    .dout2(regOp2),
    .a0(a0)
);

// select ALU operand 2: register or immediate
mux mux (
    .in0(regOp2),
    .in1(ImmOp),
    .sel(ALUsrc),
    .out(ALUop2)
);

// ALU executes operation and sets EQ
alu alu (
    .alu_op1(ALUop1),
    .alu_op2(ALUop2),
    .alu_ctrl(ALUctrl),
    .alu_out(ALUout),
    .eq(EQ)
);

endmodule
