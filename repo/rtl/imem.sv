module imem (
    /* verilator lint_off UNUSED */
    input  logic [31:0] addr,    // byte address from the program counter (PC)
    output logic [31:0] instr    // 32-bit instruction read from memory
    /* verilator lint_on UNUSED */
);

    // instruction memory array: 256 instructions, each 32 bits wide
    logic [31:0] mem [0:255];

    // preload instructions from an external hex file at simulation start
    initial begin
        $readmemh("program.hex", mem);
    end

    // output the instruction corresponding to the PC address
    assign instr = mem[addr[9:2]]; 
endmodule
