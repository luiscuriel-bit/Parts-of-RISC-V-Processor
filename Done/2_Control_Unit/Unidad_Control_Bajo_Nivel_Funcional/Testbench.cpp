#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {

  cout<< "Tiempo | dir_Out | ExALUOpIn | ExALUSrcIn | MenWriteIn | MenReadIn | MenBranchIn | WbMemtoRegIn | WbRegWriteIn |\n";

  cout << setw(5) << 	sc_time_stamp();
  cout << setw(4) << "";
  
  cout << setw(5) << dir_Out.read();
  cout << setw(4) << "";

  cout << setw(6) << Ex_ALUOpIn.read();
  cout << setw(6) << "";

  cout << setw(7) << Ex_ALUSrcIn.read();
  cout << setw(6) << "";

  cout << setw(7) << Mem_MemWriteIn.read(); 
  cout << setw(6) << "";

  cout << setw(7) << Mem_MemReadIn.read();
  cout << setw(6) << "";

  cout << setw(7) << Mem_BranchIn.read();
  cout << setw(6) << "";

  cout << setw(7) << Wb_MemtoRegIn.read();
  cout << setw(6) << "";

  cout << setw(9) << Wb_RegWriteIn.read();
  cout << setw(6) << "";


  cout << "\n\n";
}


void Testbench::test() {

//  wait();
  for(int i = 0; i < 15; i++){
   cout << "################################################################################################################\n";
   
    dir_Out.write(i+1);
    wait();
    wait();
    wait();
    // wait();

    print();    

  }

  sc_stop();
}
