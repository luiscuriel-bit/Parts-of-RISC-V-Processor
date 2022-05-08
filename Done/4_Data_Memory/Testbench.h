#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>

#include <systemc.h>

const int TAM_ADDRESS = 16;


class Testbench : public sc_module {
public:
  sc_out<sc_uint<TAM_ADDRESS>> addressOut;   
  sc_out<sc_uint<32>> write_dataOut;  
  sc_in<sc_uint<32>> read_dataIn; 
  sc_out<bool> writeOut, readOut;        //

  sc_in<bool> clkIn;  

  int * memory;
  SC_CTOR(Testbench);

private:
  void print();
  void test();
};

#endif
