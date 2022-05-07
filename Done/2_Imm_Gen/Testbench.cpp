#include "Testbench.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {

	SC_THREAD(operation);
	sensitive << clk;
	dont_initialize();

}

void Testbench::operation(){

	for(int i = 0; i < 5; i++){
		IF_IDOut.write(i+i*i);
		wait();
		print();
	}
	sc_stop();
}

void Testbench::print() {
	std::cout << "\n----------------------------------------\n";
	std::cout << "Tiempo       Imm_GenOut       Imm_GenIn" << endl;
	std::cout << "----------------------------------------\n";
	std::cout << std::setw(6) << sc_time_stamp();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(8) << IF_IDOut.read();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(12) << ID_EXIn.read();
	std::cout << std::setw(6) << "";
	std::cout << "\n";
}