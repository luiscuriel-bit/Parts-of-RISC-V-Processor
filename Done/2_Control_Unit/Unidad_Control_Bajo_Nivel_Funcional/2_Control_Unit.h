#ifndef UNIDAD_CONTROL
#define UNIDAD_CONTROL

#include <systemc.h>
#include "AndGate.h"
#include "OrGate.h"
#include "NotGate.h"
#include "divider.h"

class Unidad_Control : public sc_module
{
public:

	sc_in_clk clk;

	sc_out<sc_uint<2>> Ex_ALUOpOut;
	sc_out<bool> Ex_ALUSrcOut;
	sc_out<bool> Mem_MemWriteOut, Mem_MemReadOut, Mem_BranchOut;
	sc_out<bool> Wb_MemtoRegOut, Wb_RegWriteOut;

	sc_in<sc_uint<4>> dir_In;
//	sc_in<bool> result_and;
//	sc_out<bool> aux1, aux2, aux3, aux4/*, trueVal, falseVal*/;

//	sc_signal<bool> sg00, sg01, sg02, sg03, sg04/*, sg05, sg06*/;
	SC_CTOR(Unidad_Control);
	~Unidad_Control();

private:
	void operation();
	sc_vector<AndGate> SC_NAMED(and_gate, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(aInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(bInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(cInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(dInSg, 15);
	sc_vector<sc_signal<bool>> SC_NAMED(eOutSg, 15);
	sc_vector<sc_out<bool>> SC_NAMED(aux, 60);


	sc_vector<OrGate> SC_NAMED(or_gate, 11);
	sc_vector<sc_signal<bool>> SC_NAMED(orCOut, 11);

	sc_vector<OrGate> SC_NAMED(or_gate2, 6);
	sc_vector<sc_signal<bool>> SC_NAMED(or2COut, 6);

	sc_vector<OrGate> SC_NAMED(or_gate3, 1);
	sc_signal<bool> or3COut;

	sc_vector<NotGate> SC_NAMED(not_gate2, 1);
	sc_signal<bool> not_gate2Out;

//Daniel

	sc_vector<sc_signal<bool>> SC_NAMED(not_to_and, 28);
	sc_vector<NotGate> SC_NAMED(Not_gate, 28);
	sc_signal<bool> dir_In_0, dir_In_1,dir_In_2,dir_In_3;
	divider *Divider;
//	NotGate *not0, *not1;
};

#endif
