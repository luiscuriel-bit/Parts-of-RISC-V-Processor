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

	cpOut.write(3);
	insMemOut.write(5);
	wait();
	wait();
//	wait();
//	wait();
	print();
	sc_stop();
}

void Testbench::print() {
	std::cout << "\n\n------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Tiempo       cpOut       insMemOut       r1In      r2In       ID_EXIn       ins1In       ins2In       ins3In" << endl;
	std::cout << "------------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(6) << sc_time_stamp();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(6) << cpOut.read();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(8) << insMemOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(7) << register1In.read();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(6) << register2In.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(7) << ID_EXIn.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(7) << instruction1In.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(7) << instruction2In.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(7) << instruction3In.read();
	std::cout << std::setw(6) << "";
	std::cout << "\n";
}