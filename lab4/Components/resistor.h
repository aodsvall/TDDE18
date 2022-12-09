#ifndef RESISTOR_H
#define RESISTOR_H
#include <iostream>
#include <string>
#include "component.h"

// TODO: Complementary work needed: See capacitator.h for details.
//DONE

class Resistor : public Component
{
public:
    Resistor(std::string const &name, double ohm, Terminal &input, Terminal &output);
    ~Resistor();
    void calc_current(double const &time) override;
    double get_current() const;

private:
    double current{};
};

#endif