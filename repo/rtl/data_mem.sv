module data_mem #(
    parameter DATA_WIDTH = 32,
              ADDRESS_WIDTH = 32
) (
    input  logic                        clk,
    input  logic                        en, // write enable
    input  logic [ADDRESS_WIDTH-1:0]    wr_addr, // memory address
    input  logic [DATA_WIDTH-1:0]       din, // data to write
    input logic [2:0]                   funct3, // for byte/halfword/word selection
    output logic [DATA_WIDTH-1:0]       dout // data read
);

    // 2^32 32-bit memory locations
    logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0];

    case(funct3)
        3'b000: begin // LB
            assign dout = {{24{ram_array[wr_addr][7]}}, ram_array[wr_addr][7:0]};
        end
        3'b001: begin // LH
            assign dout = {{16{ram_array[wr_addr][15]}}, ram_array[wr_addr][15:0]};
        end
        3'b010: begin // LW
            assign dout = ram_array[wr_addr];
        end
        3'b100: begin // LBU
            assign dout = {24'b0, ram_array[wr_addr][7:0]};
        end
        3'b101: begin // LHU
            assign dout = {16'b0, ram_array[wr_addr][15:0]};
        end
        default: begin
            assign dout = ram_array[wr_addr]; // read data from memory assynchronously

        end
    endcase
    
    always_ff @(posedge clk) begin
        if (en == 1'b1) begin
            case(funct3)
                3'b000: begin // SB
                    ram_array[wr_addr][7:0] <= din[7:0];
                end
                3'b001: begin // SH
                    ram_array[wr_addr][15:0] <= din[15:0];
                end
                3'b010: begin // SW
                    ram_array[wr_addr] <= din;
                end
                default: begin
                    ram_array[wr_addr] <= din; // write data to memory synchronously
                end
            endcase
        end
    end

endmodule