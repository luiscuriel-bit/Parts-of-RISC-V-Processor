#include "1.h"
#include "Testbench.h"

int sc_main(int argc, char *argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(0, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	Uno uno("uno");
	Testbench tb("tb");

	sc_signal<sc_int<32>> unoSg;
	uno.uno(unoSg);
	tb.unoIn(unoSg);

	tb.clk(clock);

	sc_start();

	return 0;
}