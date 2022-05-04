#include "4_Branch.h"

Branch::Branch(sc_module_name nm) : sc_module(nm) {

	SC_METHOD(operation);
	sensitive << jumpIn << addressIn;
}

void Branch::operation()
{
	answerOut.write(jumpIn.read() and addressIn.read());
}
