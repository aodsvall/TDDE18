#ifndef TEXT_HANDLER_H
#define TEXT_HANDLER_H
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <istream>
#include <fstream>
#include <iterator>
#include <map>
#include <ostream>


class text_handler
{
    public:
    text_handler();
    void substitute(std::vector<std::string> &text, std::string &r_value, std::string &n_value);
    void print(std::vector<std::string> &text);
    void erase(std::vector<std::string> &text, std::string &val);

    private:
    std::string name{};
};

#endif