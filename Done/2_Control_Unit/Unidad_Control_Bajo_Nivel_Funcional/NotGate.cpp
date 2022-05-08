#include "NotGate.h"
NotGate::NotGate(sc_module_name moduleName) : sc_module(moduleName) {
	SC_METHOD(process);
	sensitive << Entrada1;

}
NotGate::~NotGate(){}
void NotGate::process(){
	Salida1.write(!Entrada1.read());
}