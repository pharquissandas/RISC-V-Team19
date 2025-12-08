// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h8fccedee_0;

VL_INLINE_OPT void Vtop___024root___sequent__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___sequent__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1;
    CData/*0:0*/ __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3;
    CData/*0:0*/ __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5;
    IData/*16:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6;
    CData/*7:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6;
    CData/*4:0*/ __Vdlyvdim0__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0;
    IData/*31:0*/ __Vdlyvval__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0;
    CData/*0:0*/ __Vdlyvset__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0;
    // Body
    __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0 = 0U;
    __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1 = 0U;
    __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3 = 0U;
    __Vdlyvset__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0 = 0U;
    if (vlSelf->top__DOT__MemWrite) {
        if ((0U == (IData)(vlSelf->top__DOT__AddressingControl))) {
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0 
                = (0xffU & vlSelf->top__DOT__dp_inst__DOT__ReadData2);
            __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0 = 1U;
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0 
                = (0x1ffffU & vlSelf->top__DOT__dp_inst__DOT__ALUResult);
        } else if ((1U == (IData)(vlSelf->top__DOT__AddressingControl))) {
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1 
                = (0xffU & vlSelf->top__DOT__dp_inst__DOT__ReadData2);
            __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1 = 1U;
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1 
                = (0x1ffffU & vlSelf->top__DOT__dp_inst__DOT__ALUResult);
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2 
                = (0xffU & (vlSelf->top__DOT__dp_inst__DOT__ReadData2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__dp_inst__DOT__ALUResult));
        } else if ((2U == (IData)(vlSelf->top__DOT__AddressingControl))) {
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3 
                = (0xffU & vlSelf->top__DOT__dp_inst__DOT__ReadData2);
            __Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3 = 1U;
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3 
                = (0x1ffffU & vlSelf->top__DOT__dp_inst__DOT__ALUResult);
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4 
                = (0xffU & (vlSelf->top__DOT__dp_inst__DOT__ReadData2 
                            >> 8U));
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4 
                = (0x1ffffU & ((IData)(1U) + vlSelf->top__DOT__dp_inst__DOT__ALUResult));
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5 
                = (0xffU & (vlSelf->top__DOT__dp_inst__DOT__ReadData2 
                            >> 0x10U));
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5 
                = (0x1ffffU & ((IData)(2U) + vlSelf->top__DOT__dp_inst__DOT__ALUResult));
            __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6 
                = (vlSelf->top__DOT__dp_inst__DOT__ReadData2 
                   >> 0x18U);
            __Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6 
                = (0x1ffffU & ((IData)(3U) + vlSelf->top__DOT__dp_inst__DOT__ALUResult));
        }
    }
    if (((IData)(vlSelf->top__DOT__RegWrite) & (0U 
                                                != 
                                                (0x1fU 
                                                 & (vlSelf->top__DOT__Instr 
                                                    >> 7U))))) {
        __Vdlyvval__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0 
            = ((0U == (IData)(vlSelf->top__DOT__ResultSrc))
                ? vlSelf->top__DOT__dp_inst__DOT__ALUResult
                : ((1U == (IData)(vlSelf->top__DOT__ResultSrc))
                    ? vlSelf->top__DOT__dp_inst__DOT__MemData
                    : ((2U == (IData)(vlSelf->top__DOT__ResultSrc))
                        ? vlSelf->top__DOT__dp_inst__DOT__PCPlus4
                        : 0U)));
        __Vdlyvset__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0 = 1U;
        __Vdlyvdim0__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0 
            = (0x1fU & (vlSelf->top__DOT__Instr >> 7U));
    }
    vlSelf->top__DOT__dp_inst__DOT__PC = ((IData)(vlSelf->rst)
                                           ? 0U : vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCNext);
    if (__Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0) {
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v0;
    }
    if (__Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1) {
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v1;
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v2;
    }
    if (__Vdlyvset__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3) {
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v3;
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v4;
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v5;
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array__v6;
    }
    if (__Vdlyvset__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0) {
        vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[__Vdlyvdim0__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0] 
            = __Vdlyvval__top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array__v0;
    }
    vlSelf->a0 = vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array
        [0xaU];
    vlSelf->top__DOT__Instr = vlSelf->top__DOT__dp_inst__DOT__instr_mem_inst__DOT__rom_array
        [(0xfffU & (vlSelf->top__DOT__dp_inst__DOT__PC 
                    >> 2U))];
    vlSelf->top__DOT__RegWrite = 0U;
    vlSelf->top__DOT__MemWrite = 0U;
    vlSelf->top__DOT__ResultSrc = 0U;
    vlSelf->top__DOT__AddressingControl = 0U;
    vlSelf->top__DOT__ctrl_inst__DOT__Branch = 0U;
    vlSelf->top__DOT__ctrl_inst__DOT__BranchType = 0U;
    vlSelf->top__DOT__ctrl_inst__DOT__Jump = 0U;
    vlSelf->top__DOT__ALUControl = 0U;
    vlSelf->top__DOT__ALUSrcB = 0U;
    vlSelf->top__DOT__dp_inst__DOT__ReadData2 = vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array
        [(0x1fU & (vlSelf->top__DOT__Instr >> 0x14U))];
    vlSelf->top__DOT__ALUSrcA = 0U;
    if ((1U & (~ (vlSelf->top__DOT__Instr >> 6U)))) {
        if ((0x20U & vlSelf->top__DOT__Instr)) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__Instr 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__MemWrite = 1U;
                                vlSelf->top__DOT__AddressingControl 
                                    = (7U & (vlSelf->top__DOT__Instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        } else {
            if ((0x10U & vlSelf->top__DOT__Instr)) {
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 3U)))) {
                    if ((4U & vlSelf->top__DOT__Instr)) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__MemWrite = 0U;
                            }
                        }
                    }
                }
            }
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 4U)))) {
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__Instr 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__AddressingControl 
                                    = (7U & (vlSelf->top__DOT__Instr 
                                             >> 0xcU));
                            }
                        }
                    }
                }
            }
        }
        if ((1U & (~ (vlSelf->top__DOT__Instr >> 5U)))) {
            if ((0x10U & vlSelf->top__DOT__Instr)) {
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 3U)))) {
                    if ((4U & vlSelf->top__DOT__Instr)) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__ALUSrcA = 1U;
                            }
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__ImmSrc = 0U;
    if ((0x40U & vlSelf->top__DOT__Instr)) {
        if ((0x20U & vlSelf->top__DOT__Instr)) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 4U)))) {
                if ((8U & vlSelf->top__DOT__Instr)) {
                    if ((4U & vlSelf->top__DOT__Instr)) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__RegWrite = 1U;
                                vlSelf->top__DOT__ResultSrc = 2U;
                                vlSelf->top__DOT__ctrl_inst__DOT__Jump = 1U;
                                vlSelf->top__DOT__ImmSrc = 3U;
                            }
                        }
                    }
                } else if ((4U & vlSelf->top__DOT__Instr)) {
                    if ((2U & vlSelf->top__DOT__Instr)) {
                        if ((1U & vlSelf->top__DOT__Instr)) {
                            vlSelf->top__DOT__RegWrite = 1U;
                            vlSelf->top__DOT__ResultSrc = 2U;
                            vlSelf->top__DOT__ctrl_inst__DOT__Jump = 2U;
                            vlSelf->top__DOT__ImmSrc = 0U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Instr)) {
                    if ((1U & vlSelf->top__DOT__Instr)) {
                        vlSelf->top__DOT__ImmSrc = 2U;
                    }
                }
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 3U)))) {
                    if ((1U & (~ (vlSelf->top__DOT__Instr 
                                  >> 2U)))) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__ctrl_inst__DOT__Branch = 1U;
                                vlSelf->top__DOT__ctrl_inst__DOT__BranchType 
                                    = (7U & (vlSelf->top__DOT__Instr 
                                             >> 0xcU));
                                vlSelf->top__DOT__ALUControl 
                                    = ((0x4000U & vlSelf->top__DOT__Instr)
                                        ? ((0x2000U 
                                            & vlSelf->top__DOT__Instr)
                                            ? 9U : 8U)
                                        : ((0x2000U 
                                            & vlSelf->top__DOT__Instr)
                                            ? 0U : 1U));
                            }
                        }
                    }
                    if ((4U & vlSelf->top__DOT__Instr)) {
                        if ((2U & vlSelf->top__DOT__Instr)) {
                            if ((1U & vlSelf->top__DOT__Instr)) {
                                vlSelf->top__DOT__ALUSrcB = 1U;
                            }
                        }
                    }
                }
            }
        }
    } else if ((0x20U & vlSelf->top__DOT__Instr)) {
        if ((0x10U & vlSelf->top__DOT__Instr)) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 3U)))) {
                if ((4U & vlSelf->top__DOT__Instr)) {
                    if ((2U & vlSelf->top__DOT__Instr)) {
                        if ((1U & vlSelf->top__DOT__Instr)) {
                            vlSelf->top__DOT__RegWrite = 1U;
                            vlSelf->top__DOT__ResultSrc = 0U;
                            vlSelf->top__DOT__ALUControl = 0xfU;
                            vlSelf->top__DOT__ALUSrcB = 1U;
                            vlSelf->top__DOT__ImmSrc = 4U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Instr)) {
                    if ((1U & vlSelf->top__DOT__Instr)) {
                        vlSelf->top__DOT__RegWrite = 1U;
                        vlSelf->top__DOT__ALUControl 
                            = ((0x4000U & vlSelf->top__DOT__Instr)
                                ? ((0x2000U & vlSelf->top__DOT__Instr)
                                    ? ((0x1000U & vlSelf->top__DOT__Instr)
                                        ? 2U : 3U) : 
                                   ((0x1000U & vlSelf->top__DOT__Instr)
                                     ? ((0U == (vlSelf->top__DOT__Instr 
                                                >> 0x19U))
                                         ? 6U : ((0x20U 
                                                  == 
                                                  (vlSelf->top__DOT__Instr 
                                                   >> 0x19U))
                                                  ? 7U
                                                  : 6U))
                                     : 4U)) : ((0x2000U 
                                                & vlSelf->top__DOT__Instr)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__Instr)
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__Instr)
                                                    ? 5U
                                                    : 
                                                   ((0U 
                                                     == 
                                                     (vlSelf->top__DOT__Instr 
                                                      >> 0x19U))
                                                     ? 0U
                                                     : 
                                                    ((0x20U 
                                                      == 
                                                      (vlSelf->top__DOT__Instr 
                                                       >> 0x19U))
                                                      ? 1U
                                                      : 0U)))));
                        vlSelf->top__DOT__ALUSrcB = 0U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__Instr 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 2U)))) {
                if ((2U & vlSelf->top__DOT__Instr)) {
                    if ((1U & vlSelf->top__DOT__Instr)) {
                        vlSelf->top__DOT__ALUControl = 0U;
                        vlSelf->top__DOT__ALUSrcB = 1U;
                        vlSelf->top__DOT__ImmSrc = 1U;
                    }
                }
            }
        }
    } else {
        if ((0x10U & vlSelf->top__DOT__Instr)) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 3U)))) {
                if ((4U & vlSelf->top__DOT__Instr)) {
                    if ((2U & vlSelf->top__DOT__Instr)) {
                        if ((1U & vlSelf->top__DOT__Instr)) {
                            vlSelf->top__DOT__RegWrite = 1U;
                            vlSelf->top__DOT__ALUControl = 0U;
                            vlSelf->top__DOT__ALUSrcB = 1U;
                            vlSelf->top__DOT__ImmSrc = 4U;
                        }
                    }
                } else if ((2U & vlSelf->top__DOT__Instr)) {
                    if ((1U & vlSelf->top__DOT__Instr)) {
                        vlSelf->top__DOT__RegWrite = 1U;
                        vlSelf->top__DOT__ALUControl 
                            = ((0x4000U & vlSelf->top__DOT__Instr)
                                ? ((0x2000U & vlSelf->top__DOT__Instr)
                                    ? ((0x1000U & vlSelf->top__DOT__Instr)
                                        ? 2U : 3U) : 
                                   ((0x1000U & vlSelf->top__DOT__Instr)
                                     ? ((0U == (vlSelf->top__DOT__Instr 
                                                >> 0x19U))
                                         ? 6U : ((0x20U 
                                                  == 
                                                  (vlSelf->top__DOT__Instr 
                                                   >> 0x19U))
                                                  ? 7U
                                                  : 6U))
                                     : 4U)) : ((0x2000U 
                                                & vlSelf->top__DOT__Instr)
                                                ? (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__Instr)
                                                    ? 9U
                                                    : 8U)
                                                : (
                                                   (0x1000U 
                                                    & vlSelf->top__DOT__Instr)
                                                    ? 5U
                                                    : 0U)));
                        vlSelf->top__DOT__ALUSrcB = 1U;
                        vlSelf->top__DOT__ImmSrc = 0U;
                    }
                }
            }
        } else if ((1U & (~ (vlSelf->top__DOT__Instr 
                             >> 3U)))) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 2U)))) {
                if ((2U & vlSelf->top__DOT__Instr)) {
                    if ((1U & vlSelf->top__DOT__Instr)) {
                        vlSelf->top__DOT__RegWrite = 1U;
                        vlSelf->top__DOT__ALUControl = 0U;
                        vlSelf->top__DOT__ALUSrcB = 1U;
                        vlSelf->top__DOT__ImmSrc = 0U;
                    }
                }
            }
        }
        if ((1U & (~ (vlSelf->top__DOT__Instr >> 4U)))) {
            if ((1U & (~ (vlSelf->top__DOT__Instr >> 3U)))) {
                if ((1U & (~ (vlSelf->top__DOT__Instr 
                              >> 2U)))) {
                    if ((2U & vlSelf->top__DOT__Instr)) {
                        if ((1U & vlSelf->top__DOT__Instr)) {
                            vlSelf->top__DOT__ResultSrc = 1U;
                        }
                    }
                }
            }
        }
    }
    vlSelf->top__DOT__dp_inst__DOT__SrcA = ((IData)(vlSelf->top__DOT__ALUSrcA)
                                             ? vlSelf->top__DOT__dp_inst__DOT__PC
                                             : vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array
                                            [(0x1fU 
                                              & (vlSelf->top__DOT__Instr 
                                                 >> 0xfU))]);
    vlSelf->top__DOT__dp_inst__DOT__ImmExt = ((4U & (IData)(vlSelf->top__DOT__ImmSrc))
                                               ? ((2U 
                                                   & (IData)(vlSelf->top__DOT__ImmSrc))
                                                   ? 0U
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->top__DOT__ImmSrc))
                                                    ? 0U
                                                    : 
                                                   (0xfffff000U 
                                                    & vlSelf->top__DOT__Instr)))
                                               : ((2U 
                                                   & (IData)(vlSelf->top__DOT__ImmSrc))
                                                   ? 
                                                  ((1U 
                                                    & (IData)(vlSelf->top__DOT__ImmSrc))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__Instr 
                                                                 >> 0x1fU))) 
                                                     << 0x14U) 
                                                    | ((0xff000U 
                                                        & vlSelf->top__DOT__Instr) 
                                                       | ((0x800U 
                                                           & (vlSelf->top__DOT__Instr 
                                                              >> 9U)) 
                                                          | (0x7feU 
                                                             & (vlSelf->top__DOT__Instr 
                                                                >> 0x14U)))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__Instr 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0x800U 
                                                        & (vlSelf->top__DOT__Instr 
                                                           << 4U)) 
                                                       | ((0x7e0U 
                                                           & (vlSelf->top__DOT__Instr 
                                                              >> 0x14U)) 
                                                          | (0x1eU 
                                                             & (vlSelf->top__DOT__Instr 
                                                                >> 7U))))))
                                                   : 
                                                  ((1U 
                                                    & (IData)(vlSelf->top__DOT__ImmSrc))
                                                    ? 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__Instr 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | ((0xfe0U 
                                                        & (vlSelf->top__DOT__Instr 
                                                           >> 0x14U)) 
                                                       | (0x1fU 
                                                          & (vlSelf->top__DOT__Instr 
                                                             >> 7U))))
                                                    : 
                                                   (((- (IData)(
                                                                (vlSelf->top__DOT__Instr 
                                                                 >> 0x1fU))) 
                                                     << 0xcU) 
                                                    | (vlSelf->top__DOT__Instr 
                                                       >> 0x14U)))));
    vlSelf->top__DOT__dp_inst__DOT__SrcB = ((IData)(vlSelf->top__DOT__ALUSrcB)
                                             ? vlSelf->top__DOT__dp_inst__DOT__ImmExt
                                             : vlSelf->top__DOT__dp_inst__DOT__ReadData2);
    vlSelf->top__DOT__dp_inst__DOT__ALUResult = ((8U 
                                                  & (IData)(vlSelf->top__DOT__ALUControl))
                                                  ? 
                                                 ((4U 
                                                   & (IData)(vlSelf->top__DOT__ALUControl))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__ALUControl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? vlSelf->top__DOT__dp_inst__DOT__SrcB
                                                     : 0U)
                                                    : 0U)
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__ALUControl))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? 
                                                    ((vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                      < vlSelf->top__DOT__dp_inst__DOT__SrcB)
                                                      ? 1U
                                                      : 0U)
                                                     : 
                                                    (VL_LTS_III(32, vlSelf->top__DOT__dp_inst__DOT__SrcA, vlSelf->top__DOT__dp_inst__DOT__SrcB)
                                                      ? 1U
                                                      : 0U))))
                                                  : 
                                                 ((4U 
                                                   & (IData)(vlSelf->top__DOT__ALUControl))
                                                   ? 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__ALUControl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? 
                                                    VL_SHIFTRS_III(32,32,5, vlSelf->top__DOT__dp_inst__DOT__SrcA, 
                                                                   (0x1fU 
                                                                    & vlSelf->top__DOT__dp_inst__DOT__SrcB))
                                                     : 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     >> 
                                                     (0x1fU 
                                                      & vlSelf->top__DOT__dp_inst__DOT__SrcB)))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     << 
                                                     (0x1fU 
                                                      & vlSelf->top__DOT__dp_inst__DOT__SrcB))
                                                     : 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     ^ vlSelf->top__DOT__dp_inst__DOT__SrcB)))
                                                   : 
                                                  ((2U 
                                                    & (IData)(vlSelf->top__DOT__ALUControl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     | vlSelf->top__DOT__dp_inst__DOT__SrcB)
                                                     : 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     & vlSelf->top__DOT__dp_inst__DOT__SrcB))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__ALUControl))
                                                     ? 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     - vlSelf->top__DOT__dp_inst__DOT__SrcB)
                                                     : 
                                                    (vlSelf->top__DOT__dp_inst__DOT__SrcA 
                                                     + vlSelf->top__DOT__dp_inst__DOT__SrcB)))));
    vlSelf->top__DOT__Zero = (0U == vlSelf->top__DOT__dp_inst__DOT__ALUResult);
    vlSelf->top__DOT__dp_inst__DOT__MemData = ((4U 
                                                & (IData)(vlSelf->top__DOT__AddressingControl))
                                                ? (
                                                   (2U 
                                                    & (IData)(vlSelf->top__DOT__AddressingControl))
                                                    ? 0U
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__AddressingControl))
                                                     ? 
                                                    ((vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                      [
                                                      (0x1ffffU 
                                                       & ((IData)(1U) 
                                                          + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                      << 8U) 
                                                     | vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                     [
                                                     (0x1ffffU 
                                                      & vlSelf->top__DOT__dp_inst__DOT__ALUResult)])
                                                     : 
                                                    vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                    [
                                                    (0x1ffffU 
                                                     & vlSelf->top__DOT__dp_inst__DOT__ALUResult)]))
                                                : (
                                                   (2U 
                                                    & (IData)(vlSelf->top__DOT__AddressingControl))
                                                    ? 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__AddressingControl))
                                                     ? 0U
                                                     : 
                                                    ((vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                      [
                                                      (0x1ffffU 
                                                       & ((IData)(3U) 
                                                          + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                      << 0x18U) 
                                                     | ((vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                         [
                                                         (0x1ffffU 
                                                          & ((IData)(2U) 
                                                             + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                         << 0x10U) 
                                                        | ((vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                            [
                                                            (0x1ffffU 
                                                             & ((IData)(1U) 
                                                                + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                            << 8U) 
                                                           | vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                           [
                                                           (0x1ffffU 
                                                            & vlSelf->top__DOT__dp_inst__DOT__ALUResult)]))))
                                                    : 
                                                   ((1U 
                                                     & (IData)(vlSelf->top__DOT__AddressingControl))
                                                     ? 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                                     [
                                                                     (0x1ffffU 
                                                                      & ((IData)(1U) 
                                                                         + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                                     >> 7U)))) 
                                                      << 0x10U) 
                                                     | ((vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                         [
                                                         (0x1ffffU 
                                                          & ((IData)(1U) 
                                                             + vlSelf->top__DOT__dp_inst__DOT__ALUResult))] 
                                                         << 8U) 
                                                        | vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                        [
                                                        (0x1ffffU 
                                                         & vlSelf->top__DOT__dp_inst__DOT__ALUResult)]))
                                                     : 
                                                    (((- (IData)(
                                                                 (1U 
                                                                  & (vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                                     [
                                                                     (0x1ffffU 
                                                                      & vlSelf->top__DOT__dp_inst__DOT__ALUResult)] 
                                                                     >> 7U)))) 
                                                      << 8U) 
                                                     | vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array
                                                     [
                                                     (0x1ffffU 
                                                      & vlSelf->top__DOT__dp_inst__DOT__ALUResult)]))));
    __Vtableidx1 = (((IData)(vlSelf->top__DOT__Zero) 
                     << 6U) | (((IData)(vlSelf->top__DOT__ctrl_inst__DOT__BranchType) 
                                << 3U) | (((IData)(vlSelf->top__DOT__ctrl_inst__DOT__Branch) 
                                           << 2U) | (IData)(vlSelf->top__DOT__ctrl_inst__DOT__Jump))));
    vlSelf->top__DOT__PCSrc = Vtop__ConstPool__TABLE_h8fccedee_0
        [__Vtableidx1];
    vlSelf->top__DOT__dp_inst__DOT__PCPlus4 = ((IData)(4U) 
                                               + vlSelf->top__DOT__dp_inst__DOT__PC);
    vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCTarget 
        = (vlSelf->top__DOT__dp_inst__DOT__PC + vlSelf->top__DOT__dp_inst__DOT__ImmExt);
    vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCNext 
        = ((0U == (IData)(vlSelf->top__DOT__PCSrc))
            ? vlSelf->top__DOT__dp_inst__DOT__PCPlus4
            : ((1U == (IData)(vlSelf->top__DOT__PCSrc))
                ? vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCTarget
                : ((2U == (IData)(vlSelf->top__DOT__PCSrc))
                    ? (0xfffffffcU & vlSelf->top__DOT__dp_inst__DOT__ALUResult)
                    : vlSelf->top__DOT__dp_inst__DOT__PCPlus4)));
}

void Vtop___024root___eval(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval\n"); );
    // Body
    if (((IData)(vlSelf->clk) & (~ (IData)(vlSelf->__Vclklast__TOP__clk)))) {
        Vtop___024root___sequent__TOP__0(vlSelf);
        vlSelf->__Vm_traceActivity[1U] = 1U;
    }
    // Final
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    // Body
    if (VL_UNLIKELY((vlSelf->clk & 0xfeU))) {
        Verilated::overWidthError("clk");}
    if (VL_UNLIKELY((vlSelf->rst & 0xfeU))) {
        Verilated::overWidthError("rst");}
    if (VL_UNLIKELY((vlSelf->trigger & 0xfeU))) {
        Verilated::overWidthError("trigger");}
}
#endif  // VL_DEBUG
