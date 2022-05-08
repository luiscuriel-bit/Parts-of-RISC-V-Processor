#ifndef AND_GATE_H
#define AND_GATE_H

#include <systemc.h>

class AndGate : public sc_module {
  public:
    sc_in<bool> aIn, cIn;  
    sc_in<bool> bIn, dIn;   
    sc_out<bool> eOut; 

    SC_CTOR(AndGate);
    ~AndGate(); 
  private:
    void operation();
};

#endif
