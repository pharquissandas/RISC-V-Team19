module main_decoder (
    input logic [6:0]  opcode,     // 7-bit opcode field from the instruction

    output logic [1:0] ResultSrc,  // control the source of data to write back to register file (00 = ALU, 01 = Memory, 10 = PC+4)
    output logic [1:0] PCSrc,      // control the source for the next PC value (00 = PC+4, 01 = PC + imm(branch/jal), 10 = ALUResult (jalr))
    output logic       MemWrite,   // enable writing to data memory
    output logic       ALUSrc,     // selects ALU second operand (0 = register, 1 = immediate)
    output logic       RegWrite,   // enable writing to register file
    output logic       Branch,     // indicates branch instruction
    output logic       Jump,
    output logic [2:0] ImmSrc,     // selects type of immediate (I = 000, S = 001, B = 010, U = 011, J = 100)
    output logic [1:0] ALUOp,      // encodes ALU operation type (passed to ALU control)
    output logic [2:0] AddressingControl
);

// combinational logic to decode opcode and generate control signals
always_comb begin
    // default values (safe defaults)
    ResultSrc = 2'b00;
    MemWrite  = 0;
    ALUSrc    = 0;
    RegWrite  = 0;
    Branch    = 0;
    ImmSrc    = 3'b000;
    ALUOp     = 2'b00;

    case(opcode)
    
        // load instructions: LB, LH, LW, LBU, LHU
        // opcode = 0000011 
        7'b0000011: begin
            ResultSrc = 2'b01;       // load data from memory
            MemWrite  = 0;
            ALUSrc    = 1;       // use immediate for address
            RegWrite  = 1;
            Branch    = 0;
            ImmSrc    = 3'b000;   // I-type immediate
            ALUOp     = 2'b00;   // ALU does ADD for address
        end

        // store instructions: SB, SH, SW S-type
        // opcode = 0100011
        7'b0100011: begin
            ResultSrc = 2'b00;       // don't care
            MemWrite  = 1;       // write to data memory
            ALUSrc    = 1;       // use immediate for address
            RegWrite  = 0;
            Branch    = 0;
            ImmSrc    = 3'b001;   // S-type immediate
            ALUOp     = 2'b00;   // ALU does ADD for address
        end

        // R-type instructions: ADD, SUB, SLL, SLT, SLTU, XOR, SRL, SRA, OR, AND
        // opcode = 0110011
        7'b0110011: begin
            ResultSrc = 2'b00;       
            MemWrite  = 0;
            ALUSrc    = 0;       // second operand from register
            RegWrite  = 1;       
            Branch    = 0;
            ImmSrc    = 3'b000;   // don't care
            ALUOp     = 2'b10;   // R-type ALU decoding
        end

        // B-type instructions: BEQ, BNE, BLT, BGE, BLTU, BGEU
        // opcode = 1100011
        7'b1100011: begin
            ResultSrc = 2'b00;       // don't care
            MemWrite  = 0;
            ALUSrc    = 0;       // use registers
            RegWrite  = 0;
            Branch    = 1;       // enable branch logic
            ImmSrc    = 3'b010;   // B-type immediate
            ALUOp     = 2'b01;   // ALU subtracts for comparison
        end

        // I-type arithmetic: ADDI, SLTI, SLTIU, XORI, ORI, ANDI, SLLI, SRLI, SRAI
        // opcode = 0010011
        7'b0010011: begin
            ResultSrc = 2'b00;
            MemWrite  = 0;
            ALUSrc    = 1;       // use immediate
            RegWrite  = 1;
            Branch    = 0;
            ImmSrc    = 3'b000;   // I-type immediate
            ALUOp     = 2'b11;   // I-type ALU (distinct from R-type)
        end

        // AUIPC (U-type)
        // opcode = 0010111
        7'b0010111: begin
            ResultSrc = 2'b00;
            MemWrite  = 0;
            ALUSrc    = 1;
            RegWrite  = 1;
            Branch    = 0;
            ImmSrc    = 3'b011;   // U-type immediate
            ALUOp     = 2'b00;
        end

        // LUI (U-type)
        // opcode = 0110111
        7'b0110111: begin
            ResultSrc = 2'b00;
            MemWrite  = 0;
            ALUSrc    = 1;
            RegWrite  = 1;
            Branch    = 0;
            ImmSrc    = 3'b011;   // U-type immediate
            ALUOp     = 2'b00;
        end

        // JAL (J-type)
        // opcode = 1101111
        7'b1101111: begin
            ResultSrc = 2'b10;       // return address is PC+4 (handled in datapath)
            MemWrite  = 0;
            ALUSrc    = 1;
            RegWrite  = 1;       // write x[rd] = PC+4
            Branch    = 0;
            ImmSrc    = 3'b100;   
            ALUOp     = 2'b00;
        end

        // JALR (I-type)
        // opcode = 1100111
        7'b1100111: begin
            ResultSrc = 2'b10;
            MemWrite  = 0;
            ALUSrc    = 1;
            RegWrite  = 1;
            Branch    = 0;
            ImmSrc    = 3'b000;
            ALUOp     = 2'b00;
        end

        default: begin
            ResultSrc  = 2'b00;
            MemWrite   = 0;
            ALUSrc     = 0;
            RegWrite   = 0;
            Branch     = 0;
            ImmSrc     = 3'b000;
            ALUOp      = 2'b00;
        end
    endcase
end

endmodule