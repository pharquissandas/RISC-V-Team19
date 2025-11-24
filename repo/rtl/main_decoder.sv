module main_decoder (
    input logic [6:0]  opcode,     // 7-bit opcode field from the instruction
    output logic       ResultSrc,  // selects data written to register file (ALU result or memory data)
    output logic       MemWrite,   // enable writing to data memory
    output logic       ALUsrc,     // selects ALU second operand (0 = register, 1 = immediate)
    output logic       RegWrite,   // enable writing to register file
    output logic       Branch,     // indicates branch instruction
    output logic [1:0] ImmSrc,     // selects type of immediate
    output logic [1:0] ALUOp       // encodes ALU operation type (passed to ALU control)
);

// combinational logic to decode opcode and generate control signals
always_comb begin
    case(opcode)

        // load instructions: LB, LH, LW, LBU, LHU
        7'b0000011: begin 
            ResultSrc  = 1;        
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUOp      = 2'b00;
        end

        // store instructions: SB, SH, SW
        7'b0100011: begin 
            ResultSrc  = 0; // don't care
            MemWrite   = 1;
            ALUsrc     = 1;
            RegWrite   = 0;
            Branch     = 0;
            ImmSrc     = 2'b01;
            ALUOp      = 2'b00;
        end

        // R-type instructions: ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
        7'b0110011: begin 
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00; // don't care
            ALUOp      = 2'b10;
        end

        // B-type instructions: BEQ, BNE, BLT, BGE, BLTU, BGEU
        7'b1100011: begin 
            ResultSrc  = 0; // don't care
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 0;
            Branch     = 1;
            ImmSrc     = 2'b10;
            ALUOp      = 2'b01;  // ALU performs subtraction for comparison
        end

        // I-type arithmetic: ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI
        7'b0010011: begin
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUOp      = 2'b10;
        end

        7'b0010111: begin // AUIPC U-type
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b11; 
            ALUOp      = 2'b00;
        end

        7'b0110111: begin // LUI U-type
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b11; 
            ALUOp      = 2'b00;
        end

        7'b1101111: begin // JAL J-type
            ResultSrc  = 0; // don't care
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00; // don't care
            ALUOp      = 2'b00;
        end

        7'b1100111: begin // JALR I-type
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUOp      = 2'b00;
        end

        default: begin
            ResultSrc  = 0;
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 0;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUOp      = 2'b00;
        end
    endcase
end

endmodule