#include "1_Instruction_Memory.h"

InstructionMemory::InstructionMemory(sc_module_name moduleName) : sc_module(moduleName), instructionNumberIn("instructionNumberIn"), operationOut("operationOut")
{
	ifstream instructionFile("Instructions.txt", ios::in);
	if (instructionFile.fail())
		exit(EXIT_FAILURE);

	numberOfInstructions = 0;

	std::string aux;
	while (!instructionFile.eof())
	{
		getline(instructionFile, aux);
		numberOfInstructions++;
	}

	instructionFile.close();

	instructionFile.open("Instructions.txt", ios::in);
	if (instructionFile.fail())
		exit(EXIT_FAILURE);

	instructionList = new std::string[numberOfInstructions];
	for (sc_int<32> i = 0; !instructionFile.eof();)
	{
		getline(instructionFile, instructionList[i]);
		if (instructionList[i] == "")
			continue;
		i++;
	}

	instructionFile.close();

	SC_METHOD(operation);

	//sensitive << clk;
	// Se debe hacer un dont_initialize para que se puedan cargar las instrucciones correctamente
	//dont_initialize();

	sensitive << instructionNumberIn;
}

void InstructionMemory::list(std::string instruction)
{
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

	std::string aux = instruction.substr(0, instruction.find_first_of(' '));
	if (aux.back() == ':')
	{
		instruction = instruction.substr(instruction.find_first_of(' ') + 1);
		aux = instruction.substr(0, instruction.find_first_of(' '));
	}

	sc_uint<4> insN = 0;
	if (aux == "add" or aux == "sub" or aux == "sll" or aux == "srl" or aux == "and" or aux == "or")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_uint<5> dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
		sc_uint<5> dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 3));
		sc_uint<5> dir03 = stoi(aux4);

		operand = dir01;
		operand <<= 8;
		operand += dir02;
		operand <<= 8;
		operand += dir03;
		operand <<= 8;

		if (aux == "add")
			insN = 1;
		else if (aux == "sub")
			insN = 2;
		else if (aux == "sll")
			insN = 4;
		else if (aux == "srl")
			insN = 5;
		else if (aux == "and")
			insN = 10;
		else if (aux == "or")
			insN = 11;

		operand += insN;
		operationOut.write(operand);
	}
	else if (aux == "addi" or aux == "slli" or aux == "srli" or aux == "andi" or aux == "ori")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_uint<5> dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 3));
		sc_uint<5> dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
		//El valor inmediato solo puede ser desde -128 hasta 127
		sc_int<8> dir03 = stoi(aux4);

		operand = dir01;
		operand <<= 8;
		operand += dir02;
		operand <<= 8;
		for (sc_uint<4> i = 0; i < 8; i++)
			operand[i] = dir03[i];
		operand <<= 8;

		if (aux == "addi")
			insN = 3;
		else if (aux == "slli")
			insN = 6;
		else if (aux == "srli")
			insN = 7;
		else if (aux == "andi")
			insN = 12;
		else if (aux == "ori")
			insN = 13;

		operand += insN;
		operationOut.write(operand);
	}
	else if (aux == "lw" or aux == "sw"/* or aux == "jalr"*/)
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_uint<5> dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of(',') + 2));
		//El valor inmediato solo puede ser desde -128 hasta 127
		sc_int<8> dir02 = stoi(aux3);
		std::string aux4(aux3.substr(aux3.find_first_of('x') + 1));
		sc_uint<5> dir03 = stoi(aux4);

		operand = dir01;
		operand <<= 8;
		for (sc_uint<4> i = 0; i < 8; i++)
			operand[i] = dir02[i];
		operand <<= 8;
		operand += dir03;
		operand <<= 8;

		if (aux == "lw")
			insN = 8;
		else if (aux == "sw")
			insN = 9;
		//else if (aux == "jalr")
		//	insN = 16;

		operand += insN;
		operationOut.write(operand);
	}
	else if (aux == "beq" or aux == "bne")
	{
		std::string aux2(instruction.substr(instruction.find_first_of('x') + 1));
		sc_uint<5> dir01 = stoi(aux2);
		std::string aux3(aux2.substr(aux2.find_first_of('x') + 1));
		sc_uint<5> dir02 = stoi(aux3);

		std::string aux4(aux3.substr(aux3.find_first_of(',') + 2));
		sc_int<32> linea = 0;
		for (sc_int<32> i = 0; i < numberOfInstructions; i++)
		{
			sc_int<32> pos = instructionList[i].find_first_of(':');
			if (pos != -1)
			{
				std::string temp = instructionList[i].substr(0, pos - 1);
				if (aux4 == temp)
				{
					linea = i;
					break;
				}
			}
		}

		operand = dir01;
		operand <<= 8;
		operand += dir02;
		operand <<= 8;
		for (sc_uint<4> i = 0; i < 8; i++)
			operand[i] = linea[i];
		operand <<= 8;

		if (aux == "beq")
			insN = 14;
		else if (aux == "bne")
			insN = 15;

		operand += insN;
		operationOut.write(operand);
	}
}

void InstructionMemory::operation()
{
	if (instructionNumberIn.read() >= 0 and instructionNumberIn.read() < numberOfInstructions)
		list(instructionList[instructionNumberIn.read()]);
	else
		sc_stop();
}