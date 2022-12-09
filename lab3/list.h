#ifndef LIST_H
#define LIST_H
#include <iostream>
#include <sstream>
#include <iomanip>

/*
Class
@param
*/

class List
{

private:
    struct Node
    {
        int value{};
        Node *next{};
    };

    Node *head{};
    Node *tail{};
    void sorted_insert(Node *tmp_sort);
    void print_list(Node const *tmp) const;
public:
    List();
    List(const List &orgObj);
    List(List &&orgObj);
    ~List();
    
    List &operator=(const List &orgObj);
    List &operator=(List &&orgObj);
    void insert(int const &value);
    
    void remove(int const &value);
    void empty_list();
    int get_index_at(int const &index) const;
    void print() const;
    
    bool is_empty() const;
    int size() const;
};

#endif
