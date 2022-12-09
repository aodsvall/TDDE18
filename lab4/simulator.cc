#include "simulator.h"
#include <iomanip>

using namespace std;

Simulator::Simulator(std::vector<Component *> const &vec, int iterations, int lines, double const time)
    : components{vec}, iterations{iterations}, lines{lines}, time{time}
{
}

Simulator::~Simulator()
{
  for (Component *i : components)
  {
    delete i;
  }
}

void Simulator::simulate()
{
  cout << fixed << setprecision(2);
  print_info(components);

  for (int j{1}; j <= iterations; j++)
  {
    for (Component *i : components)
    {
      i->calc_current(time);
    }
    if (j % (iterations / lines) == 0)
    {
      print_values(components);
    }
  }
  cout << endl;
}

void Simulator::print_info(vector<Component *> vec)
{

  for (Component *i : components)
  {
    cout << setw(12);
    cout << i->get_name();
  }
  cout << endl;
  for (int i{0}; i < components.size(); i++)
  {
    cout << setw(6);
    cout << "Volt";
    cout << setw(6);
    cout << "Curr";
  }
  cout << endl;
}

void Simulator::print_values(vector<Component *> vec)
{
  for (Component *i : components)
  {
    cout << setw(6);
    cout << i->get_charge();
    cout << setw(6);
    cout << i->get_current();
  }
  cout << endl;
}
