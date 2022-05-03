#include "FileRegister.h"

FileRegister::FileRegister(sc_module_name moduleName) : sc_module(moduleName), clkIn("clkIn"), rwIn("rwIn"), raIn("raIn"), rbIn("rbIn"), wIn("wIn"), weIn("weIn"), aOut("aOut"), bOut("bOut")
{
	for (int i = 0; i < 32; i++)
	{
		registers[i].clk(clkIn);
		registers[i].weIn(weSg[i]);
		registers[i].wIn(wIn);
		registers[i].regOut(regSg[i]);
	}

	SC_METHOD(write);
	sensitive << wIn << weIn;

	SC_METHOD(readA);
	sensitive << raIn;

	for (int i = 0; i < 32; i++)
		sensitive << regSg[i];

	SC_METHOD(readB);
	sensitive << rbIn;

	for (int i = 0; i < 32; i++)
		sensitive << regSg[i];
}

void FileRegister::readA()
{
	aOut.write(regSg[raIn.read()]);
}

void FileRegister::readB()
{
	bOut.write(regSg[rbIn.read()]);
}

void FileRegister::write()
{
	if (rwIn.read() and weIn.read())
	{
		weSg[lastRegister].write(false);
		weSg[rwIn.read()].write(true);
		lastRegister = rwIn.read();
	}
}