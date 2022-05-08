#include "3_ALU_Control_Unit.h"

ALU_CONTROL::ALU_CONTROL(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << Ex_ALUOpIn << dir_In;
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

void ALU_CONTROL::operation()
{
	instruction_aluOut.write(dir_In.read());
}
