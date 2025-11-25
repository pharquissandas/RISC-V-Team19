    // 0000 = ADD
    // 0001 = SUB
    // 0010 = AND
    // 0011 = OR
    // 0100 = XOR
    // 0101 = SLL
    // 0110 = SRL
    // 0111 = SRA
    // 1000 = SLT (signed)
    // 1001 = SLTU (unsigned)

module alu (
    input logic [31:0] SrcA,
    input logic [31:0] SrcB,
    input logic [3:0] ALUControl,
    output logic [31:0] ALUResult,
    output logic [2:0] Zero
);

    always_comb begin
        case (ALUControl)
            4'b0000: ALUResult = SrcA + SrcB; // add
            4'b0001: ALUResult = SrcA - SrcB; // sub
            4'b0010: ALUResult = SrcA & SrcB; // and
            4'b0011: ALUResult = SrcA | SrcB; // or
            4'b0100: ALUResult = SrcA ^ SrcB; // xor

            4'b0101 : ALUResult = SrcA << SrcB[4:0]; // sll
            4'b0110: ALUResult = SrcA >> SrcB[4:0]; // srl
            4'b0111: ALUResult = $signed(SrcA) >>> SrcB[4:0]; // sra
            4'b1000: ALUResult = ($signed(SrcA) < $signed(SrcB)) ? 32'b1 : 32'b0; //slt
            4'b1001: ALUResult = (SrcA < SrcB) ? 32'b1 : 32'b0; //sltu
            default: ALUResult = 32'b0;

        endcase
    end
    
    if ($signed(SrcA) == $signed(SrcB)) begin
        assign Zero = 3'b000; // zero flag
    end
    if ($signed(SrcA) != $signed(SrcB)) begin
        assign Zero = 3'b001; // not equal
    end
    if ($signed(SrcA) < $signed(SrcB)) begin
        assign Zero = 3'b010; // less than flag
    end
    if ($signed(SrcA) >= $signed(SrcB)) begin
        assign Zero = 3'b011; // greater/equal than flag
    end
    if ($unsigned(SrcA) < $unsigned(SrcB)) begin
        assign Zero = 3'b100; // less than flag unsigned
    end
    if ($unsigned(SrcA) >= $unsigned(SrcB)) begin
        assign Zero = 3'b101; // greater/equal than flag unsinged
    end
    
endmodule