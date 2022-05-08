#ifndef DIVIDER_H
#define DIVIDER_H

#include <systemc.h>

class divider : public sc_module{
public:
	sc_in<sc_uint<4>> dir_In;
	sc_out<bool> dir_In_3{"atun12"};

	sc_out<bool> dir_In_0{"atun"};
	sc_out<bool> dir_In_1{"atun1"};
	sc_out<bool> dir_In_2{"atun2"};

	SC_CTOR(divider);
	~divider();
private:
	void process();

};
#endif