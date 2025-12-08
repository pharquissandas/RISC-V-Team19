module memory_to_writeback_register(

    input logic clk,
    input logic rst,
    input logic en,

    input logic RegWriteM,
    input logic [1:0] ResultSrcM,

    input logic [31:0] ALUResultM1,
    input logic [31:0] ReadDataM1,
    input logic [4:0] RdM1,
    input logic [31:0] PCPlus4M1,
    input logic [31:0] ALUResultM2,
    input logic [31:0] ReadDataM2,
    input logic [4:0] RdM2,
    input logic [31:0] PCPlus4M2,

    output logic RegWriteW,
    output logic [1:0] ResultSrcW,

    output logic [31:0] ALUResultW1,
    output logic [31:0] ReadDataW1,
    output logic [4:0] RdW1,
    output logic [31:0] PCPlus4W1,
    output logic [31:0] ALUResultW2,
    output logic [31:0] ReadDataW2,
    output logic [4:0] RdW2,
    output logic [31:0] PCPlus4W2
);

    always_ff @(posedge clk) begin
        if (rst) begin

            RegWriteW    <= 1'b0;
            ResultSrcW   <= 2'b0;

            ALUResultW   <= 32'b0;
            ReadDataW    <= 32'b0;
            RdW          <= 5'b0;
            PCPlus4W     <= 32'b0;
        end

        else if (en) begin

            RegWriteW    <= RegWriteM;
            ResultSrcW   <= ResultSrcM;

            ALUResultW   <= ALUResultM;
            ReadDataW    <= ReadDataM;
            RdW          <= RdM;
            PCPlus4W     <= PCPlus4M;
        end
    end

endmodule
