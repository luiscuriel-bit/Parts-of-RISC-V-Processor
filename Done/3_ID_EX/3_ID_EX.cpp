#include "3_ID_EX.h"

id_ex::id_ex(sc_module_name nm) : sc_module(nm)
{
	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void id_ex::operation()
{
	for (int i = 0; i < 2; i++)
		memo_Out[i].write(memo_In[i].read());

	id_ex1Out.write(id_ex1In.read());
	id_ex2Out.write(id_ex2In.read());

	Imm_gen1Out.write(Imm_genIn.read());
	Imm_gen2Out.write(Imm_genIn.read());

	Ex_ALUSrcOut.write(Ex_ALUSrcIn.read());
	Ex_ALUOpOut.write(Ex_ALUOpIn.read());

	Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
	Mem_BranchOut.write(Mem_BranchIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}