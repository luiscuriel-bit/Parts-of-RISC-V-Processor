#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>
#include "IF_ID.h"


class Testbench : public sc_module {
public:

	sc_in_clk clk;													
	sc_out<sc_uint<32>> cpOut;
	sc_out<sc_uint<32>> insMemOut;						
	sc_in<sc_uint<5>> register1In;
	sc_in<sc_uint<5>> register2In;
	sc_in<sc_uint<32>> ID_EXIn;
	sc_in<sc_uint<32>> instruction1In;
	sc_in<sc_uint<32>> instruction2In;
	sc_in<sc_uint<32>> instruction3In;

	SC_CTOR(Testbench);

private:
	void operation();
	void print();
};

#endif
