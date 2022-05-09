#ifndef UNO_H
#define UNO_H

#include <iostream>
#include <systemc.h>

class Uno : public sc_module
{
public:
	sc_out<sc_int<32>> uno;

	SC_CTOR(Uno);
	~Uno();

private:
	void operation();
};

#endif
