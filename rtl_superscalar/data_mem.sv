module data_mem #(
    parameter XLEN = 32,
    parameter ADDRESS_WIDTH = 17,
    parameter DATA_WIDTH = 8
) (
    input  logic clk,
    input  logic WE1, // write enable
    input  logic WE2, // write enable

    // verilator lint_off UNUSED
    input  logic [XLEN-1:0] A1, // memory address
    // verilator lint_on UNUSED
    input  logic [XLEN-1:0] A2, // memory address
    input  logic [XLEN-1:0] WD1, // data to write
    input  logic [XLEN-1:0] WD2, // data to write
    output logic [XLEN-1:0] RD1, // data read
    output logic [XLEN-1:0] RD2 // data read

);
    logic [DATA_WIDTH-1:0] ram_array [2**ADDRESS_WIDTH-1:0]; // 128KB data memory

    initial begin
        // Load the data.hex file into memory at the start of simulation (starts from middle of memory)
        $readmemh("data.hex", ram_array);
    end

    logic [ADDRESS_WIDTH-1:0] addr1;
    logic [ADDRESS_WIDTH-1:0] addr2;
    assign addr1 = A1[ADDRESS_WIDTH-1:0]; // use lower ADDRESS_WIDTH bits of address
    assign addr2 = A2[ADDRESS_WIDTH-1:0]; // use lower ADDRESS_WIDTH bits of address

    always_comb begin

        if (addr1 == addr2)
            //stall ?
            //allow pipeline 2 to write as it was going to be next instruction
            //this would not work for out of order though?
    end


    always_ff @(posedge clk) begin
        // always write full word otherwise data bits will be lost and SW SH SB logic is done
        // after the data is then recieved from the cache in memory_unit
        if (WE1) begin
            ram_array[addr1]   <= WD1[7:0];
            ram_array[addr1+1] <= WD1[15:8];
            ram_array[addr1+2] <= WD1[23:16];
            ram_array[addr1+3] <= WD1[31:24];
        end
        else if (WE2) begin //what happens if both trying to write same memory??????
            ram_array[addr2]   <= WD2[7:0];
            ram_array[addr2+1] <= WD2[15:8];
            ram_array[addr2+2] <= WD2[23:16];
            ram_array[addr2+3] <= WD2[31:24];
        end
    end

    logic [ADDRESS_WIDTH-1:0] word_addr1;
    logic [ADDRESS_WIDTH-1:0] word_addr2;
    
    assign word_addr1 = {addr1[ADDRESS_WIDTH-1:2], 2'b00}; // align bytes as LB LH LW logic handled in cache
    assign word_addr2 = {addr2[ADDRESS_WIDTH-1:2], 2'b00}; // align bytes as LB LH LW logic handled in cache


    always_comb begin // return word
        RD1 = {ram_array[word_addr1+3], ram_array[word_addr1+2], ram_array[word_addr1+1], ram_array[word_addr1]};
        RD2 = {ram_array[word_addr2+3], ram_array[word_addr2+2], ram_array[word_addr2+1], ram_array[word_addr2]};
    end


endmodule
