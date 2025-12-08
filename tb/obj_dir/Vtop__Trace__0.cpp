// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals
#include "verilated_vcd_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void Vtop___024root__trace_chg_top_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_top_0\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    // Body
    Vtop___024root__trace_chg_sub_0((&vlSymsp->TOP), bufp);
}

void Vtop___024root__trace_chg_sub_0(Vtop___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_sub_0\n"); );
    // Init
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 1);
    // Body
    if (VL_UNLIKELY(vlSelf->__Vm_traceActivity[1U])) {
        bufp->chgCData(oldp+0,(vlSelf->top__DOT__PCSrc),2);
        bufp->chgBit(oldp+1,(vlSelf->top__DOT__RegWrite));
        bufp->chgCData(oldp+2,(vlSelf->top__DOT__ALUControl),4);
        bufp->chgBit(oldp+3,(vlSelf->top__DOT__ALUSrcA));
        bufp->chgBit(oldp+4,(vlSelf->top__DOT__ALUSrcB));
        bufp->chgBit(oldp+5,(vlSelf->top__DOT__MemWrite));
        bufp->chgCData(oldp+6,(vlSelf->top__DOT__ResultSrc),2);
        bufp->chgCData(oldp+7,(vlSelf->top__DOT__ImmSrc),3);
        bufp->chgCData(oldp+8,(vlSelf->top__DOT__AddressingControl),3);
        bufp->chgBit(oldp+9,(vlSelf->top__DOT__Zero));
        bufp->chgIData(oldp+10,(vlSelf->top__DOT__Instr),32);
        bufp->chgBit(oldp+11,(vlSelf->top__DOT__ctrl_inst__DOT__Branch));
        bufp->chgCData(oldp+12,(vlSelf->top__DOT__ctrl_inst__DOT__BranchType),3);
        bufp->chgCData(oldp+13,(vlSelf->top__DOT__ctrl_inst__DOT__Jump),2);
        bufp->chgCData(oldp+14,((0x7fU & vlSelf->top__DOT__Instr)),7);
        bufp->chgCData(oldp+15,((7U & (vlSelf->top__DOT__Instr 
                                       >> 0xcU))),3);
        bufp->chgCData(oldp+16,((vlSelf->top__DOT__Instr 
                                 >> 0x19U)),7);
        bufp->chgIData(oldp+17,(vlSelf->top__DOT__dp_inst__DOT__PC),32);
        bufp->chgIData(oldp+18,(vlSelf->top__DOT__dp_inst__DOT__PCPlus4),32);
        bufp->chgIData(oldp+19,(vlSelf->top__DOT__dp_inst__DOT__ImmExt),32);
        bufp->chgIData(oldp+20,(vlSelf->top__DOT__dp_inst__DOT__MemData),32);
        bufp->chgIData(oldp+21,(vlSelf->top__DOT__dp_inst__DOT__ALUResult),32);
        bufp->chgIData(oldp+22,(vlSelf->top__DOT__dp_inst__DOT__SrcA),32);
        bufp->chgIData(oldp+23,(vlSelf->top__DOT__dp_inst__DOT__SrcB),32);
        bufp->chgIData(oldp+24,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array
                                [(0x1fU & (vlSelf->top__DOT__Instr 
                                           >> 0xfU))]),32);
        bufp->chgIData(oldp+25,(vlSelf->top__DOT__dp_inst__DOT__ReadData2),32);
        bufp->chgIData(oldp+26,(((0U == (IData)(vlSelf->top__DOT__ResultSrc))
                                  ? vlSelf->top__DOT__dp_inst__DOT__ALUResult
                                  : ((1U == (IData)(vlSelf->top__DOT__ResultSrc))
                                      ? vlSelf->top__DOT__dp_inst__DOT__MemData
                                      : ((2U == (IData)(vlSelf->top__DOT__ResultSrc))
                                          ? vlSelf->top__DOT__dp_inst__DOT__PCPlus4
                                          : 0U)))),32);
        bufp->chgIData(oldp+27,((0x1ffffU & vlSelf->top__DOT__dp_inst__DOT__ALUResult)),17);
        bufp->chgIData(oldp+28,(vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCNext),32);
        bufp->chgIData(oldp+29,(vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCTarget),32);
        bufp->chgCData(oldp+30,((0x1fU & (vlSelf->top__DOT__Instr 
                                          >> 7U))),5);
        bufp->chgCData(oldp+31,((0x1fU & (vlSelf->top__DOT__Instr 
                                          >> 0xfU))),5);
        bufp->chgCData(oldp+32,((0x1fU & (vlSelf->top__DOT__Instr 
                                          >> 0x14U))),5);
        bufp->chgIData(oldp+33,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[0]),32);
        bufp->chgIData(oldp+34,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[1]),32);
        bufp->chgIData(oldp+35,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[2]),32);
        bufp->chgIData(oldp+36,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[3]),32);
        bufp->chgIData(oldp+37,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[4]),32);
        bufp->chgIData(oldp+38,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[5]),32);
        bufp->chgIData(oldp+39,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[6]),32);
        bufp->chgIData(oldp+40,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[7]),32);
        bufp->chgIData(oldp+41,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[8]),32);
        bufp->chgIData(oldp+42,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[9]),32);
        bufp->chgIData(oldp+43,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[10]),32);
        bufp->chgIData(oldp+44,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[11]),32);
        bufp->chgIData(oldp+45,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[12]),32);
        bufp->chgIData(oldp+46,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[13]),32);
        bufp->chgIData(oldp+47,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[14]),32);
        bufp->chgIData(oldp+48,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[15]),32);
        bufp->chgIData(oldp+49,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[16]),32);
        bufp->chgIData(oldp+50,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[17]),32);
        bufp->chgIData(oldp+51,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[18]),32);
        bufp->chgIData(oldp+52,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[19]),32);
        bufp->chgIData(oldp+53,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[20]),32);
        bufp->chgIData(oldp+54,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[21]),32);
        bufp->chgIData(oldp+55,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[22]),32);
        bufp->chgIData(oldp+56,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[23]),32);
        bufp->chgIData(oldp+57,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[24]),32);
        bufp->chgIData(oldp+58,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[25]),32);
        bufp->chgIData(oldp+59,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[26]),32);
        bufp->chgIData(oldp+60,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[27]),32);
        bufp->chgIData(oldp+61,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[28]),32);
        bufp->chgIData(oldp+62,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[29]),32);
        bufp->chgIData(oldp+63,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[30]),32);
        bufp->chgIData(oldp+64,(vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[31]),32);
        bufp->chgIData(oldp+65,((vlSelf->top__DOT__Instr 
                                 >> 7U)),25);
    }
    bufp->chgBit(oldp+66,(vlSelf->clk));
    bufp->chgBit(oldp+67,(vlSelf->rst));
    bufp->chgIData(oldp+68,(vlSelf->a0),32);
    bufp->chgBit(oldp+69,(vlSelf->trigger));
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Init
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    // Body
    vlSymsp->__Vm_activity = false;
    vlSymsp->TOP.__Vm_traceActivity[0U] = 0U;
    vlSymsp->TOP.__Vm_traceActivity[1U] = 0U;
}
