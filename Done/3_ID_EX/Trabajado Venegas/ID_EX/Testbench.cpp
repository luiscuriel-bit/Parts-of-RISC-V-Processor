#include "Testbench.h"
#include <iomanip>
using namespace std;

Testbench::Testbench(sc_module_name mn) : sc_module(mn) {
  SC_THREAD(test);
  sensitive << clkIn;
  dont_initialize();
}
void Testbench::print() {
  cout << "Modulo: IF ID (IN)------------------------\n";
  cout << " Ex_ALUSrcIn  :" << Ex_ALUSrcIn.read() << "\n";
  cout << " Mem_MemWriteIn  :" << Mem_MemWriteIn.read() << "\n";
  cout << " Mem_MemReadIn  :" << Mem_MemReadIn.read() << "\n";
  cout << " Mem_BranchIn  :" << Mem_BranchIn.read() << "\n";
  cout << " Wb_MemtoRegIn  :" << Wb_MemtoRegIn.read() << "\n";
  cout << " Wb_RegWriteIn  :" << Wb_RegWriteIn.read() << "\n";
  cout << " Ex_ALUOpIn  :" << Ex_ALUOpIn.read().to_string() << "\n";
  cout << " Imm_genIn  :" << Imm_genIn.read().to_string() << "\n";
  cout << " id_ex0In  :" << id_ex0In.read().to_string() << "\n";
  cout << " id_ex1In  :" << id_ex1In.read().to_string() << "\n";
  cout << " id_ex2In  :" << id_ex2In.read().to_string() << "\n";
  cout << " memo_In[0] (REGISTRO DATA 1) :" << memo_In[0].read().to_string() << "\n";
  cout << " memo_In[1] (REGISTRO DATA 2) :" << memo_In[1].read().to_string() << "\n";
  cout<<"\n";

  cout << "Modulo: IF ID (OUT)------------------------\n";
  cout << "  Ex_ALUSrcOut :" << Ex_ALUSrcOut.read() << "\n";
  cout << "  Ex_ALUOpOut :" << Ex_ALUOpOut.read().to_string() << "\n";
  cout << "  Mem_MemWriteOut :" << Mem_MemWriteOut.read() << "\n";
  cout << "  Mem_MemReadOut :" << Mem_MemReadOut.read() << "\n";
  cout << "  Mem_BranchOut :" << Mem_BranchOut.read() << "\n";
  cout << "  Wb_MemtoRegOut :" << Wb_MemtoRegOut.read() << "\n";
  cout << "  Wb_RegWriteOut :" << Wb_RegWriteOut.read() << "\n";
  cout << "  Imm_gen1Out :" << Imm_gen1Out.read().to_string() << "\n";
  cout << "  Imm_gen2Out :" << Imm_gen2Out.read().to_string() << "\n";
  cout << "  id_ex0Out :" << id_ex0Out.read().to_string() << "\n";
  cout << "  id_ex1Out :" << id_ex1Out.read().to_string() << "\n";
  cout << "  id_ex2Out :" << id_ex2Out.read().to_string() << "\n";
  cout << "  memo_Out[0] (REGISTRO DATA 1) :" << memo_Out[0].read().to_string() << "\n";
  cout << "  memo_Out[1] (REGISTRO DATA 2):" << memo_Out[1].read().to_string() << "\n";
  cout << "\n";



}


void Testbench::test() {


  int b[] = { 42, 32, 53, 74,10,1,16,12,1};
  int a[] = { 4, 2, 3, 4, 10,12,176,2,9,3};
  for(int i = 0; i < 4; i++){
    cout << "##############################################################################\n";
   
    memo_In[(i) % 2].write(a[i]);
    Imm_genIn.write(a[i + 2]);
    id_ex0In.write(b[i + 2] % 32);
    id_ex1In.write(b[i + 4] % 32);
    id_ex2In.write(b[i + 3] % 32);
    Ex_ALUSrcIn.write((i + 1) % 2);
    Ex_ALUOpIn.write((i + 1) % 2);;
    Mem_MemWriteIn.write((i + 1) % 2); 
    Mem_MemReadIn.write((i + 1) % 2);
    Mem_BranchIn.write((i + 1) % 2);
    Wb_MemtoRegIn.write((i + 1) % 2);
    Wb_RegWriteIn.write((i + 1) % 2);
    wait();
    print();    
  }



  
  sc_stop();
}
