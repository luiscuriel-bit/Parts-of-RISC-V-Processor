#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in<bool> clkIn;
  sc_in<sc_uint<2>> Ex_ALUOpIn;
  sc_in<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn;
  sc_in<bool> Wb_MemtoRegIn, Wb_RegWriteIn, Ex_ALUSrcIn;

  sc_out<sc_uint<4>> dir_Out;

//  sc_in<bool> testeo;

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
