#include "Testbench.h"
#include <iomanip>
#include <ctime>
#include <cstdlib>

Testbench::Testbench(sc_module_name mn) : sc_module(mn), adressOut("adressOut"), operationIn("operationIn")
{

	SC_THREAD(operation);
	sensitive << clk;
	dont_initialize();
}

void Testbench::operation()
{
	adressOut.write(0);
	wait();
	wait();
	wait();
	wait();

	std::cout << sc_time_stamp() << '\n';
	/*	int i = 255;
		int aux = operationIn.read() & i;
		std::cout << aux << endl;
		i = 65280;
		//	i= 65535;
		aux = operationIn.read() & i;
		std::cout << aux << endl;
		i = 16711680;
		//	i = 4080;
		aux = operationIn.read() & i;
		std::cout << aux << endl;
		i = 4278190080;
		aux = operationIn.read() & i;
		std::cout << aux << endl;

		std::cout << "\n"
				  << operationIn.read() << endl;
	*/
	/*
		for(int g=0;g<32;g++){
			std:: cout << operationIn.read()[g];
			if((g+1)%8==0)std:: cout << "   ";
		}

		std:: cout<< "\nAl reves" << endl;*/

	std::cout << "\n\nOperacion 1\n";
	for (int g = 31; g >= 0; g--)
	{
		std::cout << operationIn.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	/*for(int i=0;i<32;i++){
		std::cout << operationIn.read()[i];
		if(8%i==0) std::cout << "   ";
	}*/

	// test 2

	adressOut.write(1);
	wait();
	wait();
	wait();
	wait();

	std::cout << "\n\nOperacion 2\n"
			  << endl;

	for (int g = 31; g >= 0; g--)
	{
		std::cout << operationIn.read()[g];
		if (g % 8 == 0)
			std::cout << "   ";
	}

	sc_stop();
}
//
// void Testbench::print() {
//	std::cout << "\n\n------------------------------------------------------------------------------------------------------------\n";
//	std::cout << "Tiempo       cpOut       insMemOut       r1In      r2In       ID_EXIn       ins1In       ins2In       ins3In" << endl;
//	std::cout << "------------------------------------------------------------------------------------------------------------\n";
//	std::cout << std::setw(6) << sc_time_stamp();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(6) << cpOut.read();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(8) << insMemOut.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << register1In.read();
//	std::cout << std::setw(5) << "";
//	std::cout << std::setw(6) << register2In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << ID_EXIn.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction1In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction2In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << std::setw(7) << instruction3In.read();
//	std::cout << std::setw(6) << "";
//	std::cout << "\n";
//}