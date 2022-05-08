#ifndef REGISTER_H
#define REGISTER_H

#include "Cell.h"

class Register : public sc_module
{
public:
	sc_in_clk clk;					// Reloj
	sc_in<sc_uint<32>> wIn;			// Valor de escritura para el registro
	sc_in<bool> weIn;				// Booleano que habilita la escritura
	sc_out<sc_uint<32>> regOut;		// Valor de lectura del registro
	sc_uint<5> registerAdress;

	SC_CTOR(Register);
private:
	sc_vector<Cell> SC_NAMED(cell, 32);
	sc_vector<sc_signal<bool>> SC_NAMED(wSg, 32);
	sc_vector<sc_signal<bool>> SC_NAMED(bitSg, 32);

	void read();
	void write();
};

#endif