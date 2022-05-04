#include "2_Control_Unit.h"

Unidad_Control::Unidad_Control(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << dir_In;
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

void Unidad_Control::operation()
{
	Ex_ALUOpOut.write(3);

	if (dir_In.read() == 1)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 2)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 3)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 4)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 5)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 6)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 7)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 8)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(1);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Wb_MemtoRegOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	else
		Wb_MemtoRegOut.write(1);
	if (dir_In.read() == 9)
	{
		Wb_RegWriteOut.write(0);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(1);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 10)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 11)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 12)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 13)
	{
		Wb_RegWriteOut.write(1);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(0);
		Ex_ALUSrcOut.write(1);
	}
	if (dir_In.read() == 14)
	{
		Wb_RegWriteOut.write(0);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(1);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 15)
	{
		Wb_RegWriteOut.write(0);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(1);
		Ex_ALUSrcOut.write(0);
	}
	if (dir_In.read() == 16)
	{
		Wb_RegWriteOut.write(0);
		Mem_MemReadOut.write(0);
		Mem_MemWriteOut.write(0);
		Mem_BranchOut.write(1);
		Ex_ALUSrcOut.write(1);
	}
}
