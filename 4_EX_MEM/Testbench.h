#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:


  sc_in<bool> clkIn, alu_to_brachIn;
  sc_out<bool> alu_to_brachOut;

  sc_in<bool> Men_MemWriteIn, Men_MemReadIn, Men_BranchIn;
  sc_in<bool> Wb_MemtoRegIn, Wb_no_ideaIn ;//ni idea para sirve sea esa señal de control

  sc_out<bool> Men_MemWriteOut, Men_MemReadOut, Men_BranchOut;
  sc_out<bool> Wb_MemtoRegOut, Wb_no_ideaOut ;//ni idea para sirve sea esa señal de control


  sc_in<sc_int<32>> memo_In[4];
  sc_out<sc_int<32>> memo_Out[4];

  sc_in<sc_uint<32>> dir_In;
  sc_out<sc_uint<32>> dir_Out;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
