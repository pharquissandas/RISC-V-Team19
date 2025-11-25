module signext (
    input  logic [31:0] instr,
    input  logic [2:0]  ImmSrc,        
    output logic [31:0] ImmOp
);

    logic [31:0] immI, immS, immB, immU, immJ;

    // I-type
    assign immI = {{20{instr[31]}}, instr[31:20]};

    // S-type
    assign immS = {{20{instr[31]}}, 
                    instr[31:25], 
                    instr[11:7]};

    // B-type
    assign immB = {{19{instr[31]}},
                   instr[31],       // imm[12]
                   instr[7],        // imm[11]
                   instr[30:25],    // imm[10:5]
                   instr[11:8],     // imm[4:1]
                   1'b0};           // imm[0] = 0

    // U-type (LUI, AUIPC)
    assign immU = {instr[31:12], 12'b0};

    // J-type (JAL)
    assign immJ = {{11{instr[31]}},
                   instr[31],        // imm[20]
                   instr[19:12],     // imm[19:12]
                   instr[20],        // imm[11]
                   instr[30:21],     // imm[10:1]
                   1'b0};            // imm[0] = 0

    // MUX between immediate types
    always_comb begin
        unique case (ImmSrc)
            3'b000: ImmOp = immI;   // I-type
            3'b001: ImmOp = immS;   // S-type
            3'b010: ImmOp = immB;   // B-type
            3'b011: ImmOp = immU;   // U-type
            3'b100: ImmOp = immJ;   // J-type
            default: ImmOp = 32'b0;
        endcase
    end
endmodule