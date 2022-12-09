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

void create_text_file(vector<string> &text, vector<string> file_args)
{
    string inFile = file_args[0];
    ifstream textFile{inFile};
    if (textFile.fail())
    {
        cout << "CERR: This is not a correct text file" << endl;
        exit(EXIT_FAILURE);
    }
    copy(istream_iterator<string>(textFile), istream_iterator<string>(), back_insert_iterator<vector<string>>(text));
}

void process_args(vector<string> &text, text_handler &handler, string &arg)
{

    string delimiter_1 = "=";
    string delimiter_2 = "+";
    string raw_input = arg;
    string flag{};
    string value_1{};
    string value_2{};

    flag = raw_input.substr(0, raw_input.find(delimiter_1));

    if (flag == "--print")
    {
        handler.print(text);
    }
    else if (flag == "--remove")
    {
        if (raw_input.find(delimiter_1) == 8)
        {
            raw_input.erase(0, raw_input.find(delimiter_1) + delimiter_1.length());
            value_1 = raw_input.substr(0, raw_input.length());
        }
        if (!value_1.empty())
        {
            handler.erase(text, value_1);
        }
        else
        {
            cerr << "ERROR: This is not a correct fromat for this flag" << endl;
            cout << "Correct format: --remove=<word>" << endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (flag == "--substitute")
    {
        if (raw_input.find(delimiter_1) == 12)
        {
            raw_input.erase(0, raw_input.find(delimiter_1) + delimiter_1.length());
            value_1 = raw_input.substr(0, raw_input.find(delimiter_2));
            raw_input.erase(0, raw_input.find(delimiter_2) + delimiter_2.length());
            value_2 = raw_input.substr(0, raw_input.length());
        }
        if (!value_1.empty() && !value_2.empty())
        {
            handler.substitute(text, value_1, value_2);
        }
        else
        {
            cerr << "ERROR: This is not a correct fromat for this flag" << endl;
            cout << "Correct format: --subsitute=<word>+<word>" << endl;
            exit(EXIT_FAILURE);
        }
    }
    else if (flag == "--frequency")
    {
        handler.frequency(text);
    }
    else if (flag == "--table")
    {
        handler.table(text);
    }
    else
    {
        cerr << "ERROR: This is not a correct flag" << endl;
        cout << "Available flags: --print, --remove=<word>, --frequency, --table, --subsitute=<word>+<word>" << endl;
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char **argv)
{

    vector<string> text{};
    vector<string> file_args(argv + 1, argv + argc);
    create_text_file(text, file_args);

    text_handler handler{};

    vector<string> args(argv + 2, argv + argc);

    for_each(args.begin(), args.end(), [&text, &handler](string arg)
             { process_args(text, handler, arg); });
}
