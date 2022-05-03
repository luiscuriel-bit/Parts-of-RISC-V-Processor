#include "1_3_Adder.h"

Adder::Adder(sc_module_name moduleName) : sc_module(moduleName), number_1In("number_1In"), number_2In("number_2In"), resultOut("resultOut")
{
	SC_METHOD(operation);
	sensitive << number_1In << number_2In;
}

void Adder::operation()
{
	resultOut.write(number_1In.read() + number_2In.read());
}
