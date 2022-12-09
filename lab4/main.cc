#include "Components/battery.h"
#include "Components/resistor.h"
#include "Components/capacitor.h"
#include "Components/terminal.h"
#include "simulator.h"
#include "vector"
#include <iostream>

// TODO: Complementary work needed: The deallocation of components
// should be handled in the Simulator destructor.
// DONE

// TODO: Complementary work needed: try/catch should only surround the
// functions which can throw the exceptions (stod, stoi). If the inputted
// parameters are correct, the program should run without failure.
// Hint: Make sure to stop the program in a correct way such as return N, where N != 0.
//DONE

using namespace std;
void deallocate_components(vector<Component *> vec);
void circuit_builder1(int const iterations, int const lines, double const time, double const voltage)
{
    vector<Component *> vec{};

    Terminal p{};
    Terminal n{};
    Terminal r124{};
    Terminal r23{};

    vec.push_back(new Battery{"Bat", voltage, n, p});
    vec.push_back(new Resistor{"R1", 6, p, r124});
    vec.push_back(new Resistor{"R2", 4, r124, r23});
    vec.push_back(new Resistor{"R3", 8, r23, n});
    vec.push_back(new Resistor{"R4", 12, r124, n});
    Simulator s{vec, iterations, lines, time};
    s.simulate();
}
void circuit_builder2(int const iterations, int const lines, double const time, double const voltage)
{
    vector<Component *> vec{};

    Terminal p{};
    Terminal n{};
    Terminal L{};
    Terminal R{};

    vec.push_back(new Battery{"Bat", voltage, n, p});
    vec.push_back(new Resistor{"R1", 150, p, L});
    vec.push_back(new Resistor{"R2", 50, p, R});
    vec.push_back(new Resistor{"R3", 100, L, R});
    vec.push_back(new Resistor{"R4", 300, L, n});
    vec.push_back(new Resistor{"R5", 250, R, n});
    Simulator s{vec, iterations, lines, time};
    s.simulate();
}
void circuit_builder3(int const iterations, int const lines, double const time, double const voltage)
{
    vector<Component *> vec{};

    Terminal p{};
    Terminal n{};
    Terminal L{};
    Terminal R{};

    Battery b{"Bat", voltage, n, p};
    Resistor r1{"R1", 150, p, L};
    Resistor r2{"R2", 50, p, R};
    Capacitor c3{"C3", 1, L, R};
    Resistor r4{"R4", 300, L, n};
    Capacitor c5{"C5", 0.75, R, n};

    vec.push_back(new Battery{"Bat", voltage, n, p});
    vec.push_back(new Resistor{"R1", 150, p, L});
    vec.push_back(new Resistor{"R2", 50, p, R});
    vec.push_back(new Capacitor{"C3", 1, L, R});
    vec.push_back(new Resistor{"R4", 300, L, n});
    vec.push_back(new Capacitor{"C5", 0.75, R, n});
    Simulator s{vec, iterations, lines, time};
    s.simulate();
}

int main(int argc, char **argv)
{
    int iterations{};
    int lines{};
    double time{};
    double voltage{};
    try
    {
        iterations = stoi(argv[1]);
        lines = stoi(argv[2]);
        time = stod(argv[3]);
        voltage = stod(argv[4]);
    }
    catch (invalid_argument &a)
    {
        cout << "ERROR: " << a.what() << endl;
        return -1;
    }
    circuit_builder1(iterations, lines, time, voltage);
    circuit_builder2(iterations, lines, time, voltage);
    circuit_builder3(iterations, lines, time, voltage);
    return 0;
}