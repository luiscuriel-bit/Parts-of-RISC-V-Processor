#include "3_ALU.h"

ALU::ALU(sc_module_name nm) : sc_module(nm), number_1In("number_1In"), number_2In("number_2In"), resultOut("resultOut") /*, */ /*clk("clk")*/
{
	SC_METHOD(operation);
	sensitive << number_1In << number_2In << insIn;
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

void ALU::operation()
{

	if (insIn.read() == 1)
	{
		resultOut.write(number_1In.read() + number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 2)
	{
		resultOut.write(number_1In.read() - number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 3)
	{
		resultOut.write(number_1In.read() + number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 4)
	{
		int aux1 = number_1In.read();
		int aux2 = number_2In.read();
		resultOut.write(aux1 <<= aux2);
		zeroOut.write(0);
	}
	if (insIn.read() == 5)
	{
		int aux1 = number_1In.read();
		int aux2 = number_2In.read();
		resultOut.write(aux1 >>= aux2);
		zeroOut.write(0);
	}
	if (insIn.read() == 6)
	{
		int aux1 = number_1In.read();
		int aux2 = number_2In.read();
		resultOut.write(aux1 <<= aux2);
		zeroOut.write(0);
	}
	if (insIn.read() == 7)
	{
		int aux1 = number_1In.read();
		int aux2 = number_2In.read();
		resultOut.write(aux1 >>= aux2);
		zeroOut.write(0);
	}
	if (insIn.read() == 8)
	{
		resultOut.write(number_1In.read() + number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 9)
	{
		resultOut.write(number_1In.read() + number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 10)
	{
		resultOut.write(number_1In.read() & number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 11)
	{
		resultOut.write(number_1In.read() | number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 12)
	{
		resultOut.write(number_1In.read() & number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 13)
	{
		resultOut.write(number_1In.read() | number_2In.read());
		zeroOut.write(0);
	}
	if (insIn.read() == 14)
	{
		resultOut.write(number_1In.read() == number_2In.read());
		zeroOut.write(number_1In.read() == number_2In.read());
	}
	if (insIn.read() == 15)
	{
		resultOut.write(number_1In.read() != number_2In.read());
		zeroOut.write(number_1In.read() != number_2In.read());
	}
	if (insIn.read() == 16)
	{
		resultOut.write(number_1In.read() + number_2In.read());
		zeroOut.write(1);
	}
}
