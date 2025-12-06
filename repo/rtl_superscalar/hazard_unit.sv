module hazard_unit(

    input logic [4:0] Rs1E, //source register from instruction in execution stage
    input logic [4:0] Rs2E, //source register from instruction in execution stage
    input logic [4:0] Rs1D, //source register from instruction in execution stage
    input logic [4:0] Rs2D, //source register from instruction in execution stage
    input logic [4:0] RdM1,  //destination register of an instruction in memory/writeback stage
    input logic [4:0] RdW1,  //destination register of an instruction in memory/writeback stage
    input logic [4:0] RdE1,  
    input logic RegWriteW1, //tells us whether destination register is actually written
    input logic RegWriteM1,  //tells us whether destination register is actually written
    
    input logic [1:0] ResultSrcE1, //to identify load instructions in execute stage
    input logic [1:0] PCSrcE1, //to identify control hazards in execute stage


    input logic [4:0] Rs4E, //source register from instruction in execution stage
    input logic [4:0] Rs5E, //source register from instruction in execution stage
    input logic [4:0] Rs4D, //source register from instruction in execution stage
    input logic [4:0] Rs5D, //source register from instruction in execution stage
    input logic [4:0] RdM2,  //destination register of an instruction in memory/writeback stage
    input logic [4:0] RdW2,  //destination register of an instruction in memory/writeback stage
    input logic [4:0] RdE2,  
    input logic RegWriteW2, //tells us whether destination register is actually written
    input logic RegWriteM2,  //tells us whether destination register is actually written
    
    input logic [1:0] ResultSrcE2, //to identify load instructions in execute stage
    input logic [1:0] PCSrcE2, //to identify control hazards in execute stage

    output logic [1:0] ForwardAE1, //these are select inputs for muxes, 00 means no forwarding, 01 means forwarding of result in writeback stage, 10 means forwarding of result from ALU in memory stage
    output logic [1:0] ForwardBE1,  //these are select inputs for muxes

    output logic [1:0] ForwardAE2, //these are select inputs for muxes, 00 means no forwarding, 01 means forwarding of result in writeback stage, 10 means forwarding of result from ALU in memory stage
    output logic [1:0] ForwardBE2,  //these are select inputs for muxes

    output logic StallDecode,
    output logic StallFetch,
    output logic StallExecute,

    output logic StallWriteback,
    output logic FlushExecute,
    output logic FlushDecode,

    
);

always_comb begin
    ForwardAE     = 2'b00;
    ForwardBE     = 2'b00;
    StallDecode   = 1'b0;
    StallFetch    = 1'b0;
    StallExecute  = 1'b0;
    //StallMemory   = 1'b0;
    StallWriteback= 1'b0;
    FlushExecute  = 1'b0;
    FlushDecode   = 1'b0;
    FlushWriteback= 1'b0;
    //pc_redirect_o = 1'b0;

    if(Rs1E == 5'b0) // register x0 is never forwarded
        ForwardAE = 2'b00;
    else if((Rs1E == RdM) && RegWriteM && Rs1E != 0)
        ForwardAE = 2'b10;
    else if((Rs1E == RdW) && RegWriteW && Rs1E != 0)
        ForwardAE = 2'b01;

    if(Rs2E == 5'b0) // register x0 is never forwarded
        ForwardBE = 2'b00;
    else if((Rs2E == RdM) &&  RegWriteM && Rs2E != 0)
        ForwardBE = 2'b10;
    else if((Rs2E == RdW) && RegWriteW && Rs2E != 0)
        ForwardBE = 2'b01;

    // ------stall logic------

    // unconditional jump control hazard (branch taken)
    else if (PCSrcE != 2'b00) begin
        FlushDecode = 1'b1;
        FlushExecute = 1'b1;
        // pc_redirect_o = 1'b1;
    end

    // load-use hazard (data hazard)
    else if (ResultSrcE == 2'b01 && (RdE != 0) && (RdE == Rs1D || RdE == Rs2D)) begin
        StallDecode = 1'b1;
        StallFetch = 1'b1;
        FlushExecute = 1'b1;
    end
end
endmodule
