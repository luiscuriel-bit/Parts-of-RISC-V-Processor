#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);

  sensitive << clkIn;
  dont_initialize();
}

void Testbench::print() {
cout<<"################################################################################\n";  
  cout << "Tiempo    address    write_data    read_data     Men_write      Men_read     clock \n";

  cout << setw(6) << sc_time_stamp();
  cout << setw(4) << "";
  cout << setw(4) << addressOut.read();
  cout << setw(8) << "";
  cout << setw(4) << write_dataOut.read();
  cout << setw(8) << "";
  cout << setw(4) << read_dataIn.read();      
  cout << setw(8) << "";
  cout << setw(4) << writeOut.read();
  cout << setw(12) << "";
  cout << setw(4) << readOut.read(); 
  cout << setw(8) << "";

  cout << setw(4) << clkIn.read();

  cout << "\n";  
 
}

void Testbench::test() {

  	cout << "----------------------------------------------------------------------------\n";
    cout << "----------------------------------------------------------------------------\n";


    int dir[5] = {1, 1, 12, 12,20};
    int dat[5] = {900, 0,93, 0, 89};
    //int pass[5] = {1, 1,1, 1, 1};

    for (int j = 0; j < 5;j++) {
      write_dataOut.write(dat[j]);
      addressOut.write(dir[j]); 
      readOut.write(true);            
      writeOut.write(true);            
      wait();
      print();
    }
  
  sc_stop();
}
