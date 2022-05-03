#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout << "Tiempo   cl  D1In  D2In  | D1Out  D2Out  | C1In | C1Out |\n";
  cout << setw(4) << sc_time_stamp();
  cout << setw(3) << "";

  cout << setw(3) << clkIn.read();
  cout << setw(3) << "";  
  for(int i = 0; i < 2; i++){
    cout << setw(3) << memo_In[i].read().to_string() ;
    cout << setw(3) << "";
  }  
  for(int i = 0; i < 2; i++){
    cout << setw(4) << memo_Out[i].read().to_string() ;
    cout << setw(4) << "";
  }    
  cout << setw(3) << dir_In.read().to_string() ;
  cout << setw(3) << "";
    
  cout << setw(4) << dir_Out.read().to_string() ;
  cout << setw(4) << "";
  cout<<endl;
  cout<< "  Wb1In  Wn2Out | Wb1In  Wn2Out |\n";





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


  int b[] = { 42, 32, 53, 74,10,1,16};
  int a[] = { 4, 2, 3, 4,10,12,176};
  for(int i = 0; i < 2; i++){
   cout << "##############################################################################\n";
   
    memo_Out[i].write(a[i]);
    dir_Out.write(b[i]);

    Wb_MemtoRegOut.write((i + 1) % 2);
    Wb_no_ideaOut.write((i + 1) % 2); 
    wait();
    print();    
  }



  
  sc_stop();
}
