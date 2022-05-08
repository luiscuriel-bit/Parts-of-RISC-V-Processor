#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout<<"Modulo : MEM_WB (IN)------------------------\n";
  cout<<"  Wb_MemtoRegIn :"<<  Wb_MemtoRegIn.read()<<"\n";
  cout<<"  Wb_RegWriteIn :"<<  Wb_RegWriteIn.read()<<"\n";
  cout<<"  memo_In[0] (dataMemory_MemWb):"<<  memo_In[0].read().to_string()<<"\n";
  cout<<"  memo_In[1] (exMem_dataMemoryAddress_MemWb):"<<  memo_In[1].read().to_string()<<"\n";
  cout<<"  dir_In :"<<  dir_In.read().to_string()<<"\n";
  cout<<endl;  
  cout << "Modulo: EX MEM (OUT)------------------------\n";
  cout << "  aIWb_MemtoRegOutn :" << Wb_MemtoRegOut.read() << "\n"; 
  cout << "  Wb_RegWriteOut :" << Wb_RegWriteOut.read() << "\n";    
  cout << "  memo_Out[0] (MemWb_muxWb1):" << memo_Out[0].read().to_string() << "\n";
  cout << "  memo_Out[1] (MemWb_muxWb2):" << memo_Out[1].read().to_string() << "\n";
  cout << "  dir_Out :" << dir_Out.read().to_string() << "\n";
  cout << endl;

  cout << "\n";
}


void Testbench::test() {


  int b[] = {42,32,53,74,10, 1,16};
  int a[] = { 4, 2, 10, 5,10,12,176};
  for(int i = 0; i < 4; i++){
   cout << "##############################################################################\n";
   
   memo_In[(i % 2)].write(a[i]);
    dir_In.write(b[i] % 32);
    Wb_MemtoRegIn.write((i + 1) % 2);
    Wb_RegWriteIn.write((i + 1) % 2); 
    wait();
    print();    
  }



  
  sc_stop();
}
