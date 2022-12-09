#ifndef BATTERY_H
#define BATTERY_H
#include <iostream>
#include <string>
#include "component.h"

// TODO: Complementary work needed: No need to declare the destructor
// if it doesn't do anything.
//DONE
class Battery : public Component
{
public:
    Battery(std::string const &name, double const volt, Terminal &input, Terminal &output);
    double get_current() const;
    void calc_current(double const &time) override;

private:
    double voltage{};  
};

#endif