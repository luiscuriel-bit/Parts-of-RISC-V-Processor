#ifndef INSTRUCTIONMEMORY_H
#define INSTRUCTIONMEMORY_H

#include <systemc.h>
#include <fstream>
#include <string>

class InstructionMemory : public sc_module
{

public:
	sc_in_clk clk;
	sc_in<sc_int<32>> instructionNumberIn;
	sc_out<sc_int<32>> operationOut;

	SC_CTOR(InstructionMemory);
private:
	sc_int<32> numberOfInstructions, operand;
	std::string *instructionList;

	void operation();
	void list(std::string);
};

#endif
