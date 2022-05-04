#include "1_3_Adder.h"
#include "Testbench.h"

int sc_main(int argc, char* argv[])
{
	sc_time period(10, SC_NS);
	sc_time delay(10, SC_NS);
	sc_clock clock("clock", period, 5, delay, false);

	Adder adder("adder");
	Testbench tb("tb");

	tb.clk(clock);

	sc_signal<sc_int<32>> number_1Sg, number_2Sg, resultSg;

	adder.number_1In(number_1Sg);
	tb.number_1Out(number_1Sg);

	adder.number_2In(number_2Sg);
	tb.number_2Out(number_2Sg);

	adder.resultOut(resultSg);
	tb.resultIn(resultSg);

	sc_start();

	return 0;
}