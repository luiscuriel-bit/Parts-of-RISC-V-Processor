#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>

class Unidad_Control : public sc_module
{
public:
	sc_out<sc_uint<2>> Ex_ALUOpOut;
	sc_out<bool> Ex_ALUSrcOut;
	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;

	sc_in<sc_int<4>> dir_In;

	SC_CTOR(Unidad_Control);

private:
	void operation();
};

#endif
