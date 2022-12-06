#include "text_handler.h"

using namespace std;

text_handler::text_handler() : name{}
{
}

void text_handler::substitute(vector<string> &text, string &r_value, string &n_value)
{
    replace_if(
        text.begin(), text.end(), [r_value](auto &tmp)
        { return tmp == r_value; },
        n_value);
}

void text_handler::print(vector<string> &text)
{
    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void text_handler::erase(vector<string> &text, string &val)
{
    text.erase(remove(text.begin(), text.end(), val), text.end());
}