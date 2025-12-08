module fetch_to_decode_register(

    input logic clk,
    input logic en,
    input logic rst,
    input logic [31:0] PCF1,
    input logic [31:0] PCPlus8F1,
    input logic [31:0] InstrF1,
    input logic [31:0] PCF2,
    input logic [31:0] PCPlus8F2,
    input logic [31:0] InstrF2,

    output logic [31:0] PCD1,
    output logic [31:0] PCD2,
    output logic [31:0] PCPlus8D1,
    output logic [31:0] PCPlus8D2,
    output logic [31:0] InstrD1,
    output logic [31:0] InstrD2,

);

    always_ff @(posedge clk) begin
        if (rst) begin
            PCD1 <= 32'b0;
            PCPlus8D1 <= 32'b0;
            InstrD1 <= 32'b0;
            PCD2 <= 32'b0;
            PCPlus8D2 <= 32'b0;
            InstrD2 <= 32'b0;
        end
        else if (en) begin
            PCD1 <= PCF1;
            PCPlus8D1 <= PCPlus8F1;
            InstrD1 <= InstrF1;
            PCD2 <= PCF2;
            PCPlus8D2 <= PCPlus8F2;
            InstrD2 <= InstrF2;
        end
    end
endmodule
