#include "1.h"

Uno::Uno(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
}

void Uno::operation()
{
	uno.write(1);
}

Uno::~Uno() {}