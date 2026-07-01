// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_cpu.h for the primary calling header

#ifndef VERILATED_VTB_CPU___024ROOT_H_
#define VERILATED_VTB_CPU___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_cpu__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_cpu___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_cpu__DOT__clk;
        CData/*0:0*/ tb_cpu__DOT__reset;
        CData/*0:0*/ tb_cpu__DOT__ex_mem_forward_a_event;
        CData/*0:0*/ tb_cpu__DOT__ex_mem_forward_b_event;
        CData/*0:0*/ tb_cpu__DOT__mem_wb_forward_a_event;
        CData/*0:0*/ tb_cpu__DOT__mem_wb_forward_b_event;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__stall;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__control_taken;
        CData/*3:0*/ tb_cpu__DOT__uut__DOT__alu_ctrl;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__wb_we;
        CData/*6:0*/ tb_cpu__DOT__uut__DOT__id_ex_opcode;
        CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd;
        CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rs1;
        CData/*4:0*/ tb_cpu__DOT__uut__DOT__id_ex_rs2;
        CData/*3:0*/ tb_cpu__DOT__uut__DOT__id_ex_alu_ctrl;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__id_ex_is_itype;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__id_ex_is_load;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__id_ex_is_store;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__id_ex_is_branch;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__id_ex_is_jal;
        CData/*2:0*/ tb_cpu__DOT__uut__DOT__id_ex_funct3;
        CData/*1:0*/ tb_cpu__DOT__uut__DOT__forward_a_sel;
        CData/*1:0*/ tb_cpu__DOT__uut__DOT__forward_b_sel;
        CData/*4:0*/ tb_cpu__DOT__uut__DOT__ex_mem_rd;
        CData/*6:0*/ tb_cpu__DOT__uut__DOT__ex_mem_opcode;
        CData/*4:0*/ tb_cpu__DOT__uut__DOT__mem_wb_rd;
        CData/*6:0*/ tb_cpu__DOT__uut__DOT__mem_wb_opcode;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__mem_wb_is_jal;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__ex_use_imm;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__branch_cond_taken;
        CData/*0:0*/ tb_cpu__DOT__uut__DOT__ex_mem_is_jal;
        CData/*0:0*/ __Vfunc_tb_cpu__DOT__instr_uses_rs1__0__Vfuncout;
        CData/*6:0*/ __Vfunc_tb_cpu__DOT__instr_uses_rs1__0__opcode;
        CData/*0:0*/ __Vfunc_tb_cpu__DOT__instr_uses_rs2__1__Vfuncout;
        CData/*6:0*/ __Vfunc_tb_cpu__DOT__instr_uses_rs2__1__opcode;
        CData/*0:0*/ __Vdlyvval__tb_cpu__DOT__clk__v0;
        CData/*0:0*/ __Vdlyvset__tb_cpu__DOT__clk__v0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_cpu__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        IData/*31:0*/ tb_cpu__DOT__cycle_count;
        IData/*31:0*/ tb_cpu__DOT__retired_count;
        IData/*31:0*/ tb_cpu__DOT__stall_count;
        IData/*31:0*/ tb_cpu__DOT__control_count;
        IData/*31:0*/ tb_cpu__DOT__load_use_stall_count;
        IData/*31:0*/ tb_cpu__DOT__branch_taken_count;
        IData/*31:0*/ tb_cpu__DOT__jump_taken_count;
        IData/*31:0*/ tb_cpu__DOT__flush_count;
        IData/*31:0*/ tb_cpu__DOT__rtype_count;
        IData/*31:0*/ tb_cpu__DOT__itype_count;
        IData/*31:0*/ tb_cpu__DOT__load_count;
        IData/*31:0*/ tb_cpu__DOT__store_count;
        IData/*31:0*/ tb_cpu__DOT__branch_instr_count;
        IData/*31:0*/ tb_cpu__DOT__jal_instr_count;
        IData/*31:0*/ tb_cpu__DOT__ex_mem_forward_a_count;
        IData/*31:0*/ tb_cpu__DOT__ex_mem_forward_b_count;
        IData/*31:0*/ tb_cpu__DOT__mem_wb_forward_a_count;
        IData/*31:0*/ tb_cpu__DOT__mem_wb_forward_b_count;
        IData/*31:0*/ tb_cpu__DOT__total_forward_count;
        IData/*31:0*/ tb_cpu__DOT__summary_file;
        IData/*31:0*/ tb_cpu__DOT__instruction_file;
        IData/*31:0*/ tb_cpu__DOT__trace_file;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__pc;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__instr;
    };
    struct {
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__if_id_instr;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__if_id_pc;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__imm;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__wb_data;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd1;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_rd2;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_imm;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_instr;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__id_ex_pc;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__forward_a;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__forward_b;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_result;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__mem_wb_result;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__mem_wb_pc_plus_4;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__alu_result;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__jal_target;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_store_data;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_pc_plus_4;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__ex_mem_instr;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__mem_read_data;
        IData/*31:0*/ tb_cpu__DOT__uut__DOT__mem_wb_instr;
        IData/*31:0*/ __VactIterCount;
        VlUnpacked<IData/*31:0*/, 256> tb_cpu__DOT__uut__DOT__imem_inst__DOT__mem;
        VlUnpacked<IData/*31:0*/, 32> tb_cpu__DOT__uut__DOT__rf__DOT__regs;
        VlUnpacked<IData/*31:0*/, 256> tb_cpu__DOT__uut__DOT__dmem__DOT__mem;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h605b3eaf__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<3> __VactTriggered;
    VlTriggerVec<3> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_cpu__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_cpu___024root(Vtb_cpu__Syms* symsp, const char* v__name);
    ~Vtb_cpu___024root();
    VL_UNCOPYABLE(Vtb_cpu___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
