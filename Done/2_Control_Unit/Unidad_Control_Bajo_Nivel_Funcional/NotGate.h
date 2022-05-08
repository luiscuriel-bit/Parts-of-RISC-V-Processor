#ifndef NOT_GATE_H
#define NOT_GATE_H

#include <systemc.h>

class NotGate : public sc_module{
public:
	sc_in<bool> Entrada1;
	sc_out<bool> Salida1;

	SC_CTOR(NotGate);
	~NotGate();
private:
	void process();

};
#endif