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
	sc_uint<4> instruction;
	sc_uint<5> operand1, operand2, operand3;
	sc_int<18> imm;

	ID_EX0Out.write(pcIn.read());

	for (sc_uint<3> i = 0; i < 4; i++)
		instruction[i] = insMemIn.read()[i];

	if (instruction == 3 or instruction == 6 or instruction == 7 or instruction == 12 or instruction == 13 or instruction == 8 or instruction == 9 or instruction == 14 or instruction == 15)
	{
		for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
			operand1[j] = insMemIn.read()[i];

		for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
			operand2[j] = insMemIn.read()[i];

		for (sc_uint<6> i = 14, j = 0; i < 32; i++, j++)
			imm[j] = insMemIn.read()[i];
	}
	else
	{
		for (sc_uint<4> i = 4, j = 0; i < 9; i++, j++)
			operand1[j] = insMemIn.read()[i];

		for (sc_uint<4> i = 9, j = 0; i < 14; i++, j++)
			operand2[j] = insMemIn.read()[i];

		for (sc_uint<5> i = 14, j = 0; i < 19; i++, j++){
			operand3[j] = insMemIn.read()[i];
			
		}
		
	}

	fileRegister1Out.write(operand2);
	fileRegister2Out.write(operand3);

	//if (instruction == 3 || instruction == 6 || instruction == 7 || instruction == 12 || instruction == 13)
	//	immGenOut.write(imm);

	if (instruction == 8 || instruction == 9)
	{
		fileRegister1Out.write(operand2);
		fileRegister2Out.write(operand1);
		//immGenOut.write(imm);
	}

	if (instruction == 14 || instruction == 15)
	{
		fileRegister1Out.write(operand1);
		fileRegister2Out.write(operand2);
		//immGenOut.write(register2);
	}

	immGenOut.write(imm);
	
	ID_EX1Out.write(instruction);
	ID_unidadControlOut.write(instruction);
	ID_EX2Out.write(operand1);
}