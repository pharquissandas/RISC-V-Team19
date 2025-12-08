module execute(
    input logic [1:0]  JumpE1,
    input logic        BranchE1,
    input logic [3:0]  ALUControlE1,
    input logic        ALUSrcAE1,
    input logic        ALUSrcBE1,
    input logic [2:0]  BranchTypeE1,
    input logic [1:0]  JumpE2,
    input logic        BranchE2,
    input logic [3:0]  ALUControlE2,
    input logic        ALUSrcAE2,
    input logic        ALUSrcBE2,
    input logic [2:0]  BranchTypeE2,


    input logic [31:0] ResultW1,
    input logic [31:0] ALUResultM1,
    input logic [31:0] ResultW2,
    input logic [31:0] ALUResultM2,
    input logic [31:0] RD1E,
    input logic [31:0] RD2E,
    input logic [31:0] RD4E,
    input logic [31:0] RD5E,

    input logic [1:0] ForwardAE,
    input logic [1:0] ForwardBE,

    input logic [31:0] PCE1,
    input logic [31:0] PCE2,
    input logic [31:0] ImmExtE1,
    input logic [31:0] ImmExtE2,

    output logic [31:0] WriteDataE,
    output logic [1:0]  PCSrcE,
    output logic [31:0] ALUResultE,
    output logic [31:0] PCTargetE
);

    logic ZeroE1;
    logic ZeroE2;
    logic [31:0] SrcB, SrcA;
    logic [31:0] SrcBE1, SrcAE1. SrcAE2,SrcBE2;

    always_comb begin
        case (ForwardAE)
            2'b00: SrcA = RD1E;
            2'b01: SrcA = ResultW;
            2'b10: SrcA = ALUResultM;
            default: SrcA = RD1E;
        endcase

        case (ForwardBE)
            2'b00: SrcB = RD2E;
            2'b01: SrcB = ResultW;
            2'b10: SrcB = ALUResultM;
            default: SrcB = RD2E;
        endcase

        SrcAE = ALUSrcAE ? PCE : SrcA;
        SrcBE = ALUSrcBE ? ImmExtE : SrcB;

        PCTargetE1  = PCE1 + ImmExtE1;
        PCTargetE2  = PCE2 + ImmExtE2;

        WriteDataE1 = SrcB;
    end

    alu alu_inst1 (
        .SrcA (SrcAE1),
        .SrcB (SrcBE1),
        .ALUControl (ALUControlE1),
        
        .ALUResult (ALUResultE1),
        .Zero (ZeroE1)
    );

    alu alu_inst2(
        .SrcA(SrcAE2),
        .SrcB(SrcBE2),
        .ALUControl(ALUControlE2),

        .ALUResult(ALUResultE2),
        .zero(ZeroE2)

    );

    pcsrc_unit pcsrc_unit_inst1 (
        .Jump (JumpE1),
        .Branch (BranchE1),
        .Zero(ZeroE1),
        .BranchType (BranchTypeE1),
        
        .PCSrc (PCSrcE1)
    );

    pcsrc_unit pcsrc_unit_inst2 (
        .Jump (JumpE2),
        .Branch (BranchE2),
        .Zero(ZeroE2),
        .BranchType (BranchTypeE2),
        
        .PCSrc (PCSrcE2)
    );

    // branch prediction and bht update signals
    assign execute_is_branch_o = BranchE && (JumpE == 2'b00);
    assign execute_branch_taken_o = execute_is_branch_o && (PCSrcE == 2'b01);

    // misprediction detection
    always_comb begin
        branch_mispredict_o = 1'b0;
        mispredict_target_pc_o = 32'b0; 

        // only check for misprediction on conditional branches
        if (execute_is_branch_o) begin
            // check if actual outcome differs from predicted outcome
            if (execute_branch_taken_o != predict_taken_i) begin
                branch_mispredict_o = 1'b1;
                // determine correct target PC
                if (execute_branch_taken_o) begin
                    mispredict_target_pc_o = PCTargetE; // branch taken
                end
                else begin
                    mispredict_target_pc_o = PCE + 4; // branch not taken
                end
            end
        end
    end
endmodule
