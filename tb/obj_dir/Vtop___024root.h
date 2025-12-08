// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"

class Vtop__Syms;

class Vtop___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(rst,0,0);
    VL_IN8(trigger,0,0);
    CData/*1:0*/ top__DOT__PCSrc;
    CData/*0:0*/ top__DOT__RegWrite;
    CData/*3:0*/ top__DOT__ALUControl;
    CData/*0:0*/ top__DOT__ALUSrcA;
    CData/*0:0*/ top__DOT__ALUSrcB;
    CData/*0:0*/ top__DOT__MemWrite;
    CData/*1:0*/ top__DOT__ResultSrc;
    CData/*2:0*/ top__DOT__ImmSrc;
    CData/*2:0*/ top__DOT__AddressingControl;
    CData/*0:0*/ top__DOT__Zero;
    CData/*0:0*/ top__DOT__ctrl_inst__DOT__Branch;
    CData/*2:0*/ top__DOT__ctrl_inst__DOT__BranchType;
    CData/*1:0*/ top__DOT__ctrl_inst__DOT__Jump;
    CData/*0:0*/ __Vclklast__TOP__clk;
    VL_OUT(a0,31,0);
    IData/*31:0*/ top__DOT__Instr;
    IData/*31:0*/ top__DOT__dp_inst__DOT__PC;
    IData/*31:0*/ top__DOT__dp_inst__DOT__PCPlus4;
    IData/*31:0*/ top__DOT__dp_inst__DOT__ImmExt;
    IData/*31:0*/ top__DOT__dp_inst__DOT__MemData;
    IData/*31:0*/ top__DOT__dp_inst__DOT__ALUResult;
    IData/*31:0*/ top__DOT__dp_inst__DOT__SrcA;
    IData/*31:0*/ top__DOT__dp_inst__DOT__SrcB;
    IData/*31:0*/ top__DOT__dp_inst__DOT__ReadData2;
    IData/*31:0*/ top__DOT__dp_inst__DOT__pc_inst__DOT__PCNext;
    IData/*31:0*/ top__DOT__dp_inst__DOT__pc_inst__DOT__PCTarget;
    VlUnpacked<IData/*31:0*/, 4096> top__DOT__dp_inst__DOT__instr_mem_inst__DOT__rom_array;
    VlUnpacked<CData/*7:0*/, 131072> top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array;
    VlUnpacked<IData/*31:0*/, 32> top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array;
    VlUnpacked<CData/*0:0*/, 2> __Vm_traceActivity;

    // INTERNAL VARIABLES
    Vtop__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* name);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
} VL_ATTR_ALIGNED(VL_CACHE_LINE_BYTES);


#endif  // guard
