#include "5_MEM_WB.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  MEM_WB me_wb("me_wb");
  Testbench tb("tb");


  sc_signal<bool> clkIn;

  sc_signal<bool> Wb_MemtoReg_1, Wb_RegWrite_1 ;
  sc_signal<sc_int<32>> memo_1[2];
  sc_signal<sc_uint<5>> dir_1;

  sc_signal<bool> Wb_MemtoReg_2, Wb_RegWrite_2 ;
  sc_signal<sc_int<32>> memo_2[2];
  sc_signal<sc_uint<5>> dir_2;



  me_wb.Wb_MemtoRegIn(Wb_MemtoReg_1), me_wb.Wb_RegWriteIn(Wb_RegWrite_1) ;
  me_wb.Wb_MemtoRegOut(Wb_MemtoReg_2), me_wb.Wb_RegWriteOut(Wb_RegWrite_2) ;
  me_wb.dir_In(dir_1);
  me_wb.dir_Out(dir_2);

  for(int i = 0; i< 2; i++){
    me_wb.memo_In[i](memo_1[i]);
  } 

  
  for(int i = 0; i< 2; i++){
    me_wb.memo_Out[i](memo_2[i]);
  } 
  
  

  tb.Wb_MemtoRegIn(Wb_MemtoReg_1), tb.Wb_RegWriteIn(Wb_RegWrite_1) ;
  tb.Wb_MemtoRegOut(Wb_MemtoReg_2), tb.Wb_RegWriteOut(Wb_RegWrite_2) ;
  tb.dir_In(dir_1);
  tb.dir_Out(dir_2);

  for(int i = 0; i< 2; i++){
    tb.memo_In[i](memo_1[i]);
  } 

  for(int i = 0; i< 2; i++){
    tb.memo_Out[i](memo_2[i]);
  } 

  me_wb.clkIn(clock);
  tb.clkIn(clock);

  sc_start();

  return 0;
}
