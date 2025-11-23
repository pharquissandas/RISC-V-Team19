module PC #(
    parameter WIDTH = 32
)(
    input  logic                clk,    // system clock
    input  logic                rst,    // asynchronous reset
    input  logic                PCsrc,  // selects between sequential PC and branch target
    input  logic [WIDTH-1:0]    ImmOp,  // immediate offset for branch target
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

// select between sequential PC and branch PC
assign next_PC = PCsrc ? branch_PC : inc_PC;

// program counter register with asynchronous reset
always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        pc <= {WIDTH{1'b0}};      // Reset PC to 0
    else
        pc <= next_PC;            // Update PC normally
end

endmodule
