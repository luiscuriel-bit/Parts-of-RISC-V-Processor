#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>
#include "Ins_Mem.h"
#include "PC.h"

class Testbench : public sc_module {
public:

	sc_in_clk clk;													
	sc_out<sc_uint<32>> adressOut;
	sc_in<sc_uint<32>> operationIn;

	SC_CTOR(Testbench);

private:
	void operation();
	//void print();
};

#endif
