module register(

    input  logic       clk,      // clock signal
    input  logic [31:0] d,       // input data
    output logic [31:0] q        // stored output data
);

    // simple D-flip-flop register -> on every rising edge of clk, q updates to the value of d
    always_ff @(posedge clk)
        q <= d;

endmodule
