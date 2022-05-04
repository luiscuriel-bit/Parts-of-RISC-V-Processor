#include "4_EX_MEM.h"

EX_MEM::EX_MEM(sc_module_name nm) : sc_module(nm)
{

	SC_METHOD(operation);
	sensitive << clkIn.pos();
}

void EX_MEM::operation()
{

	//std:: cout << "\n\n\n\n\n\nEXMEM DEL SUM TENGO: " << memo_In[0].read() << "\n\n\n\n\n\n\n"; 
	for (int i = 0; i < 3; i++){
		memo_Out[i].write(memo_In[i].read());
	}
	memo_Out[3].write(memo_In[1].read());//esto es para pasar la ramificacion que se hace en mem
											 //debido a que como ya se dvide el cable para dirigirlo a 
											 //el testbench no se puede dividir mas

	dir_Out.write(dir_In.read());

	alu_to_brachOut.write(alu_to_brachIn.read());
	Mem_MemWriteOut.write(Mem_MemWriteIn.read());
	Mem_MemReadOut.write(Mem_MemReadIn.read());
	Mem_BranchOut.write(Mem_BranchIn.read());
	Wb_MemtoRegOut.write(Wb_MemtoRegIn.read());
	Wb_RegWriteOut.write(Wb_RegWriteIn.read());
}
