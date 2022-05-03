#include "1_PC.h"

PC::PC(sc_module_name moduleName) : sc_module(moduleName), adressIn("adressIn"), adressAdderOut("adressAdderOut"), adressPC_IF_IDOut("adressPC_IF_IDOut"), adressInstructionMemoryOut("adressInstructionMemoryOut")
{
	SC_METHOD(write);
	sensitive << clk.pos();
	SC_METHOD(read);
	sensitive << clk.neg();
}

void PC::write()
{
	adress = adressIn.read();

}

void PC::read()
{
	adressAdderOut.write(adress);
	adressPC_IF_IDOut.write(adress);
	adressInstructionMemoryOut.write(adress);
}