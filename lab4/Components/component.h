#ifndef Component_h
#define Component_h
#include <iostream>
#include <string>
#include <iomanip>
#include "terminal.h"

// TODO: Complementary work needed: Your destructor should be virtual
// in base class, which affects the subclasses.
//DONE

// TODO: Complementary work needed: calcCurrent does not follow the
// same naming convention as the other functions.
//DONE

// TODO: Complementary work needed: Complex datatypes should avoid
// being copied into functions (this is true for *all* files).
//DONE

// TODO: Complementary work needed: The data member current is
// overshadowed in all subclasses, so it is not needed in the base
// class: remove it!
//DONE

// TODO: Complementary work needed: Your destructor is empty, should
// therefore be set default in baseclass.
//DONE

class Component
{

protected:
    std::string name{};
    Terminal &in;
    Terminal &out;

public:
    Component(std::string const &name, Terminal &in, Terminal &out); 
    virtual ~Component() = default;
    double get_charge() const;
    virtual double get_current() const = 0;
    virtual void calc_current(double const &time) = 0;
    std::string get_name() const;
};

#endif