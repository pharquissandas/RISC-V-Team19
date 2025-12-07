module dependencies_unit(

    input [4:0] RdD1,
    input [4:0] RdD2,
    input [31:0] PCD1,
    input [31:0] PCD2,
    input [31:0] PCF1,
    input [31:0] PCF2,



    
    output [31:0] PCNextNew1,    
    output StallPipeline2

);


always_comb begin

    StallPipeline2 = 1'b0;


    if(RdD1 == RdD2)
        StallPipeline2 = 1'b1;
        //PCNextNew1 = PCD2
        //PCNextNew2 = PCF2 -> implement with MUX in fetch stage 



end





endmodule
