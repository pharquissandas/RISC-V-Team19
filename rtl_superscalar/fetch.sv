module fetch(
    input logic clk,
    input logic rst,
    input logic en,
    input logic [1:0] PCSrcE1,
    input logic [31:0] PCTargetE1,
    input logic [31:0] ALUResultE1,
    input logic [1:0] PCSrcE2,
    input logic [31:0] PCTargetE2,
    input logic [31:0] ALUResultE2,
    
    output logic [31:0] InstrF1,
    output logic [31:0] InstrF2,
    output logic [31:0] PCF1,
    output logic [31:0] PCPlus8F1,
    output logic [31:0] PCF2,
    output logic [31:0] PCPlus8F2
);


    logic  [31:0] PCF1;
    logic  [31:0] PCF2;

    pc pc_inst(
        .clk(clk),
        .rst(rst),
        .en(en),
        .PCSrcE1(PCSrcE1),
        .ALUResultE1(ALUResultE1),
        .PCTargetE1(PCTargetE1),
        .PCSrcE2(PCSrcE2),
        .ALUResultE2(ALUResultE2),
        .PCTargetE2(PCTargetE2),

        .PCF1(PCF1),
        .PCF2(PCF2),
        .PCPlus8F2(PCPlus8F1),
        .PCPlus8F2(PCPlus8F2)
    );

    instr_mem instr_mem_inst(
        .A1(PCF1),
        .A2(PCF2),
        
        .RD1(InstrF1)
        .RD2(InstrF2)
    );
endmodule
