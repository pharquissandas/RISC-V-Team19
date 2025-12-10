module dependencies_unit(
    
    input clk,
    input [4:0] RdD1,
    input [4:0] RdD2,
    input logic BranchD1,
    input logic BranchD2,
    //input [6:0] opcode1,
    //input [6:0] opcode2,

  
    output logic StallPipeline2,
    output logic StallPipeline1NC

);
   //PCNextNew1 = PCD2
        //PCNextNew2 = PCF2 -> implement with MUX in fetch stage 
        //StallPipeline1NC = 1'b1;//cycle after p2 is stalled we stall p1 and let p2 run

    // if(opcode1 == 7'b1100011 && opcode2 = 7'b1100011)begin //we have jumps/branches in both pipelines
    // //with branches in both pipelines, we stall the pipeline with the higher PC value
    // //we execute the pipeline with the lower PC value if the branch is taken we set the PC values correctly for both pipelines
    // //if its not taken we execute the branch in the pipeline which had the higher PC value as this would of been the next instruction
    // //but we must check that PC value in pipeline 2 is always equal to pipeline 1 pc + 4 or this design choice wont work

    //     if(PCD1 > PCD2)begin

    //         stall_p1 = 1'b1;


    //     end
    //     if(PCD2 > PCD1) begin
    //         stall_p2 = 1'b1;
    //     end

    // end

 
 
//havent considered dependency between source and destination registers in different pipelines, 

always_comb begin

    StallPipeline2 = 1'b0;


    if((RdD1 == RdD2) && !(BranchD1 || BranchD2) && !(RdD1 == 0 || RdD2 == 0))
        StallPipeline2 = 1'b1; // with a dependency we stall pipeline 2 first allow p1 to run
     
end


always_ff @(posedge clk)begin

    if(StallPipeline2)
        StallPipeline1NC <= 1'b1;
    else
        StallPipeline1NC <= 1'b0;

end


endmodule
