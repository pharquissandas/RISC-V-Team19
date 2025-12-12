module execute_to_memory_register (

    input logic clk,
    input logic en1,
    input logic en2,
    input logic rst1,
    input logic rst2,

    input logic RegWriteE1,
    input logic [1:0] ResultSrcE1,
    input logic MemWriteE1,
    input logic [2:0] AddressingControlE1,

    input logic RegWriteE2,
    input logic [1:0] ResultSrcE2,
    input logic MemWriteE2,
    input logic [2:0] AddressingControlE2,

    input logic [31:0] ALUResultE1,
    input logic [31:0] WriteDataE1,
    input logic [4:0] RdE1,

        
    input logic [31:0]    PCPlus4E2, // PC + 4
    input logic [31:0]    PCPlus4E1, // PC + 4



    input logic [31:0] ALUResultE2,
    input logic [31:0] WriteDataE2,
    input logic [4:0] RdE2,
    
    output logic RegWriteM1,
    output logic [1:0] ResultSrcM1,
    output logic MemWriteM1,
    output logic [2:0] AddressingControlM1,

    output logic RegWriteM2,
    output logic [1:0] ResultSrcM2,
    output logic MemWriteM2,
    output logic [2:0] AddressingControlM2,

    output logic [31:0] ALUResultM1,
    output logic [31:0] ALUResultM2,
    output logic [31:0] WriteDataM1,
    output logic [31:0] WriteDataM2,
    output logic [4:0] RdM1,
    output logic [4:0] RdM2,
    output logic [31:0]    PCPlus4M1, // PC + 4
    output logic [31:0]    PCPlus4M2 // PC + 4

);
    always_ff @(posedge clk) begin
        
        if (rst1) begin

            RegWriteM1          <= 1'b0;
            ResultSrcM1         <= 2'b0;
            MemWriteM1          <= 1'b0;
            AddressingControlM1 <= 3'b0;

            ALUResultM1   <= 32'b0;
            WriteDataM1   <= 32'b0;
            RdM1          <= 5'b0;
            PCPlus4M1     <= 32'b0;


        end
            
        else if (en1) begin
            RegWriteM1          <= RegWriteE1;
            ResultSrcM1         <= ResultSrcE1;
            MemWriteM1          <= MemWriteE1;
            AddressingControlM1 <= AddressingControlE1;

            ALUResultM1   <= ALUResultE1;
            WriteDataM1   <= WriteDataE1;
            RdM1          <= RdE1;
            PCPlus4M1     <= PCPlus4E1;


        end

        if (rst2) begin

            RegWriteM2          <= 1'b0;
            ResultSrcM2         <= 2'b0;
            MemWriteM2          <= 1'b0;
            AddressingControlM2 <= 3'b0;

            ALUResultM2   <= 32'b0;
            WriteDataM2   <= 32'b0;
            RdM2          <= 5'b0;
            PCPlus4M2     <= 32'b0;


        end


        else if(en2) begin

            RegWriteM2          <= RegWriteE2;
            ResultSrcM2         <= ResultSrcE2;
            MemWriteM2          <= MemWriteE2;
            AddressingControlM2 <= AddressingControlE2;

            ALUResultM2   <= ALUResultE2;
            WriteDataM2   <= WriteDataE2;
            RdM2          <= RdE2;
            PCPlus4M2     <= PCPlus4E2;

        end

    end

endmodule
