// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtb_trap_halt.h for the primary calling header

#ifndef VERILATED_VTB_TRAP_HALT___024ROOT_H_
#define VERILATED_VTB_TRAP_HALT___024ROOT_H_  // guard

#include "verilated.h"
#include "verilated_timing.h"


class Vtb_trap_halt__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtb_trap_halt___024root final : public VerilatedModule {
  public:

    // DESIGN SPECIFIC STATE
    // Anonymous structures to workaround compiler member-count bugs
    struct {
        CData/*0:0*/ tb_trap_halt__DOT__clk;
        CData/*0:0*/ tb_trap_halt__DOT__reset;
        CData/*0:0*/ tb_trap_halt__DOT__trap_valid;
        CData/*3:0*/ tb_trap_halt__DOT__cause_at_trap;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__stall;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__control_taken;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__predict_taken;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__trapped;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__trap_hold;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__if_id_valid;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__if_id_predict_taken;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__alu_ctrl;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__is_jalr;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__uses_rs1;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__uses_rs2;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__reg_write;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__mem_size;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_unsigned;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_exception;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__id_cause;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_valid;
        CData/*4:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_rd;
        CData/*4:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_rs1;
        CData/*4:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_rs2;
        CData/*2:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_funct3;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_itype;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_load;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_store;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_branch;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_jal;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_jalr;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_lui;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_is_auipc;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_reg_write;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_mem_size;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_mem_unsigned;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_exception;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_cause;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__forward_a_sel;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__forward_b_sel;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__branch_cond_taken;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__actual_taken;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_valid;
        CData/*4:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_rd;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_is_link;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_reg_write;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_is_load;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_is_store;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_mem_size;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_mem_unsigned;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_exception;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_cause;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_exception;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__mem_cause;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_valid;
        CData/*4:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_is_link;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_reg_write;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_is_load;
    };
    struct {
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_exception;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__wb_we;
        CData/*7:0*/ tb_trap_halt__DOT__uut__DOT__load_byte;
        CData/*1:0*/ tb_trap_halt__DOT__uut__DOT__bp__DOT__current;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__bp__DOT__init_done;
        CData/*3:0*/ tb_trap_halt__DOT__uut__DOT__dmem__DOT__byte_en;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0;
        CData/*0:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0;
        CData/*0:0*/ __VstlFirstIteration;
        CData/*0:0*/ __Vtrigprevexpr___TOP__tb_trap_halt__DOT__clk__0;
        CData/*0:0*/ __VactContinue;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__reset;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__trap_valid;
        CData/*3:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_cause;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_taken;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_we;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_valid;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_exception;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_taken;
        CData/*1:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b_sel;
        CData/*1:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a_sel;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__stall;
        CData/*4:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__mem_wb_rd;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__trapped;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_9_0;
        CData/*1:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_mem_size;
        CData/*3:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_alu_ctrl;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_7_0;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_5_0;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_0_0;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_2_0;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_valid;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs2;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_uses_rs1;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_4_0;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_valid;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_3_0;
        CData/*4:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs2;
        CData/*4:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rs1;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_branch;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_taken;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_taken;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_load;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_can_forward;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_is_load;
        CData/*4:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs1;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__uses_rs2;
        CData/*4:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_rd;
        CData/*0:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_is_store;
        SData/*15:0*/ tb_trap_halt__DOT__uut__DOT__load_half;
        SData/*8:0*/ tb_trap_halt__DOT__uut__DOT__bp__DOT__init_index;
        IData/*31:0*/ tb_trap_halt__DOT__pc_at_trap;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__control_target;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__pc;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__instr;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__predict_target;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__next_pc;
    };
    struct {
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__if_id_instr;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__if_id_pc;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__if_id_pc_plus_4;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__if_id_predict_target;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__imm;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_pc;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_pc_plus_4;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_rd1;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_rd2;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_imm;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__id_ex_predict_target;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__forward_a;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__forward_b;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__alu_result;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__actual_target;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_result;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_store_data;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_pc_plus_4;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__mem_read_data;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_pc_plus_4;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_result;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__mem_wb_read_data;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__wb_data;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__dmem__DOT__store_word;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0;
        IData/*31:0*/ tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0;
        IData/*31:0*/ __VactIterCount;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__predict_target;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__pc;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__control_target;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_b;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__ex_mem_forward_data;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__wb_data;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_10_0;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__forward_a;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_8_0;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_6_0;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__u_assert__DOT___Vpast_1_0;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd2;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_rd1;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__actual_target;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__id_ex_predict_target;
        IData/*31:0*/ __Vsampled__TOP__tb_trap_halt__DOT__uut__DOT__if_id_instr;
        VlUnpacked<IData/*31:0*/, 1024> tb_trap_halt__DOT__uut__DOT__imem_inst__DOT__mem;
        VlUnpacked<CData/*1:0*/, 256> tb_trap_halt__DOT__uut__DOT__bp__DOT__counters;
        VlUnpacked<IData/*31:0*/, 32> tb_trap_halt__DOT__uut__DOT__rf__DOT__regs;
        VlUnpacked<IData/*31:0*/, 1024> tb_trap_halt__DOT__uut__DOT__dmem__DOT__mem;
    };
    VlDelayScheduler __VdlySched;
    VlTriggerScheduler __VtrigSched_h13638d1d__0;
    VlTriggerVec<1> __VstlTriggered;
    VlTriggerVec<2> __VactTriggered;
    VlTriggerVec<2> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtb_trap_halt__Syms* const vlSymsp;

    // CONSTRUCTORS
    Vtb_trap_halt___024root(Vtb_trap_halt__Syms* symsp, const char* v__name);
    ~Vtb_trap_halt___024root();
    VL_UNCOPYABLE(Vtb_trap_halt___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
