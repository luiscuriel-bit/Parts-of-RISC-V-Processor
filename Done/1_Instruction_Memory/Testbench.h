#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>

class Testbench : public sc_module
{
public:
	sc_in_clk clk;

	sc_out<sc_int<32>> instructionNumberOut;
	sc_in<sc_int<32>> operationIn;

	SC_CTOR(Testbench);
private:
	sc_int<8> operand1, operand2, operand3, instruction;

	void print();
	void test();
};

#endif
