#include "2_Imm_Gen.h"

Imm_Gen::Imm_Gen(sc_module_name moduleName) : sc_module(moduleName)
{

	SC_METHOD(operation);
	sensitive << IF_IDIn;
	dont_initialize();
}

void Imm_Gen::operation()
{
	ID_EXOut.write(IF_IDIn.read());
}