#include "Register.h"

Register::Register(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), wIn("wIn"), weIn("weIn"), regOut("regOut")
{
	for (int i = 0; i < 32; i++)
	{
		cell[i].wIn(wSg[i]);
		cell[i].weIn(weIn);
		cell[i].clk(clk);
		cell[i].dataOut(bitSg[i]);
	}

	SC_METHOD(write);
	sensitive << wIn << weIn;

	SC_METHOD(read);
	for (int i = 0; i < 32; i++)
		sensitive << bitSg[i];
}

void Register::read()
{
	sc_uint<32> aux;

	for (int i = 0; i < 32; i++)
		aux[i] = bitSg[i].read();

	regOut.write(aux);
}

void Register::write()
{
	for (int i = 0; i < 32; i++)
		wSg[i] = wIn.read()[i];
}
