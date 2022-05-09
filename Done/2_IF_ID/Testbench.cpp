#include "Testbench.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

Testbench::Testbench(sc_module_name mn) : sc_module(mn)
{

	SC_THREAD(operation);
	sensitive << clk;
	dont_initialize();
}

void Testbench::operation()
{
	pcOut.write(0);
	insMemOut.write(537206379);
	wait();
	wait();
	print();

	pcOut.write(1);
	insMemOut.write(16387011);
	wait();
	wait();
	print();

	pcOut.write(2);
	insMemOut.write(4734);
	wait();
	wait();
	print();

	pcOut.write(3);
	insMemOut.write(529145);
	wait();
	wait();
	print();
	sc_stop();
}

void Testbench::print()
{

	std::cout << "\n\n-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << "Tiempo       pcIn       fileRegister1Out      fileRegister2Out       immGenOut       ID_EX0Out       ID_EX1Out       ID_unidadControl       ID_EX2Out" << endl;
	std::cout << "-----------------------------------------------------------------------------------------------------------------------------------------------------\n";
	std::cout << std::setw(6) << sc_time_stamp();
	std::cout << std::setw(11) << pcOut.read();
	std::cout << std::setw(23) << fileRegister1In.read();
	std::cout << std::setw(22) << fileRegister2In.read();
	std::cout << std::setw(16) << immGenIn.read();
	std::cout << std::setw(16) << ID_EX0In.read();
	std::cout << std::setw(16) << ID_EX1In.read();
	std::cout << std::setw(23) << ID_unidadControlIn.read();
	std::cout << std::setw(16) << ID_EX2In.read() << "\n";
}