#include "3_ALU_Control_Unit.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ALU_CONTROL aluC("aluC");
  Testbench tb("tb");

  sc_signal<sc_uint<4>> insIn, insOut;
  sc_signal<sc_uint<2>> Op;

  aluC.Ex_ALUOpIn(Op);
  aluC.dir_In(insIn);
  aluC.instruction_aluOut(insOut);
//  alu.clk(clock);

  tb.Ex_ALUOpOut(Op);
  tb.dir_Out(insIn);
  tb.instruction_aluIn(insOut);
  tb.clk(clock);

  sc_start();

  return 0;
}
