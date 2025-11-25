module PC #(
    parameter WIDTH = 32
)(
    input  logic                clk,    // system clock
    input  logic                rst,    // asynchronous reset
    input  logic [1:0]          PCsrc,  // selects between sequential PC and branch target
    input  logic [WIDTH-1:0]    ImmOp,  // immediate offset for branch target
    input  logic [WIDTH-1:0]    JALRjump,  // current program counter input
    output logic [WIDTH-1:0]    pc      // current program counter
);

// compute PC+4 (normal sequential execution)
logic [WIDTH-1:0] inc_PC;

// compute PC+immediate (branch target address)
logic [WIDTH-1:0] branch_PC;

// next PC after the mux
logic [WIDTH-1:0] next_PC;

// add 4 to PC for next instruction
assign inc_PC = pc + {{WIDTH-3{1'b0}}, 3'b100};

// add immediate offset to PC for branch target
assign branch_PC = pc + ImmOp;

// select between sequential PC and branch PC and JALR target
case(PCsrc)
    2'b00: assign next_PC = inc_PC;        // Next sequential instruction
    2'b01: assign next_PC = branch_PC;     // Branch target
    2'b10: assign next_PC = JALRjump;      // JALR target
    default: assign next_PC = inc_PC;      // Default to sequential
endcase

// program counter register with asynchronous reset
always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        pc <= {WIDTH{1'b0}};      // Reset PC to 0
    else
        pc <= next_PC;            // Update PC normally
end

endmodule
