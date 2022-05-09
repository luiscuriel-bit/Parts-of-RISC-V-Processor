#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <iostream>
#include <systemc.h>

class Testbench : public sc_module {
public:

	sc_in_clk clk;		
	
	sc_out<sc_int<32>> pcOut;
	sc_out<sc_uint<32>> insMemOut;

	sc_in<sc_uint<5>> fileRegister1In;
	sc_in<sc_uint<5>> fileRegister2In;
	sc_in<sc_int<18>> immGenIn;
	sc_in<sc_int<32>> ID_EX0In;
	sc_in<sc_uint<4>> ID_EX1In;
	sc_in<sc_uint<4>> ID_unidadControlIn;
	sc_in<sc_uint<5>> ID_EX2In;

	SC_CTOR(Testbench);

private:
	void operation();
	void print();
};

#endif
