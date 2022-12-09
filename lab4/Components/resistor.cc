#include "resistor.h"

using namespace std;

Resistor::Resistor(string const &name, double ohm, Terminal &input, Terminal &output)
        : Component{name, input, output}, current{ohm}
    {

    }

Resistor::~Resistor() {
    
}

double Resistor::get_current() const{

    return (abs(in.charge-out.charge)/current);
}




void Resistor::calc_current(double const &time) {

    double charge_difference = {get_current() * time};
    if(in.charge > out.charge) {
        in.charge -= charge_difference;
        out.charge += charge_difference;
        
    }
    else {
        in.charge += charge_difference;
        out.charge -= charge_difference;

    } 
    
   
} 

