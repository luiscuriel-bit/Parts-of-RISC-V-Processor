#ifndef CELL_H
#define CELL_H

#include <systemc.h>

class Cell : public sc_module
{
public:
	sc_in_clk clk;		// Reloj
	sc_in<bool> wIn;
	sc_in<bool> weIn;	// Valor de escritura para celda y booleano que habilita la escritura
	sc_out<bool> dataOut;	// Valor de lectura de la celda

	SC_CTOR(Cell);
private:
	bool storage;

	void read();
	void write();
};

#endif
