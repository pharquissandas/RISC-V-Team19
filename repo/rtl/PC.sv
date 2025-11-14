module PC #(
    parameter WIDTH = 32
)(
    input logic clk,
    input logic rst,
    input logic PCsrc,
    input logic [WIDTH-1:0] immOp,
    output logic [WIDTH-1:0] pc
);

logic [WIDTH-1:0] branch_PC;
logic [WIDTH-1:0] inc_PC;
logic [WIDTH-1:0] next_PC;

assign inc_PC = pc + WIDTH'd4; 
assign branch_PC = pc + immOp;
assign next_PC = PCsrc ? branch_PC : inc_PC;

always_ff @(posedge clk or posedge rst) begin
    if (rst) 
        pc <= {WIDTH{1'b0}};
    else
        pc <= next_PC;
    end
endmodule
