#include "2_Control_Unit.h"

Unidad_Control::Unidad_Control(sc_module_name nm) : sc_module(nm), dir_In("dir_In")/*, aux1("aux1"), aux2("axu2"), aux3("aux3"), aux4("aux4"), trueVal("trueVal"), falseVal("falseVal")*/
{

	Divider = new divider("Divider");	

	for (int i = 0; i < 15; i++)
	{
		and_gate[i].aIn(aInSg[i]);
		and_gate[i].bIn(bInSg[i]);
		and_gate[i].cIn(cInSg[i]);
		and_gate[i].dIn(dInSg[i]);
		and_gate[i].eOut(eOutSg[i]);
	}

	for (int i = 0, j = 0; i < 60; i+=4, j++)
	{
		aux[i](aInSg[j]);
		aux[i+1](bInSg[j]);
		aux[i+2](cInSg[j]);
		aux[i+3](dInSg[j]);
	}

	Divider->dir_In(dir_In);
	Divider->dir_In_0(dir_In_0);
	Divider->dir_In_1(dir_In_1);
	Divider->dir_In_2(dir_In_2);
	Divider->dir_In_3(dir_In_3);

//----------------------------------------
	Not_gate[0].Entrada1(dir_In_1);
	Not_gate[1].Entrada1(dir_In_2);
	Not_gate[2].Entrada1(dir_In_3);

	Not_gate[0].Salida1(not_to_and[0]);
	Not_gate[1].Salida1(not_to_and[1]);
	Not_gate[2].Salida1(not_to_and[2]);

//----------------------------------------

	Not_gate[3].Entrada1(dir_In_0);
	Not_gate[4].Entrada1(dir_In_2);
	Not_gate[5].Entrada1(dir_In_3);

	Not_gate[3].Salida1(not_to_and[3]);
	Not_gate[4].Salida1(not_to_and[4]);
	Not_gate[5].Salida1(not_to_and[5]);


//----------------------------------------

	Not_gate[6].Entrada1(dir_In_2);
	Not_gate[7].Entrada1(dir_In_3);

	Not_gate[6].Salida1(not_to_and[6]);
	Not_gate[7].Salida1(not_to_and[7]);

//----------------------------------------

	Not_gate[8].Entrada1(dir_In_0);
	Not_gate[9].Entrada1(dir_In_1);
	Not_gate[10].Entrada1(dir_In_3);

	Not_gate[8].Salida1(not_to_and[8]);
	Not_gate[9].Salida1(not_to_and[9]);
	Not_gate[10].Salida1(not_to_and[10]);

//----------------------------------------

	Not_gate[11].Entrada1(dir_In_1);
	Not_gate[12].Entrada1(dir_In_3);

	Not_gate[11].Salida1(not_to_and[11]);
	Not_gate[12].Salida1(not_to_and[12]);

//----------------------------------------

	Not_gate[13].Entrada1(dir_In_0);
	Not_gate[14].Entrada1(dir_In_3);

	Not_gate[13].Salida1(not_to_and[13]);
	Not_gate[14].Salida1(not_to_and[14]);

//----------------------------------------

	Not_gate[15].Entrada1(dir_In_3);

	Not_gate[15].Salida1(not_to_and[15]);

//----------------------------------------

	Not_gate[16].Entrada1(dir_In_0);
	Not_gate[17].Entrada1(dir_In_1);
	Not_gate[18].Entrada1(dir_In_2);

	Not_gate[16].Salida1(not_to_and[16]);
	Not_gate[17].Salida1(not_to_and[17]);
	Not_gate[18].Salida1(not_to_and[18]);

//----------------------------------------

	Not_gate[19].Entrada1(dir_In_1);
	Not_gate[20].Entrada1(dir_In_2);

	Not_gate[19].Salida1(not_to_and[19]);
	Not_gate[20].Salida1(not_to_and[20]);

//----------------------------------------

	Not_gate[21].Entrada1(dir_In_0);
	Not_gate[22].Entrada1(dir_In_2);

	Not_gate[21].Salida1(not_to_and[21]);
	Not_gate[22].Salida1(not_to_and[22]);


//----------------------------------------

	Not_gate[23].Entrada1(dir_In_2);

	Not_gate[23].Salida1(not_to_and[23]);

//----------------------------------------

	Not_gate[24].Entrada1(dir_In_0);
	Not_gate[25].Entrada1(dir_In_1);

	Not_gate[24].Salida1(not_to_and[24]);
	Not_gate[25].Salida1(not_to_and[25]);

//----------------------------------------
	Not_gate[26].Entrada1(dir_In_1);

	Not_gate[26].Salida1(not_to_and[26]);

//----------------------------------------

	Not_gate[27].Entrada1(dir_In_0);

	Not_gate[27].Salida1(not_to_and[27]);

//----------------------------------------

	not_gate2[0].Entrada1(eOutSg[7]);
	not_gate2[0].Salida1(not_gate2Out);

	//RegWrite

	or_gate[0].aIn(eOutSg[0]);
	or_gate[0].bIn(eOutSg[1]);
	or_gate[0].cOut(orCOut[0]);

	or_gate[1].aIn(eOutSg[2]);
	or_gate[1].bIn(eOutSg[3]);
	or_gate[1].cOut(orCOut[1]);

	or_gate[2].aIn(eOutSg[4]);
	or_gate[2].bIn(eOutSg[5]);
	or_gate[2].cOut(orCOut[2]);

	or_gate[3].aIn(eOutSg[6]);
	or_gate[3].bIn(eOutSg[7]);
	or_gate[3].cOut(orCOut[3]);

	or_gate[4].aIn(eOutSg[9]);
	or_gate[4].bIn(eOutSg[10]);
	or_gate[4].cOut(orCOut[4]);

	or_gate[5].aIn(eOutSg[11]);
	or_gate[5].bIn(eOutSg[12]); 
	or_gate[5].cOut(orCOut[5]);

	or_gate[6].aIn(orCOut[0]);
	or_gate[6].bIn(orCOut[1]);
	or_gate[6].cOut(orCOut[6]);

	or_gate[7].aIn(orCOut[2]);
	or_gate[7].bIn(orCOut[3]);
	or_gate[7].cOut(orCOut[7]);

	or_gate[8].aIn(orCOut[4]);
	or_gate[8].bIn(orCOut[5]);
	or_gate[8].cOut(orCOut[8]);

	or_gate[9].aIn(orCOut[6]);
	or_gate[9].bIn(orCOut[7]);
	or_gate[9].cOut(orCOut[9]);

	or_gate[10].aIn(orCOut[8]);
	or_gate[10].bIn(orCOut[9]);
	or_gate[10].cOut(orCOut[10]);

	//ALUSrc

	or_gate2[0].aIn(eOutSg[5]);
	or_gate2[0].bIn(eOutSg[6]);
	or_gate2[0].cOut(or2COut[0]);

	or_gate2[1].aIn(eOutSg[7]);
	or_gate2[1].bIn(eOutSg[8]);
	or_gate2[1].cOut(or2COut[1]);

	or_gate2[2].aIn(eOutSg[11]);
	or_gate2[2].bIn(eOutSg[12]);
	or_gate2[2].cOut(or2COut[2]);

	or_gate2[3].aIn(or2COut[0]);
	or_gate2[3].bIn(or2COut[1]);
	or_gate2[3].cOut(or2COut[3]);

	or_gate2[4].aIn(or2COut[2]);
	or_gate2[4].bIn(eOutSg[2]);
	or_gate2[4].cOut(or2COut[4]);

	or_gate2[5].aIn(or2COut[3]);
	or_gate2[5].bIn(or2COut[4]);
	or_gate2[5].cOut(or2COut[5]);

//2,5,6,7,8,11,12

	//Branch

	or_gate3[0].aIn(eOutSg[13]);
	or_gate3[0].bIn(eOutSg[14]);
	or_gate3[0].cOut(or3COut);

	SC_METHOD(operation);
	sensitive << clk.neg() << clk.pos()/* << dir_In*/;

}

// 1 add
// 2 sub
// 3 addi
// 4 sll
// 5 srl
// 6 slli
// 7 srli
// 8 lw
// 9 sw
// 10 and
// 11 or
// 12 andi
// 13 ori
// 14 beq
// 15 bne

void Unidad_Control::operation()
{

	aux[0].write(dir_In_0);
	aux[1].write(not_to_and[0]);
	aux[2].write(not_to_and[1]);
	aux[3].write(not_to_and[2]);	

	aux[4].write(not_to_and[3]);
	aux[5].write(dir_In_1);
	aux[6].write(not_to_and[4]);
	aux[7].write(not_to_and[5]);

	aux[8].write(dir_In_0);
	aux[9].write(dir_In_1);
	aux[10].write(not_to_and[6]);
	aux[11].write(not_to_and[7]);		

	aux[12].write(not_to_and[8]);
	aux[13].write(not_to_and[9]);
	aux[14].write(dir_In_2);
	aux[15].write(not_to_and[10]);

	aux[16].write(dir_In_0);
	aux[17].write(not_to_and[11]);
	aux[18].write(dir_In_2);
	aux[19].write(not_to_and[12]);

	aux[20].write(not_to_and[13]);
	aux[21].write(dir_In_1);
	aux[22].write(dir_In_2);
	aux[23].write(not_to_and[14]);

	aux[24].write(dir_In_0);
	aux[25].write(dir_In_1);
	aux[26].write(dir_In_2);
	aux[27].write(not_to_and[15]);

	aux[28].write(not_to_and[16]);
	aux[29].write(not_to_and[17]);
	aux[30].write(not_to_and[18]);
	aux[31].write(dir_In_3);


	aux[40].write(dir_In_0);
	aux[41].write(dir_In_1);
	aux[42].write(not_to_and[23]);
	aux[43].write(dir_In_3);

	aux[36].write(not_to_and[21]);
	aux[37].write(dir_In_1);
	aux[38].write(not_to_and[22]);
	aux[39].write(dir_In_3);

	aux[32].write(dir_In_0);
	aux[33].write(not_to_and[19]);
	aux[34].write(not_to_and[20]);
	aux[35].write(dir_In_3);		

	aux[44].write(not_to_and[24]);
	aux[45].write(not_to_and[25]);
	aux[46].write(dir_In_2);
	aux[47].write(dir_In_3);


	aux[48].write(dir_In_0);
	aux[49].write(not_to_and[26]);
	aux[50].write(dir_In_2);
	aux[51].write(dir_In_3);	


	aux[52].write(not_to_and[27]);
	aux[53].write(dir_In_1);
	aux[54].write(dir_In_2);
	aux[55].write(dir_In_3);	


	aux[56].write(dir_In_0);
	aux[57].write(dir_In_1);
	aux[58].write(dir_In_2);
	aux[59].write(dir_In_3);

	Ex_ALUOpOut.write(0);
	Wb_RegWriteOut.write(or_gate[10].cOut.read());
	Mem_MemReadOut.write(and_gate[7].eOut.read());
	Mem_MemWriteOut.write(and_gate[8].eOut.read());
	Mem_BranchOut.write(or_gate3[0].cOut.read());
	Ex_ALUSrcOut.write(or_gate2[5].cOut.read());
	Wb_MemtoRegOut.write(not_gate2[0].Salida1.read());

}

Unidad_Control::~Unidad_Control() {
  // Es importante recordar liberar la memoria que asignamos
  delete Divider;

}