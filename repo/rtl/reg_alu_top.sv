module reg_alu_top #(
    parameter   DATA_WIDTH = 32,
                ADDRESS_WIDTH = 5
) (
    input logic                         clk,
    input logic  [ADDRESS_WIDTH-1:0]    AD1,
    input logic  [ADDRESS_WIDTH-1:0]    AD2,
    input logic  [ADDRESS_WIDTH-1:0]    AD3,
    input logic  [DATA_WIDTH-1:0]       ImmOp,
    input logic                         RegWrite,
    input logic                         ALUctrl,
    input logic                         ALUsrc,
    output logic                        EQ,
    output logic [DATA_WIDTH-1:0]       a0
);

logic [DATA_WIDTH-1:0] ALUout;
logic [DATA_WIDTH-1:0] ALUop1;
logic [DATA_WIDTH-1:0] ALUop2;
logic [DATA_WIDTH-1:0] regOp2;

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

mux mux (
    .in0(regOp2),
    .in1(ImmOp),
    .sel(ALUsrc),
    .out(ALUop2)
);

alu alu (
    .alu_op1(ALUop1),
    .alu_op2(ALUop2),
    .alu_ctrl(ALUctrl),
    .alu_out(ALUout),
    .eq(EQ)
);

endmodule
