#include "Cell.h"

Cell::Cell(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), wIn("wIn"), weIn("weIn"), dataOut("dataOut")
{
	storage = 0;

	SC_METHOD(write);
	sensitive << clk.neg();
	dont_initialize();

	SC_METHOD(read);
	sensitive << clk.pos();
	dont_initialize();
}

void Cell::read()
{
	dataOut.write(storage);
}

void Cell::write()
{
	if (weIn.read())
		storage = wIn.read();
}
