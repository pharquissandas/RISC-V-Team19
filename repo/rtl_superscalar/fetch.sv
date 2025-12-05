module fetch(
    input logic clk,
    input logic rst,
    input logic en1,
    input logic en2,
    input logic [1:0] PCSrcE,
    input logic [31:0] PCTargetE,
    input logic [31:0] ALUResultE,
    input logic pc_redirect_i,
    input logic [31:0] mispredict_target_pc_i,
    input logic pc_predict_redirect_i,
    input logic [31:0] predicted_target_pc_i,

    output logic [31:0] InstrF1,
    output logic [31:0] InstrF2,
    output logic [31:0] PCF1,
    output logic [31:0] PCPlus4F1,
    output logic [31:0] PCF2,
    output logic [31:0] PCPlus4F2
);
    pc pc_inst1(
        .clk(clk),
        .rst(rst),
        .en(en),
        .PCSrcE(PCSrcE),
        .ALUResultE(ALUResultE),
        .PCTargetE(PCTargetE),
        .pc_redirect_i(pc_redirect_i),
        .mispredict_target_pc_i(mispredict_target_pc_i),
        .pc_predict_redirect_i(pc_predict_redirect_i),
        .predicted_target_pc_i(predicted_target_pc_i),
        .PCPlus4F1(PCPlus4F1),
        .PCF1(PCF1),
        .PCPlus4F2(PCPlus4F2),
        .PCPlus4F2(PCPlus4F2)
    );

    instr_mem instr_mem_inst(
        .A1(PCF1),
        .A2(PCF2),
        .RD1(InstrF1)
        .RD2(InstrF2)
    );
endmodule
