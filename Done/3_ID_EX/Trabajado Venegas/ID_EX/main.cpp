#include "3_ID_EX.h"
#include "Testbench.h"


int sc_main(int argv, char* argc[]) {
  sc_time period(10,SC_NS);
  sc_time delay(10,SC_NS);

  sc_clock clock("clock", period, 0.5, delay, true);

  id_ex id_ex("id_ex");
  Testbench tb("tb");


  sc_signal<bool> clkIn;
  sc_signal<bool> Ex_ALUSrc_1;
  sc_signal<sc_uint<2>> Ex_ALUOp_1;
  sc_signal<bool> Mem_MemWrite_1, Mem_MemRead_1, Mem_Branch_1;
  sc_signal<bool> Wb_MemtoReg_1, Wb_RegWrite_1 ;
  sc_signal<sc_int<32>> memo_1[2];


  sc_signal<bool> Ex_ALUSrc_2;
  sc_signal<sc_uint<2>> Ex_ALUOp_2;
  sc_signal<bool> Mem_MemWrite_2, Mem_MemRead_2, Mem_Branch_2;
  sc_signal<bool> Wb_MemtoReg_2, Wb_RegWrite_2 ;
  sc_signal<sc_int<32>> memo_2[2];

  sc_signal<sc_int<32>> Imm_gen_1;
  sc_signal<sc_int<32>> id_ex0_1;
  sc_signal<sc_uint<5>> id_ex1_1;
  sc_signal<sc_uint<5>> id_ex2_1; 

  sc_signal<sc_int<32>> Imm_gen1_2;
  sc_signal<sc_int<32>> Imm_gen2_2;
  sc_signal<sc_int<32>> id_ex0_2;
  sc_signal<sc_uint<5>> id_ex1_2;
  sc_signal<sc_uint<5>> id_ex2_2; 

  id_ex.Ex_ALUSrcIn(Ex_ALUSrc_1), id_ex.Ex_ALUOpIn(Ex_ALUOp_1);
  id_ex.Mem_MemWriteIn(Mem_MemWrite_1), id_ex.Mem_MemReadIn(Mem_MemRead_1), id_ex.Mem_BranchIn(Mem_Branch_1);
  id_ex.Wb_MemtoRegIn(Wb_MemtoReg_1), id_ex.Wb_RegWriteIn(Wb_RegWrite_1) ;

  id_ex.Imm_genIn(Imm_gen_1);
  id_ex.id_ex0In(id_ex0_1);
  id_ex.id_ex1In(id_ex1_1);
  id_ex.id_ex2In(id_ex2_1); 

  id_ex.Imm_gen1Out(Imm_gen1_2);
  id_ex.Imm_gen2Out(Imm_gen2_2);
  id_ex.id_ex0Out(id_ex0_2);
  id_ex.id_ex1Out(id_ex1_2);
  id_ex.id_ex2Out(id_ex2_2);

  id_ex.Ex_ALUSrcOut(Ex_ALUSrc_2), id_ex.Ex_ALUOpOut(Ex_ALUOp_2);
  id_ex.Mem_MemWriteOut(Mem_MemWrite_2), id_ex.Mem_MemReadOut(Mem_MemRead_2), id_ex.Mem_BranchOut(Mem_Branch_2);
  id_ex.Wb_MemtoRegOut(Wb_MemtoReg_2), id_ex.Wb_RegWriteOut(Wb_RegWrite_2) ;



  for(int i = 0; i< 2; i++){
    id_ex.memo_In[i](memo_1[i]);
  } 


  for(int i = 0; i< 2; i++){
    id_ex.memo_Out[i](memo_2[i]);
  } 




  tb.Ex_ALUSrcIn(Ex_ALUSrc_1), tb.Ex_ALUOpIn(Ex_ALUOp_1);
  tb.Mem_MemWriteIn(Mem_MemWrite_1), tb.Mem_MemReadIn(Mem_MemRead_1), tb.Mem_BranchIn(Mem_Branch_1);
  tb.Wb_MemtoRegIn(Wb_MemtoReg_1), tb.Wb_RegWriteIn(Wb_RegWrite_1) ;

  tb.Imm_genIn(Imm_gen_1);
  tb.id_ex0In(id_ex0_1);
  tb.id_ex1In(id_ex1_1);
  tb.id_ex2In(id_ex2_1); 

  tb.Imm_gen1Out(Imm_gen1_2);
  tb.Imm_gen2Out(Imm_gen2_2);
  tb.id_ex0Out(id_ex0_2);
  tb.id_ex1Out(id_ex1_2);
  tb.id_ex2Out(id_ex2_2);

  tb.Ex_ALUSrcOut(Ex_ALUSrc_2), tb.Ex_ALUOpOut(Ex_ALUOp_2);
  tb.Mem_MemWriteOut(Mem_MemWrite_2), tb.Mem_MemReadOut(Mem_MemRead_2), tb.Mem_BranchOut(Mem_Branch_2);
  tb.Wb_MemtoRegOut(Wb_MemtoReg_2), tb.Wb_RegWriteOut(Wb_RegWrite_2) ;

  for(int i = 0; i< 2; i++){
    tb.memo_In[i](memo_1[i]);
  } 


  for(int i = 0; i< 2; i++){
    tb.memo_Out[i](memo_2[i]);
  } 



  id_ex.clkIn(clock);

  tb.clkIn(clock);

  sc_start();

  return 0;
}
