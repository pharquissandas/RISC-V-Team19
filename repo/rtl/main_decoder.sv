module main_decoder (
    input logic [6:0]  opcode,     // 7-bit opcode field from the instruction
    output logic       ResultsSrc, // selects data written to register file (ALU result or memory data)
    output logic       MemWrite,   // enable writing to data memory
    output logic       ALUsrc,     // selects ALU second operand (0 = register, 1 = immediate)
    output logic       RegWrite,   // enable writing to register file
    output logic       Branch,     // indicates branch instruction
    output logic [1:0] ImmSrc,     // selects type of immediate
    output logic [1:0] ALUop       // encodes ALU operation type (passed to ALU control)
);

// combinational logic to decode opcode and generate control signals
always_comb begin
    case(opcode)

        // load instructions (e.g., LW)
        7'b0000011: begin 
            ResultsSrc = 1;        
            MemWrite   = 0;
            ALUsrc     = 1;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUop      = 2'b00;
        end

        // store instructions (e.g., SW)
        7'b0100011: begin 
            ResultsSrc = X;
            MemWrite   = 1;
            ALUsrc     = 1;
            RegWrite   = 0;
            Branch     = 0;
            ImmSrc     = 2'b01;
            ALUop      = 2'b00;
        end

        // R-type instructions (e.g., ADD, SUB)
        7'b0110011: begin 
            ResultsSrc = 0;
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 1;
            Branch     = 0;
            ImmSrc     = 2'bXX;
            ALUop      = 2'b10;
        end

        // branch instructions (e.g., BNE, BEQ)
        7'b1100011: begin 
            ResultsSrc = X;
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 0;
            Branch     = 1;
            ImmSrc     = 2'b10;
            ALUop      = 2'b01;  // ALU performs subtraction for comparison
        end

        default: begin
            ResultsSrc = 0;
            MemWrite   = 0;
            ALUsrc     = 0;
            RegWrite   = 0;
            Branch     = 0;
            ImmSrc     = 2'b00;
            ALUop      = 2'b00;
        end
    endcase
end

endmodule