#ifndef SIMULATOR_H
#define SIMULATOR_H
#include <iostream>
#include <string>
#include <vector>
#include "Components/component.h"

    // COMMENT: It is unclear why time is const but nothing else is...
class Simulator
{


public:
    Simulator(std::vector<Component*> const &vec, int const iterations, int const lines, double const time);
    void simulate();
    ~Simulator();
    void print_values(std::vector<Component*> vec);
    void print_info(std::vector<Component*> vec);

private:
    std::vector<Component*> components{};
    int lines{};
    int iterations{};
    double time{};

};

#endif

