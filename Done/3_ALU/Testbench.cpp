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
  cout << setw(4) << send_number_1Out.read().to_string() ;
  cout << setw(4) << "";
  cout << setw(4) << send_number_2Out.read().to_string();
  cout << setw(4) << "";
  cout << setw(4) << numberIn.read().to_string();
  cout << setw(4) << "";

  cout << "\n";
}


void Testbench::test() {
  cout << "Tiempo    intA    intB    \n";
  cout << "----------------------------------------------------------------------------------\n";



  int a[] = {-4, 14, 4, 2,8,1,-16};
  int b[] = {8, 12, 5, 3,2,-2,-15};
  
  for (int j = 0; j < 7; j++) {
    insOut.write(j+10);
    send_number_1Out.write(a[j]);
    send_number_2Out.write(b[j]);
    wait();
    wait();
    print();    
    cout << "---------------------------------------------------------------------------------\n";
  }
  sc_stop();
}
