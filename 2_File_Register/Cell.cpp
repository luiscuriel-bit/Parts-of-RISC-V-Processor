#include "Cell.h"

Cell::Cell(sc_module_name nm) : sc_module(nm), clkIn("clkIn"), wIn("wIn"), weIn("weIn"), dataOut("dataOut")
{
	storage = 0;

	SC_METHOD(write);
	sensitive << clkIn.neg();

	SC_METHOD(read);
	sensitive << clkIn.pos();
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
