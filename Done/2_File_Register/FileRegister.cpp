#include "FileRegister.h"

FileRegister::FileRegister(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), rwIn("rwIn"), raIn("raIn"), rbIn("rbIn"), wIn("wIn"), weIn("weIn"), aOut("aOut"), bOut("bOut"), and1("and1")
{
	for (int i = 0; i < 32; i++)
	{
		registers[i].clk(clk);
		registers[i].weIn(weSg[i]);
		registers[i].wIn(wSg[i]);
		registers[i].regOut(regSg[i]);
	}

	and1.aIn(aSg);
	and1.bIn(bSg);
	and1.cOut(cSg);

	SC_METHOD(write);
	sensitive << wIn << weIn << cSg;

	SC_METHOD(readA);
	sensitive << raIn;

	SC_METHOD(readB);
	sensitive << rbIn;
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
	weSg[lastRegister].write(false);

	aSg = rwIn.read();
	bSg = weIn.read();

	if (cSg.read())
	{
		weSg[rwIn.read()].write(true);
		wSg[rwIn.read()].write(wIn.read());
		lastRegister = rwIn.read();
	}
}