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
  cout << setw(5) << send_number_1Out.read().to_string() ;
  cout << setw(4) << "";
  cout << setw(12) << send_number_2Out.read().to_string();
  cout << setw(4) << "";
  cout << setw(10) << numberIn.read().to_string();
  cout << setw(4) << "";

  cout << "\n";
}


void Testbench::test() {
  cout << "Tiempo    number_1Out    number_2Out    ResultIn\n";
  cout << "----------------------------------------------------------------------------------\n";
  
  for (int j = 0; j < 15; j++) {
    insOut.write(j+1);
    send_number_1Out.write(j);
    send_number_2Out.write(14-j);
    wait();
    wait();
    print();    
    cout << "---------------------------------------------------------------------------------\n";
  }
  sc_stop();
}
