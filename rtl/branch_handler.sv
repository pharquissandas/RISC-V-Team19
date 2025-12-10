module branch_handler(

    input logic BranchE1,
    input logic BranchE2,
    input logic [31:0] PCD1,
    input logic [31:0] PCD2,


    output logic StallFetch1,
    output logic StallFetch2,
    output logic StallExecute1,    
    output logic StallExecute2


);

endmodule

//(//in decode block we have identified that we have branches in both cycles
// we will stall fetch blocks of both pipelines in next cycle
// in next cycle we will execute only the instruction that has the lower PC, so we need to stall
// the execution of the other pipeline
// at the end of the execution stage we know if the branch is taken
// if it is then we set the PCNext values for both pipelines correctly and unstall

//if its not taken we need to continue stalling fetch, now we stall execution of pipeline with lower PC
//and run the execution of that with the higher PC to evaluate the branch
//then we set the PCs as required)//

// if we have a branch in both
// we execute both at the end of execution if both are taken
// we only set the PC values to the values that result from the branch from the lower PC instruction
//

always_comb begin

    if(BranchE1 && BranchE2)begin

        if(PCD1 < PCD2)begin

            StallFetch1 = 1'b1;
            StallFetch2 = 1'b1;            

            StallExecute2 = 1'b1;

        end




    end

end