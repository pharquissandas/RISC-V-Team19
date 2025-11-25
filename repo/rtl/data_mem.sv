module data_mem #(
    parameter DATA_WIDTH = 32,
              ADDRESS_WIDTH = 32
) (
    input  logic                        clk,
    input  logic                        en, // write enable
    input  logic [ADDRESS_WIDTH-1:0]    wr_addr, // memory address
    input  logic [DATA_WIDTH-1:0]       din, // data to write
    output logic [DATA_WIDTH-1:0]       dout // data read
);

    // 2^32 32-bit memory locations
    logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];
    
    assign dout = ram_array[wr_addr]; // read data from memory assynchronously

    always_ff @(posedge clk) begin
        if (en == 1'b1) begin
            ram_array[wr_addr] <= din; // write data to memory synchronously
        end
    end

endmodule