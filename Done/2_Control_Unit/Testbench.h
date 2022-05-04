#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in<bool> clkIn, read_writeIn;
  sc_in<sc_uint<2>> Ex_ALUSrcIn, Ex_ALUOpIn;
  sc_in<bool> Men_MemWriteIn, Men_MemReadIn, Men_BranchIn;
  sc_in<bool> Wb_MemtoRegIn, Wb_no_ideaIn ;//ni idea para sirve sea esa señal de control

  sc_out<sc_uint<32>> dir_Out;


  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
