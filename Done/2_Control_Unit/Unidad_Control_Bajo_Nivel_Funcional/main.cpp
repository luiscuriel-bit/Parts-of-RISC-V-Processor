#include "2_Control_Unit.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  Unidad_Control Unidad_Control("Unidad_Control");
  Testbench tb("tb");

  sc_signal<sc_uint<2>> Ex_ALUOp_1;
  sc_signal<bool> Mem_MemWrite_1, Mem_MemRead_1, Mem_Branch_1;
  sc_signal<bool> Wb_MemtoReg_1, Wb_RegWrite_1, Ex_ALUSrc_1;

  sc_signal<sc_uint<4>> dir_1;

  Unidad_Control.Ex_ALUSrcOut(Ex_ALUSrc_1), Unidad_Control.Ex_ALUOpOut(Ex_ALUOp_1);
  Unidad_Control.Mem_MemWriteOut(Mem_MemWrite_1), Unidad_Control.Mem_MemReadOut(Mem_MemRead_1), Unidad_Control.Mem_BranchOut(Mem_Branch_1);
  Unidad_Control.Wb_MemtoRegOut(Wb_MemtoReg_1), Unidad_Control.Wb_RegWriteOut(Wb_RegWrite_1) ;

  Unidad_Control.dir_In(dir_1);

  tb.Ex_ALUSrcIn(Ex_ALUSrc_1), tb.Ex_ALUOpIn(Ex_ALUOp_1);
  tb.Mem_MemWriteIn(Mem_MemWrite_1), tb.Mem_MemReadIn(Mem_MemRead_1), tb.Mem_BranchIn(Mem_Branch_1);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_1), tb.Wb_RegWriteIn(Wb_RegWrite_1) ;
/*
  sc_signal<bool> test;

  Unidad_Control.sg(test);
  tb.testeo(test);*/

  tb.dir_Out(dir_1);
  tb.clkIn(clock);

  Unidad_Control.clk(clock);

  sc_start();

  return 0;
}