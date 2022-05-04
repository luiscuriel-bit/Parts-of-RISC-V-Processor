#ifndef ALU_H
#define ALU_H

#include <systemc.h>

class ALU : public sc_module
{
public:
	sc_in<sc_int<4>> insIn;
	sc_in<sc_int<32>> number_1In, number_2In;
	sc_out<sc_int<32>> resultOut;
	sc_out<bool> zeroOut;

	SC_CTOR(ALU);

private:
	void operation();
};

#endif
