#include "battery.h"

using namespace std;

Battery::Battery(string const &name, double const volt, Terminal &input, Terminal &output)
        : Component{name, input, output}, voltage{volt}
    {

    }



double Battery::get_current() const{
    return 0;
}


void Battery::calc_current(double const &time) {
    out.charge = voltage;
    in.charge = 0;
}


