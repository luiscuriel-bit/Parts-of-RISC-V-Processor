#ifndef TESTBENCH_H
#define TESTBENCH_H

#include <systemc.h>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

class Testbench : public sc_module
{
public:
	sc_in_clk clk;								// Reloj
	sc_in<sc_uint<32>> aIn, bIn;				// Valores A y B leídos de los registros en las direcciones raOut y rbOut
	sc_out<sc_uint<5>> raOut, rbOut, rwOut;		// Direcciones de registros: rwOut para escribir, raOut y rbOut para leer
	sc_out<sc_uint<32>> wOut;					// Valor de escritura para el registro
	sc_out<bool> weOut;							// Booleano que habilita la escritura

	SC_CTOR(Testbench);

private:
	void test();
	void print1();
	void print2();
};

#endif
