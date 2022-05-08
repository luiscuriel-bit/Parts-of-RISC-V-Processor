#include "Testbench.h"

Testbench::Testbench(sc_module_name mn) : sc_module(mn), clk("clk"), aIn("aIn"), bIn("bIn"), raOut("raOut"), rbOut("rbOut"), rwOut("rwOut"), wOut("wOut"), weOut("weOut")
{
	SC_THREAD(test);
	sensitive << clk;
	dont_initialize();
}

void Testbench::test()
{
	srand(time(NULL));
	sc_uint<32> a;

	std::cout << "\n\n\nEscribiendo...\n";
	for (int i = 0; i < 32; i++)
	{
		a = rand() % 100;
		rwOut.write(i);
		wOut.write(a);

		if (!i || a % 2 == 0)
			weOut.write(true);
		else
			weOut.write(false);

		wait();
		print1();
		wait();
	}


	wait();

	std::cout << "\n\n\nLeyendo...\n";

	for (int i = 0; i <= 30; i += 2)
	{
		raOut.write(i);
		rbOut.write(i + 1);

		wait();
		wait();
		print2();
	}

	sc_stop();
}

void Testbench::print1()
{
	std::cout << "\n\n" << sc_time_stamp() << '\n';
	std::cout << "------------------------------\n";
	std::cout << "rwOut           w          we\n";
	std::cout << "------------------------------\n";
	std::cout << std::setw(5) << rwOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(6) << wOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(6) << weOut.read();
	std::cout << std::setw(6) << "\n";
}

void Testbench::print2() {
	std::cout << "\n\n" << sc_time_stamp() << '\n';
	std::cout << "--------------------------------------\n";
	std::cout << "  ra          rb          a         b\n";
	std::cout << "--------------------------------------\n";
	std::cout << std::setw(6) << raOut.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(6) << rbOut.read();
	std::cout << std::setw(5) << "";
	std::cout << std::setw(5) << aIn.read();
	std::cout << std::setw(6) << "";
	std::cout << std::setw(4) << bIn.read();
	std::cout << std::setw(6) << "\n";
}