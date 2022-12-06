#include "text_handler.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <fstream>
#include <iterator>
#include <map>
#include <ostream>

using namespace std;

int main(int argc, char **argv)
{

    string inFile = argv[1];
    ifstream textFile{inFile};
    vector<string> text{};
    copy(istream_iterator<string>(textFile), istream_iterator<string>(), back_insert_iterator<vector<string>>(text));
    map<string, int> frequency{};

    text_handler handler{};
    string val{"the"};
    string sub1{"the"};
    string sub2{"NEW"};
    vector<string> args(argv + 2, argv + argc);
    if (args[0] == "--print")
    {
        handler.print(text);
    }
    else if (args[0] == "--remove")
    {
        handler.erase(text, val);
        handler.print(text);
    }
    else if (args[0] == "--substitute")
    {
        handler.substitute(text, sub1, sub2);
        handler.print(text);
    }
}