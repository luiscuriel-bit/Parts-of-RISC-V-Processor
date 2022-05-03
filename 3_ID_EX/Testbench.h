#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:

  sc_in<bool> clkIn;
  sc_in<bool> Ex_ALUSrcIn, Ex_ALUOpIn;
  sc_in<bool> Men_MemWriteIn, Men_MemReadIn, Men_BranchIn;
  sc_in<bool> Wb_MemtoRegIn, Wb_no_ideaIn ;//ni idea para sirve sea esa señal de control

  sc_out<bool> Ex_ALUSrcOut, Ex_ALUOpOut;
  sc_out<bool> Men_MemWriteOut, Men_MemReadOut, Men_BranchOut;
  sc_out<bool> Wb_MemtoRegOut, Wb_no_ideaOut ;//ni idea para sirve sea esa señal de control

  //sc_in<sc_vector<sc_int<32>>> SC_NAMED(memoIn, 2);
  //sc_out<sc_vector<sc_int<32>>> SC_NAMED(memoOut, 2);
  sc_in<sc_int<32>> memo_In[2];
  sc_out<sc_int<32>> memo_Out[2];
 // sc_in<sc_vector<sc_uint<32>>> SC_NAMED(dir_In, 3);
 // sc_out<sc_vector<sc_uint<32>>> SC_NAMED(dir_out, 3);
  sc_in<sc_uint<32>> dir_In[3];
  sc_out<sc_uint<32>> dir_Out[3];

  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
