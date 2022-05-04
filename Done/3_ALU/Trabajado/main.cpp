#include "3_ALU.h"
#include "Testbench.h"

int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  ALU alu("alu");
  Testbench tb("tb");

  sc_signal<sc_int<32>> add_1, add_2, result;
  sc_signal<sc_int<4>> ins;
  sc_signal<bool> zero;


  alu.number_1In(add_1);
  alu.number_2In(add_2);
  alu.insIn(ins);
  alu.zeroOut(zero);
  alu.resultOut(result);
//  alu.clk(clock);


  tb.numberIn(result);
  tb.send_number_1Out(add_1);
  tb.send_number_2Out(add_2);
  tb.insOut(ins);
  tb.zeroIn(zero);

  tb.clk(clock);

  sc_start();

  return 0;
}
