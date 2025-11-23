module mux #(
    parameter DATA_WIDTH = 32
) (
    input   logic [DATA_WIDTH-1:0]  in0,  // first input (selected when sel = 0)
    input   logic [DATA_WIDTH-1:0]  in1,  // second input (selected when sel = 1)
    input   logic                   sel,  // control signal to choose input
    output  logic [DATA_WIDTH-1:0]  out  // output of the multiplexer
);

    // combinational assignment:
    // if sel == 1, output in1; otherwise, output in0
    assign out = sel ? in1 : in0;

endmodule