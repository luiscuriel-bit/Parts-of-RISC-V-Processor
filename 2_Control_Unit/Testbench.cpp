#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {

  cout<< "Ex1In  Ex11Out | Ex2In  Ex21Out | Men1In Men1Out | Men2In Men2Out | Men3In Men3Out | Wb1In  Wn2Out | Wb1In  Wn2Out |\n";
  cout << setw(5) << Ex_ALUSrcIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Ex_ALUSrcOut.read();
  cout << setw(4) << "";

  cout << setw(4) << Ex_ALUOpIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Ex_ALUOpOut.read();
  cout << setw(4) << "";

  cout << setw(4) << Men_MemWriteIn.read(); 
  cout << setw(4) << "";
  cout << setw(4) << Men_MemWriteOut.read(); 
  cout << setw(4) << "";

  cout << setw(4) << Men_MemReadIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Men_MemReadOut.read();
  cout << setw(4) << "";

  cout << setw(7) << Men_BranchIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Men_BranchOut.read();
  cout << setw(4) << "";

  cout << setw(4) << Wb_MemtoRegIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Wb_MemtoRegOut.read();
  cout << setw(4) << "";

  cout << setw(4) << Wb_no_ideaIn.read();
  cout << setw(4) << "";
  cout << setw(4) << Wb_no_ideaOut.read();
  cout << setw(4) << "";


  cout << "\n";
}


void Testbench::test() {
 // cout << "Tiempo   cl  D1In  D1Out | D2In  D2Out | C1In  C1Out | C2In C2Out | C3In  C3Out |\n";
//  cout << "##############################################################################\n";


 
  for(int i = 0; i < 2; i++){
   cout << "##############################################################################\n";
   

    Ex_ALUSrcOut.write((i + 1) % 2);
    Ex_ALUOpOut.write((i + 1) % 2);;
    Men_MemWriteOut.write((i + 1) % 2); 
    Men_MemReadOut.write((i + 1) % 2);
    Men_BranchOut.write((i + 1) % 2);
    Wb_MemtoRegOut.write((i + 1) % 2);
    Wb_no_ideaOut.write((i + 1) % 2);//ni idea para sirve sea esa señal de control    
    wait();
    print();    
  }



  
  sc_stop();
}
