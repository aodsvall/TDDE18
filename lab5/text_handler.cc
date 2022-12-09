#include "text_handler.h"

using namespace std;

text_handler::text_handler() : name{}
{
}



void text_handler::substitute(vector<string> &text, string &r_value, string &n_value)
{
    // Replace can't tell difference between "the" and "there", replace_if can
    auto res = find(text.begin(), text.end(), r_value);
    if (res != text.end())
    {
        replace_if(
            text.begin(), text.end(), [r_value](auto &tmp)
            { return tmp == r_value; },
            n_value);
    }
    else
    {
        cerr << "ERROR: Word does not exist in text file";
        cout << endl;
    }
}

void text_handler::print(vector<string> &text)
{
    // Copys the vector into ostream_iterator because ostream_iterator is able to print the vector
    copy(text.begin(), text.end(), ostream_iterator<string>(cout, " "));
    cout << endl;
}

void text_handler::erase(vector<string> &text, string &val)
{
    // Combo of erase & remove -> remove only places removed value at the back of vector, erase deletes it
    auto res = find(text.begin(), text.end(), val);
    if (res != text.end())
    {
    text.erase(remove(text.begin(), text.end(), val), text.end());
    }
    else
    {
        cerr << "ERROR: Word does not exist in text file";
        cout << endl;
    }
}

bool swap_pair(const pair<string, int> &a_pair, const pair<string, int> &b_pair)
{
    return (a_pair.second < b_pair.second);
}

void text_handler::frequency(vector<string> &text)
{

    vector<pair<string, int>> frequency{};
    /* Iterates over the text file and loads them in to a vector of pairs,
        if the word has occured its value is incremented to be able to display the result */
    for_each(text.begin(), text.end(), [&frequency](string str)
             {
        if (frequency.empty()) {frequency.push_back(make_pair(str, 1));}
        else{ auto it = find_if( frequency.begin(), frequency.end(),[&str] 
            (const pair<std::string, int>& pair){ return pair.first == str;} );
                if( it != frequency.end()) { frequency[distance(frequency.begin(), it)].second++; } 
                    else { frequency.push_back(make_pair(str, 1)); }} });

    auto print = [](std::pair<string, int> &itp)
    { cout << setw(11) << itp.first << " " << itp.second << endl; };

    sort(frequency.begin(), frequency.end(), swap_pair);
    reverse(frequency.begin(), frequency.end());
    for_each(frequency.begin(), frequency.end(), print);
}

void text_handler::table(vector<string> &text)
{
    /*Defaults in ascending order, therefor good alternative for table */
    map<string, int> wordmap{};
    /*Iterator to print our map*/
    auto print = [](std::pair<const string, int> &itp)
    { cout << itp.first << setw(13 - itp.first.length()) << itp.second << endl; };

    for_each(text.begin(), text.end(), [&wordmap](string str)
             { return wordmap[str]++; });

    for_each(wordmap.begin(), wordmap.end(), print);
}