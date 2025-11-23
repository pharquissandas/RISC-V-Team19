module imem (
    /* verilator lint_off UNUSED */
    input  logic [31:0] addr,
    output logic [31:0] instr
    /* verilator lint_on UNUSED */
);

    logic [31:0] mem [0:255];

    initial begin
        $readmemh("../rtl/program.hex", mem);
    end

    assign instr = mem[addr[9:2]]; 
endmodule
