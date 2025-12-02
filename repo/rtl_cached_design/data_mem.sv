module data_mem #(
    parameter XLEN = 32,
    parameter ADDRESS_WIDTH = 17,
    parameter DATA_WIDTH = 8
) (
    input  logic clk,
    input  logic WE, // write enable
    // verilator lint_off UNUSED
    input  logic [XLEN-1:0] A, // memory address
    // verilator lint_on UNUSED
    input  logic [XLEN-1:0] WD, // data to write
    input  logic [2:0] AddressingControl, // funct3 to determine load/store type
    output logic [XLEN-1:0] RD // data read
);
    logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0]; // 128KB data memory

    initial begin
        // Load the data.hex file into memory at the start of simulation (starts from middle of memory)
        $readmemh("data.hex", ram_array);
    end

    logic [ADDRESS_WIDTH-1:0] addr;
    assign addr = A[ADDRESS_WIDTH-1:0]; // use lower ADDRESS_WIDTH bits of address

    always_ff @(posedge clk) begin
        if (WE) begin
            case (AddressingControl)
                3'b000: ram_array[addr] <= WD[7:0]; // SB
                3'b001: begin                      // SH
                    ram_array[addr]   <= WD[7:0];
                    ram_array[addr+1] <= WD[15:8];
                end
                3'b010: begin                      // SW
                    ram_array[addr]   <= WD[7:0];
                    ram_array[addr+1] <= WD[15:8];
                    ram_array[addr+2] <= WD[23:16];
                    ram_array[addr+3] <= WD[31:24];
                end
                default: ; // ignore other funct3
            endcase
        end
    end

    logic [ADDRESS_WIDTH-1:0] word_addr;
    assign word_addr = {addr[ADDRESS_WIDTH-1:2], 2'b00}; // align bytes as LB LH LW logic handled in cache

    always_comb begin // return word
        RD = {ram_array[word_addr+3], ram_array[word_addr+2], ram_array[word_addr+1], ram_array[word_addr]};
    end


endmodule
