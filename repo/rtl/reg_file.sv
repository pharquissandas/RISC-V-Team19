module reg_file #(
    parameter   ADDRESS_WIDTH = 5,      // 32 registers
                DATA_WIDTH    = 32      // 32-bits
)(
    input  logic                        clk,          // clock
    input  logic [ADDRESS_WIDTH-1:0]    write_addr,   // destination register 
    input  logic [ADDRESS_WIDTH-1:0]    read_addr1,   // source register 1 address (rs1)
    input  logic [ADDRESS_WIDTH-1:0]    read_addr2,   // source register 2 address (rs2)
    input  logic [DATA_WIDTH-1:0]       wd3,          // write data
    input  logic                        we3,          // write enable
    output logic [DATA_WIDTH-1:0]       dout1,        // register file output for rs1
    output logic [DATA_WIDTH-1:0]       dout2,        // register file output for rs2
    output logic [DATA_WIDTH-1:0]       a0            // special output for register x10 (a0)
);

// 32 32-bit registers
logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

// write operation (synchronous) -> writes occur only if we3 is asserted
always_ff @(posedge clk) begin
    if (we3 == 1'b1 && write_addr != 0)
        ram_array[write_addr] <= wd3;
end

// read operations (combinational) -> outputs change immediately when read_addr changes
assign dout1 = ram_array[read_addr1];
assign dout2 = ram_array[read_addr2];

// special readout of x10 (a0)
assign a0 = ram_array[10];

endmodule
