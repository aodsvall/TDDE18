#include "component.h"
#include "math.h"
using namespace std;

Component::Component(string const &name, Terminal &input, Terminal &output)
    : name{name}, in{input}, out{output}
{
}
double Component::get_charge() const
{
    return (abs(out.charge-in.charge));
}

string Component::get_name() const {
    return name;
}




