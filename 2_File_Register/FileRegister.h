#ifndef FILEREGISTER_H
#define FILEREGISTER_H

#include "Register.h"

class FileRegister : public sc_module
{
public:
	sc_in_clk clkIn;						// Reloj
	sc_in<sc_uint<5>> rwIn, raIn, rbIn;		// Direcciones de registros: rwIn para escribir, raIn y rbIn para leer
	sc_in<sc_uint<32>> wIn;					// Valor de escritura para el registro
	sc_in<bool> weIn;						// Booleano que habilita la escritura
	sc_out<sc_uint<32>> aOut, bOut;			// Valores A y B leídos de los registros en las direcciones raIn y rbIn

	SC_CTOR(FileRegister);
private:
	sc_uint<5> lastRegister;

	sc_vector<Register> SC_NAMED(registers, 32);
	sc_vector<sc_signal<bool>> SC_NAMED(weSg,32);
	sc_vector<sc_signal<sc_uint<32>>> SC_NAMED(regSg, 32);
	
	void readA();
	void readB();
	void write();
};

#endif
