// for 4096 byte capacity cache: 2048 byte per way, 512 sets, 9 bit set

module memory_unit #(
    parameter XLEN = 32
) (
    input  logic clk,
    input  logic WE,
    input  logic [XLEN-1:0] A,
    input  logic [XLEN-1:0] WD,
    input  logic [2:0] AddressingControl,
    output logic [XLEN-1:0] RD,
);

logic [20:0] tag;
logic [8:0] set;
logic [1:0] byte_offset;

// WAY 0 ARRAYS
logic        v_way0    [511:0]; // valid bit
logic        d_way0    [511:0]; // dirty bit
logic [20:0] tag_way0  [511:0]; // tag
logic [31:0] data_way0 [511:0]; // data
// WAY 1 ARRAYS
logic        v_way1    [511:0]; // valid bit
logic        d_way1    [511:0]; // dirty bit
logic [20:0] tag_way1  [511:0]; // tag
logic [31:0] data_way1 [511:0]; // data

logic u_bit [511:0] // 0 = way0 accessed most recently, 1 = way1 accessed most recently

logic hit0; // way 0 hit
logic hit1; // way 1 hit
logic hit;

logic [31:0] selected_word;
logic [31:0] ram_data;
logic [31:0] ram_write;
logic ram_write_en;

// clear cache valid bits on startup
initial begin
    for (int i = 0; i < 512; i++) begin
        v_way0[i] = 0;
        v_way1[i] = 0;
        u_bit [i] = 0;
        d_way0[i] = 0;
        d_way1[i] = 0;
    end
end

assign tag = A[31:11];
assign set = A[10:2];
assign byte_offset = A[1:0];

assign hit0 = v_way0[set] && (tag_way0[set] == tag_in);
assign hit1 = v_way1[set] && (tag_way1[set] == tag_in);
assign hit  = hit0 || hit1;

always_comb begin
    if (hit0) begin
        selected_word = data_way0[set];
    end
    if (hit1) begin
        selected_word = data_way1[set];
    end
    else begin
        selected_word = ram_array;
    end

    case (AddressingControl)
        3'b000: begin // LB (signed)
            case(byte_offset)
                2'b00: RD = {{24{selected_word[7]}},  selected_word[7:0]};
                2'b01: RD = {{24{selected_word[15]}}, selected_word[15:8]};
                2'b10: RD = {{24{selected_word[23]}}, selected_word[23:16]};
                2'b11: RD = {{24{selected_word[31]}}, selected_word[31:24]};
            endcase
        end
        3'b001: begin // LH (signed)
            case(byte_offset[1]) // check bit 1 (0 or 2)
                1'b0: RD = {{16{selected_word[15]}}, selected_word[15:0]};
                1'b1: RD = {{16{selected_word[31]}}, selected_word[31:16]};
            endcase
        end
        3'b010: RD = selected_word; // LW
        3'b100: begin // LBU (unsigned)
            case(byte_offset)
                2'b00: RD = {24'b0, selected_word[7:0]};
                2'b01: RD = {24'b0, selected_word[15:8]};
                2'b10: RD = {24'b0, selected_word[23:16]};
                2'b11: RD = {24'b0, selected_word[31:24]};
            endcase
        end
        3'b101: begin // LHU (unsigned)
            case(byte_offset[1])
                1'b0: RD = {16'b0, selected_word[15:0]};
                1'b1: RD = {16'b0, selected_word[31:16]};
            endcase
        end
        default: RD = 32'b0;
    endcase

end

always_ff @(posedge clk) begin
    // write: on a hit write to cache and set dirty bit true 
    if (WE) begin
        if (hit0) begin
            data_way0[set] <= WD;
            u_bit[set]  <= 0;
            d_way0[set] <= 1;
        else if (hit1)
            data_way1[set] <= WD;
            u_bit[set]  <= 1;
            d_way1[set] <= 1;
        end
    end
    // on a read miss, bring data from ram to cache
    else if (hit == 0) begin
        ram_write_en <= 0;
        if (u_bit[set] == 1) begin // 1 most recently used so load into 0

            // if(d_way0[set] == 1) begin // write data from cache to memory before getting evicted 
            //     ram_write_en <= 1;
            //     ram_write <= data_way0[set];
            // end
            
            data_way0[set] <= ram_data;
            tag_way0[set]  <= tag;
            v_way0[set] <= 1;
            d_way0[set] <= 0;
            u_bit[set]  <= 0; // way 0 most recently used
        end
        else begin // 0 most recently used so load into 1

            // if(d_way1[set] == 1) begin // write data from cache to memory before getting evicted 
            //     ram_write_en <= 1;
            //     ram_write <= data_way1[set];
            // end

            data_way1[set] <= ram_data;
            tag_way1[set]  <= tag;
            v_way1[set] <= 1;
            d_way1[set] <= 0;
            u_bit[set]  <= 1; // way 1 most recently used
        end
    end
    else begin // read hit: update
        if (hit0) begin
            u_bit[set] <= 0;
        end
        if (hit1) begin
            u_bit[set] <= 1;
        end
    end
end

data_mem main_mem_inst (
    .clk(clk),
    .WE(ram_write_en),
    .A(A),
    .WD(ram_write),
    .AddressingControl(AddressingControl),
    .RD(ram_rd)
);

endmodule