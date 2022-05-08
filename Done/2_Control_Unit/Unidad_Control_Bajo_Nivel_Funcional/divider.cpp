#include "divider.h"

using namespace std;

divider::divider(sc_module_name moduleName) : sc_module(moduleName) {
	SC_METHOD(process);
	sensitive << dir_In;

}
divider::~divider(){

}

void divider::process(){
	dir_In_0.write(dir_In.read()[0]);
	dir_In_1.write(dir_In.read()[1]);
	dir_In_2.write(dir_In.read()[2]);
	dir_In_3.write(dir_In.read()[3]);
}