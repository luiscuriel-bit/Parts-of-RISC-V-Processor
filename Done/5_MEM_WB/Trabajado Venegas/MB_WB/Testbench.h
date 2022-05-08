#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:


  sc_in<bool> clkIn;

  sc_out<bool> Wb_MemtoRegIn,Wb_RegWriteIn;

  sc_in<bool> Wb_MemtoRegOut,Wb_RegWriteOut;

  sc_out<sc_int<32>> memo_In[2];
  sc_in<sc_int<32>> memo_Out[2];

  sc_out<sc_uint<5>> dir_In;
  sc_in<sc_uint<5>> dir_Out;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
