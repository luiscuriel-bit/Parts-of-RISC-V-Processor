#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>


class Testbench : public sc_module {
public:

  sc_in<sc_int<32>> numberIn;
  sc_out<sc_int<32>> send_number_1Out, send_number_2Out;
  sc_out<sc_int<8>> insOut;
  sc_in<bool> zeroIn;
  sc_in<bool> clk;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
