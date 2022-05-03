#include "2_IF_ID.h"

IF_ID::IF_ID(sc_module_name moduleName) : sc_module(moduleName), pcIn("pcIn"), insMemIn("insMemIn"), fileRegister1Out("fileRegister1Out"), fileRegister2Out("fileRegister2Out"), ID_EX0Out("ID_EX0Out"), ID_EX1Out("ID_EX1Out"), ID_EX2Out("ID_EX2Out")
{

	SC_METHOD(operation);
	sensitive << clk.pos();
	dont_initialize();
}

// 1 add
// 2 sub
// 3 addi
// 4 sll
// 5 srl
// 6 slli
// 7 srli
// 8 lw
// 9 sw
// 10 and
// 11 or
// 12 andi
// 13 ori
// 14 beq
// 15 bne
// 16 jalr

void IF_ID::operation()
{
	sc_int<8> writeRegister;
	sc_int<8> register1;
	sc_int<8> register2;
	sc_int<8> imm, imm2;
	sc_int<8> instruction;

	ID_EX0Out.write(pcIn.read());

	for (int i = 31, j = 7; i >= 24; i--, j--)
		writeRegister[j] = insMemIn.read()[i];

	for (int i = 23, j = 7; i >= 16; i--, j--)
	{
		register1[j] = insMemIn.read()[i];
		imm[j] = insMemIn.read()[i];
	}
	for (int i = 15, j = 7; i >= 8; i--, j--)
	{
		register2[j] = insMemIn.read()[i];
		imm2[j] = insMemIn.read()[i];
	}

	for (int i = 7, j = 7; i >= 0; i--, j--)
		instruction[j] = insMemIn.read()[i];

	fileRegister1Out.write(register1);
	fileRegister2Out.write(register2);

	if (instruction == 3 || instruction == 6 || instruction == 7 || instruction == 12 || instruction == 13)
		immGenOut.write(imm2);
	else
		immGenOut.write(imm);

	if (instruction == 8 || instruction == 9 || instruction == 16)
	{

		fileRegister1Out.write(register2);
		fileRegister2Out.write(writeRegister); // El primer operando es el que se va a guardar en data memory
		immGenOut.write(register1);
	}
	else
	{
		fileRegister1Out.write(register1);
		fileRegister2Out.write(register2);
	}

	if (instruction == 14 || instruction == 15)
	{
		fileRegister1Out.write(writeRegister);
		fileRegister2Out.write(register1);
		immGenOut.write(register2);
	}

	ID_EX1Out.write(instruction);
	ID_unidadControl.write(instruction);
	ID_EX2Out.write(writeRegister);
}
