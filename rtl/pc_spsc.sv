module pc_spsc #(
    parameter WIDTH = 32
)(
//Pipeline 1:
    input  logic                clk,    // system clock
    input  logic                rst,    // asynchronous reset
    input  logic                en1,     // enable signal
    input  logic                en2,     // enable signal
    input  logic [1:0]          PCSrcE1,  // control the source for the next PC value (00 = PC+4, 01 = PC + imm(branch/jal), 10 = ALUResult (jalr))

    input  logic [WIDTH-1:0]    PCTargetE1,
            
    /* verilator lint_off UNUSED */

    input  logic [WIDTH-1:0]    ALUResultE1,

    output logic [WIDTH-1:0]    PCPlus4F1, // PC + 4

    output logic [WIDTH-1:0]    PCF1,      // current program counter

//Pipeline 2:
    input  logic [1:0]          PCSrcE2,  // control the source for the next PC value (00 = PC+4, 01 = PC + imm(branch/jal), 10 = ALUResult (jalr))

    input  logic [WIDTH-1:0]    PCTargetE2,
            
    /* verilator lint_off UNUSED */

    input  logic [WIDTH-1:0]    ALUResultE2,

    /* verilator lint_on UNUSED */

    output logic [WIDTH-1:0]    PCPlus4F2, // PC + 4

    output logic [WIDTH-1:0]    PCF2      // current program counter
);


// next PC after the mux
logic [WIDTH-1:0] PCNext1;
logic [WIDTH-1:0] PCNext2;
logic [WIDTH-1:0] PCPlus8F1;
logic [WIDTH-1:0] PCPlus8F2;

// logic [WIDTH-1:0] PCTarget;

always_comb begin
   
    assign PCPlus8F1 = PCF1 + 8;
    assign PCPlus8F2 = PCF2 + 8;
    PCPlus4F1 = PCF1 + 4;
    PCPlus4F2 = PCF2 + 4;

    if(PCSrcE1 == 2'b00 && PCSrcE2 == 2'b01)begin

        PCNext1 = PCTargetE2;
        PCNext2 = PCTargetE2 + 4;

    end
    else if(PCSrcE1 == 2'b01 && PCSrcE2 == 2'b00)begin

        PCNext1 = PCTargetE1;
        PCNext2 = PCTargetE1 + 4;

    end
    else if (PCSrcE1 == 2'b00 && PCSrcE2 == 2'b00)begin

        PCNext1 = PCPlus8F1;
        PCNext2 = PCPlus8F2;

    end
    else if (PCSrcE1 == 2'b01 && PCSrcE2 == 2'b01)begin

        PCNext1 = PCTargetE1;
        PCNext2 = PCTargetE1 + 4;

    end
    else if (PCSrcE1 == 2'b10) begin

        PCNext1 = {ALUResultE1[31:2], 2'b00};
        PCNext2 = PCNext1  +4;

    end
    else if (PCSrcE2 == 2'b10) begin

        PCNext2 = {ALUResultE2[31:2], 2'b00};
        PCNext1 = PCNext2 + 4;

    end
    else begin // need to implement JAL

        PCNext1 = PCPlus8F1;
        PCNext2 = PCPlus8F2;
    
    end

end

// program counter register with asynchronous reset
always_ff @(posedge clk) begin
    if (rst) begin
        PCF1 <= {WIDTH{1'b0}};      // Reset PC1 to 0
        PCF2 <= 32'h4;              //Reset PC2 to 4
    end
    else begin

        if (en1) begin
            PCF1 <= PCNext1;            // Update PC normally
        end
        if (en2) begin
        PCF2 <= PCNext2; 
        end



    end
    
end

endmodule
