// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "verilated.h"

#include "Vtop___024root.h"

extern const VlWide<8>/*255:0*/ Vtop__ConstPool__CONST_h1de76f24_0;

VL_ATTR_COLD void Vtop___024root___initial__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___initial__TOP__0\n"); );
    // Body
    VL_READMEM_N(true, 8, 131072, 0, std::string{"data.hex"}
                 ,  &(vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array)
                 , 0, ~0ULL);
    VL_READMEM_N(true, 32, 4096, 0, VL_CVT_PACK_STR_NW(8, Vtop__ConstPool__CONST_h1de76f24_0)
                 ,  &(vlSelf->top__DOT__dp_inst__DOT__instr_mem_inst__DOT__rom_array)
                 , 0, ~0ULL);
}

extern const VlUnpacked<CData/*1:0*/, 128> Vtop__ConstPool__TABLE_h8fccedee_0;

VL_ATTR_COLD void Vtop___024root___settle__TOP__0(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___settle__TOP__0\n"); );
    // Init
    CData/*6:0*/ __Vtableidx1;
    // Body
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

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    // Body
    Vtop___024root___initial__TOP__0(vlSelf);
    vlSelf->__Vclklast__TOP__clk = vlSelf->clk;
}

VL_ATTR_COLD void Vtop___024root___eval_settle(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_settle\n"); );
    // Body
    Vtop___024root___settle__TOP__0(vlSelf);
    vlSelf->__Vm_traceActivity[1U] = 1U;
    vlSelf->__Vm_traceActivity[0U] = 1U;
}

VL_ATTR_COLD void Vtop___024root___final(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___final\n"); );
}

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    if (false && vlSelf) {}  // Prevent unused
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    // Body
    vlSelf->clk = VL_RAND_RESET_I(1);
    vlSelf->rst = VL_RAND_RESET_I(1);
    vlSelf->a0 = VL_RAND_RESET_I(32);
    vlSelf->trigger = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__PCSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__RegWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUControl = VL_RAND_RESET_I(4);
    vlSelf->top__DOT__ALUSrcA = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ALUSrcB = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__MemWrite = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ResultSrc = VL_RAND_RESET_I(2);
    vlSelf->top__DOT__ImmSrc = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__AddressingControl = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__Zero = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__Instr = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__PC = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__PCPlus4 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__ImmExt = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__MemData = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__ALUResult = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__SrcA = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__SrcB = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__ReadData2 = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCNext = VL_RAND_RESET_I(32);
    vlSelf->top__DOT__dp_inst__DOT__pc_inst__DOT__PCTarget = VL_RAND_RESET_I(32);
    for (int __Vi0=0; __Vi0<4096; ++__Vi0) {
        vlSelf->top__DOT__dp_inst__DOT__instr_mem_inst__DOT__rom_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    for (int __Vi0=0; __Vi0<131072; ++__Vi0) {
        vlSelf->top__DOT__dp_inst__DOT__data_mem_inst__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(8);
    }
    for (int __Vi0=0; __Vi0<32; ++__Vi0) {
        vlSelf->top__DOT__dp_inst__DOT__reg_file_inst__DOT__ram_array[__Vi0] = VL_RAND_RESET_I(32);
    }
    vlSelf->top__DOT__ctrl_inst__DOT__Branch = VL_RAND_RESET_I(1);
    vlSelf->top__DOT__ctrl_inst__DOT__BranchType = VL_RAND_RESET_I(3);
    vlSelf->top__DOT__ctrl_inst__DOT__Jump = VL_RAND_RESET_I(2);
    for (int __Vi0=0; __Vi0<2; ++__Vi0) {
        vlSelf->__Vm_traceActivity[__Vi0] = VL_RAND_RESET_I(1);
    }
}
