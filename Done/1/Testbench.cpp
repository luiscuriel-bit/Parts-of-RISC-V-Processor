#include "Testbench.h"
#include <iomanip>

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName), clk("clk")
{
	SC_THREAD(test);
	sensitive << clk;
	dont_initialize();
}

void Testbench::test()
{
	wait();
	std::cout << " Time    uno\n";
	std::cout << "------------\n";
	print();
	std::cout << "------------\n";

	sc_stop();
}

void Testbench::print()
{
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(7) << unoIn.read().to_string() << '\n';
}