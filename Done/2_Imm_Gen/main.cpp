#include "Testbench.h"
#include "2_Imm_Gen.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	Imm_Gen imm_gen("imm_gen");

	tb.clk(clock);
//	imm_gen.clk(clock);

	sc_signal<sc_int<16>> Sg1;
	sc_signal<sc_int<32>> Sg2;

	tb.IF_IDOut(Sg1);
	imm_gen.IF_IDIn(Sg1);

	tb.ID_EXIn(Sg2);
	imm_gen.ID_EXOut(Sg2);

	sc_start();

	return 0;
}