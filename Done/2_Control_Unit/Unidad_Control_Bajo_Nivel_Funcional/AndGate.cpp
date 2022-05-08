#include "AndGate.h"

AndGate::AndGate(sc_module_name moduleName) : sc_module(moduleName) {
  SC_METHOD(operation); 
  sensitive << aIn << bIn << cIn << dIn;
}

AndGate::~AndGate() {}

void AndGate::operation() {

  eOut.write(aIn.read() and bIn.read() and cIn.read() and dIn.read());

}