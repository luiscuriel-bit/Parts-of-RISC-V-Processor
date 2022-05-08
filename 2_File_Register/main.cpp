#include "Testbench.h"
#include "FileRegister.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 0.5, delay, true);

	Testbench tb("tb");
	FileRegister fr("fr");

	tb.clk(clock);
	fr.clk(clock);

	sc_signal<sc_uint<32>> aSg, bSg,wSg;
	sc_signal<sc_uint<5>> rwSg, raSg, rbSg;
	sc_signal<bool> weSg;

	tb.wOut(wSg);
	fr.wIn(wSg);

	tb.weOut(weSg);
	fr.weIn(weSg);

	tb.aIn(aSg);
	fr.aOut(aSg);

	tb.bIn(bSg);
	fr.bOut(bSg);

	tb.rwOut(rwSg);
	fr.rwIn(rwSg);

	tb.raOut(raSg);
	fr.raIn(raSg);

	tb.rbOut(rbSg);
	fr.rbIn(rbSg);

	sc_start();

	return 0;
}