#include "Testbench.h"
#include <iomanip>
#include <cstdlib>
#include <ctime>

Testbench::Testbench(sc_module_name moduleName) : sc_module(moduleName), clk("clk"), instructionNumberOut("instructionNumberOut"), operationIn("operationIn")
{
	SC_THREAD(test);
	sensitive << clk;
}

void Testbench::test()
{
	std::cout << " Time    operand1    operand2    operand3    instruction\n";
	std::cout << "--------------------------------------------------------\n";




	// Si Instruction Memory es sensible a la entrada, la lectura de la linea 0 no la detecta, si no que es la lectura por defecto al principio del programa. Por esto, basta con colocar un wait acá y ya tendremos la lectura de la primera línea. En este caso, el for empezaría a partir de 1 (0 ya lo leyó)
	wait();
	for (int i = 31, j = 7; i >= 24; i--, j--)
		operand1[j] = operationIn.read()[i];

	for (int i = 23, j = 7; i >= 16; i--, j--)
		operand2[j] = operationIn.read()[i];

	for (int i = 15, j = 7; i >= 8; i--, j--)
		operand3[j] = operationIn.read()[i];

	for (int i = 7, j = 7; i >= 0; i--, j--)
		instruction[j] = operationIn.read()[i];

	print();




	for (int i = 1; i < 10; i++)
	//for (int i = 0; i < 10; i++)
	{
		instructionNumberOut.write(i);
		// Al estar sincronizado con reloj, el testbench debe esperar un ciclo completo para obtener respuesta de Instruction Memory, debido a la lectura y escritura sobre los puertos
		//wait();
		//wait

		wait();

		for (int i = 31, j = 7; i >= 24; i--, j--)
			operand1[j] = operationIn.read()[i];

		for (int i = 23, j = 7; i >= 16; i--, j--)
			operand2[j] = operationIn.read()[i];
		
		for (int i = 15, j = 7; i >= 8; i--, j--)
			operand3[j] = operationIn.read()[i];
		
		for (int i = 7, j = 7; i >= 0; i--, j--)
			instruction[j] = operationIn.read()[i];

		print();
	}

	std::cout << "--------------------------------------------------------\n";

	sc_stop();
}

void Testbench::print()
{
	std::cout << std::setw(5) << sc_time_stamp();
	std::cout << std::setw(12) << operand1.to_string();
	std::cout << std::setw(12) << operand2.to_string();
	std::cout << std::setw(12) << operand3.to_string();
	std::cout << std::setw(15) << instruction.to_string() << '\n';
}