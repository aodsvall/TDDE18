#ifndef CAPACITOR_H
#define CAPACITOR_H
#include <iostream>
#include <string>
#include "component.h"
// TODO: Complementary work needed: charge_difference should be a
// local variable rather than a data member. It is unnecessary to
// store it in the object since it is only ever used in calcCurrent
// and you are not using the previous value (this is true in the
// resistor class as well).
// DONE
class Capacitor : public Component
{
public:
    Capacitor(std::string const &name, double ohm, Terminal &input, Terminal &output);
    ~Capacitor();
    void calc_current(double const &time) override;
    double get_current() const;

private:
    double current{};
    double stored_volt{};
};

#endif