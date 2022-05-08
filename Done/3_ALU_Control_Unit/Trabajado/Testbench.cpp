#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clk;
  dont_initialize();
}
void Testbench::print() {
  cout << setw(6) << sc_time_stamp();
  cout << setw(4) << "";
  cout << setw(5) << Ex_ALUOpOut.read().to_string() ;
  cout << setw(4) << "";
  cout << setw(12) << dir_Out.read().to_string();
  cout << setw(4) << "";
  cout << setw(14) << instruction_aluIn.read().to_string();
  cout << setw(4) << "";

  cout << "\n";
}


void Testbench::test() {
  cout << "Tiempo    ALU_OpOut    Instruction_Out    Instruction_In\n";
  cout << "----------------------------------------------------------------------------------\n";
  
  for (int j = 0; j < 15; j++) {
    Ex_ALUOpOut.write(3);
    dir_Out.write(j+1);
    wait();
    wait();
    print();    
    cout << "---------------------------------------------------------------------------------\n";
  }
  sc_stop();
}
