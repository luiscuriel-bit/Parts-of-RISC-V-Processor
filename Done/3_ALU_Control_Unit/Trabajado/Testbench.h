#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:

  sc_in_clk clk;
	sc_out<sc_uint<2>> Ex_ALUOpOut;
	sc_out<sc_uint<4>> dir_Out;
	sc_in<sc_uint<4>> instruction_aluIn;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
