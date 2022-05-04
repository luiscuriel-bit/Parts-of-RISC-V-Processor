#include "Testbench.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), number_1Out("number_1Out"), number_2Out("number_2Out"), resultIn("resultIn")
{
	SC_THREAD(test);
	sensitive << clk;
}

void Testbench::test()
{
	srand(time(NULL));
	sc_int<32> a, b;

	std::cout << " Time    number_1Out    number_2Out    resultIn\n";
	std::cout << "-----------------------------------------------\n";

	for (int i = 0; i < 10; i++)
	{
		a = rand() % 200;
		b = a * 2;
		number_1Out.write(a);
		number_2Out.write(b);
		wait();
		print();
	}

	std::cout << "-----------------------------------------------\n";

	sc_stop();
}

void Testbench::print()
{
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(15) << number_1Out.read().to_string();
	std::cout << std::setw(15) << number_2Out.read().to_string();
	std::cout << std::setw(12) << resultIn.read().to_string() << '\n';
}