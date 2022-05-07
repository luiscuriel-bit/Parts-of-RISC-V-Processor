#ifndef IMM_GEN_H
#define IMM_GEN_H

#include <systemc.h>

class Imm_Gen : public sc_module
{

public:
	sc_in<sc_int<16>> IF_IDIn;
	sc_out<sc_int<32>> ID_EXOut;

	SC_CTOR(Imm_Gen);

private:
	void operation();
};

#endif
