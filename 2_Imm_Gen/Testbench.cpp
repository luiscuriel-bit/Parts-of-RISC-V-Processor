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

	IF_IDOut.write(7);
	wait();
	wait();
//	wait();
//	wait();
	print();
	sc_stop();
}

void Testbench::print() {
	std::cout << "\n\n-----------------------------------\n";
	std::cout << "Tiempo       IF_IDOut       ID_EXIn" << endl;
	std::cout << "-----------------------------------\n";
	std::cout << std::setw(6) << sc_time_stamp();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(6) << IF_IDOut.read();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(8) << ID_EXIn.read();
	std::cout << std::setw(6) << "";
	std::cout << "\n";
}