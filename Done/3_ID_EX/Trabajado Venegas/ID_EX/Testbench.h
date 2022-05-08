#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>


class Testbench : public sc_module {
public:
  sc_in_clk clkIn;

  sc_out<bool> Ex_ALUSrcIn;
  sc_out<bool> Mem_MemWriteIn, Mem_MemReadIn, Mem_BranchIn;
  sc_out<bool> Wb_MemtoRegIn, Wb_RegWriteIn; 
  sc_out<sc_uint<2>> Ex_ALUOpIn; 
  sc_out<sc_int<32>> Imm_genIn;
  sc_out<sc_int<32>> id_ex0In;
  sc_out<sc_uint<5>> id_ex1In;
  sc_out<sc_uint<5>> id_ex2In;
  sc_vector<sc_out<sc_int<32>>> SC_NAMED(memo_In, 2);

  sc_in<bool> Ex_ALUSrcOut;
  sc_in<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
  sc_in<bool> Wb_MemtoRegOut, Wb_RegWriteOut; 

  sc_in<sc_uint<2>> Ex_ALUOpOut;      
  sc_in<sc_int<32>> Imm_gen1Out;
  sc_in<sc_int<32>> Imm_gen2Out;
  sc_in<sc_int<32>> id_ex0Out;
  sc_in<sc_uint<5>> id_ex1Out;
  sc_in<sc_uint<5>> id_ex2Out;
  sc_vector<sc_in<sc_int<32>>> SC_NAMED(memo_Out, 2); 


  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
