#include "Testbench.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn), clk("clk"), aIn("aIn"), bIn("bIn"), raOut("raOut"), rbOut("rbOut"), rwOut("rwOut"), wOut("wOut"), weOut("weOut")
{
	SC_THREAD(test);
	sensitive << clk;
}

void Testbench::test()
{
	srand(time(NULL));
	sc_uint<32> a;

	a = rand() % 100;

	rwOut.write(5);
	weOut.write(true);
	wOut.write(a);
	wait();

	print1();
	raOut.write(5);
	weOut.write(false);
	wait();
	print2();
	wait();
	print2();
	wait();
	print2();

	sc_stop();
}

void Testbench::print1()
{
	std::cout << "\n\n\nEscribiendo...\n";
	std::cout << sc_time_stamp() << '\n';
	std::cout << "\n\n------------------------------\n";
	std::cout << "rwOut           w          we\n";
	std::cout << "------------------------------\n";
	std::cout << std::setw(5) << rwOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(6) << wOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(6) << weOut.read();
	std::cout << std::setw(6) << "\n";
}

void Testbench::print2()
{
	std::cout << "\n\n\nLeyendo...\n";
	std::cout << sc_time_stamp() << '\n';
	std::cout << "\n\n----------\n";
	std::cout << "ra       a\n";
	std::cout << "----------\n";
	std::cout << std::setw(2) << raOut.read();
	std::cout << std::setw(2) << "";
	std::cout << std::setw(6) << aIn.read();
	std::cout << std::setw(6) << "\n";
}