module reg_file #(
    parameter   ADDRESS_WIDTH = 5,
                DATA_WIDTH = 32
)(
    input logic                         clk,
    input logic  [ADDRESS_WIDTH-1:0]    write_addr,
    input logic  [ADDRESS_WIDTH-1:0]    read_addr1,
    input logic  [ADDRESS_WIDTH-1:0]    read_addr2,
    input logic  [DATA_WIDTH-1:0]       wd3,
    input logic                         we3,
    output logic [DATA_WIDTH-1:0]       dout1,
    output logic [DATA_WIDTH-1:0]       dout2,
    output logic [DATA_WIDTH-1:0]       a0
);

logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

always_ff @(posedge clk)begin

    if (we3 == 1'b1 && write_addr != 0)
        ram_array[write_addr] <= wd3;
end

assign dout1 = ram_array[read_addr1];
assign dout2 = ram_array[read_addr2];
assign a0 = ram_array[10];

endmodule
