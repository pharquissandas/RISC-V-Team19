module PC #(
    parameter WIDTH = 32
)(
    input logic clk,
    input logic rst,
    input logic PCsrc,
    input logic [WIDTH-1:0] ImmOp,
    output logic [WIDTH-1:0] pc
);

logic [WIDTH-1:0] branch_PC;
logic [WIDTH-1:0] inc_PC;
logic [WIDTH-1:0] next_PC;

assign inc_PC = pc + {{WIDTH-3{1'b0}}, 3'b100};
assign branch_PC = pc + ImmOp;
assign next_PC = PCsrc ? branch_PC : inc_PC;

always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        pc <= {WIDTH{1'b0}};
    else
        pc <= next_PC;
    end
endmodule
