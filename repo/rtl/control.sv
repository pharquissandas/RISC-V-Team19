module control (
    input  logic [31:0] instr,
    input  logic [2:0]  EQ,       
    output logic        RegWrite,
    output logic        ALUSrc,
    output logic [2:0]  ALUctrl,
    output logic [2:0]  ImmSrc,
    output logic [1:0]  ResultSrc,
    output logic        MemWrite,
    output logic [1:0]  PCsrc,    
    output logic [2:0]  funct3
);

    // fields
    logic [6:0] opcode = instr[6:0];
    logic [6:0] funct7 = instr[31:25];
    assign funct3 = instr[14:12];
    // wires between decoders
    logic Branch;
    logic [1:0] ALUOp;

    // instantiate main decoder
    main_decoder main_dec (
        .opcode(opcode),
        .RegWrite(RegWrite),
        .ALUSrc(ALUSrc),
        .ResultSrc(ResultSrc),
        .MemWrite(MemWrite),
        .ImmSrc(ImmSrc),
        .Branch(Branch),
        .ALUOp(ALUOp)
    );

        // instantiate ALU decoder
    alu_decoder alu_dec (
        .ALUOp(ALUOp),
        .funct3(funct3),
        .funct75(funct7[5]),
        .ALUctrl(ALUctrl)
    );

    always_comb begin
        if (Branch) begin
            case(funct3)
                3'b000: begin // BEQ
                    if (EQ == 3'b000) begin
                        PCsrc = 2'b01;
                    end
                end
                3'b001: begin // BNE
                    if (EQ == 3'b001) begin
                        PCsrc = 2'b01;
                    end
                end
                3'b100: begin // BLT
                    if (EQ == 3'b010) begin
                        PCsrc = 2'b01;
                    end
                end
                3'b101: begin // BGE
                    if (EQ == 3'b011) begin
                        PCsrc = 2'b01;
                    end
                end
                3'b110: begin // BLTU
                    if (EQ == 3'b100) begin
                        PCsrc = 2'b01;
                    end
                end
                3'b111: begin // BGEU
                    if (EQ == 3'b101) begin
                        PCsrc = 2'b01;
                    end
                end
                default: begin
                    PCsrc = 2'b00;
                end
            endcase
        end
            
        case(opcode)
            7'b1101111: begin // JAL
                PCsrc = 2'b01;
            end
            7'b1100111: begin // JALR
                PCsrc = 2'b10;
            end
            default: begin
                PCsrc = 2'b00;
            end
        endcase
    end

endmodule
