
#include "list.h"

using namespace std;

List::List()
    : head{nullptr}, tail{nullptr}
{
}
List::List(const List &orgObj)
{
    if (orgObj.head == nullptr)
    {
        head = nullptr;
    }
    else
    {
        Node *tmp{};
        tmp = orgObj.head;
        if(orgObj.size() > 1) {
        while (tmp->next != nullptr)
        {
            Node *copy = new Node{tmp->value, nullptr};
            if (is_empty())
            {
                head = copy;
                tail = copy;
                head->next = tail;
            }

            tail->next = copy;
            tail = copy;

            tmp = tmp->next;
        }
        Node *copy = new Node{tmp->value, nullptr};
        tail->next = copy;
        tail = copy;
    } else {
        Node *copy = new Node{tmp->value, nullptr};
        head = copy;
        tail = copy;
    }}

}

List::List(List &&orgObj)
{
    if (orgObj.head == nullptr)
    {
        head = nullptr;
    }
    else if (orgObj.size() > 0)
    {
        head = orgObj.head;
        orgObj.head = nullptr;
        
    }
}

List &List::operator=(const List &orgObj)
{
    List tmp{orgObj};
    Node *dummy{nullptr};
    dummy = head;
    head = tmp.head;
    tmp.head = dummy;
    return *this;
}

List &List::operator=(List &&orgObj)
{
    empty_list();
    head = orgObj.head;
    orgObj.head = nullptr;
    return *this;
}

List::~List()
{
    empty_list();
}

void List::insert(int const &value)
{
    Node *tmp = new Node{value, nullptr};

    if (is_empty())
    {
        head = tmp;
        tail = head;
        return;
    }
    else if (head->value > tmp->value)
    {
        tmp->next = head;
        tail = head;
        head = tmp;
    }
    else
        sorted_insert(tmp);
    return;
}

void List::sorted_insert(Node *tmp_sort)
{
    Node *iterator{head};

    while (iterator->next != nullptr)
    {
        if (tmp_sort->value > iterator->value)
        {
            if (tmp_sort->value < iterator->next->value)
            {
                Node *dummy{nullptr};
                dummy = iterator->next;
                iterator->next = tmp_sort;
                tmp_sort->next = dummy;
                return;
            }
            iterator = iterator->next;
        }
    }
    tail->next = tmp_sort;
    tail = tmp_sort;
    return;
}

void List::remove(int const &value)
{
    if(!is_empty()) {
    Node *tmp{nullptr}, *dummy{nullptr};
    tmp = head;
    while (tmp->next != nullptr)
    {
        if (tmp->next->value == value)
        {
            dummy = tmp->next;
            tmp->next = dummy->next;
            delete dummy;
            return;
        }
        tmp = tmp->next;
    }}
}

void List::empty_list()
{
    while (!is_empty())
    { 
        Node *tmp = head->next;
        delete head;
        head = tmp;
    }
}

int List::get_index_at(int const &index) const
{
    Node *tmp;
    tmp = head;

    if(index > size() || index < 0 || is_empty()) {
        return 0;
    }
    
    for (int i = 0; i <= index - 1; i++)
    {
        tmp = tmp->next;
    }

    return tmp->value;
}

void List::print() const
{
    Node *tmp;
    tmp = head;

    print_list(tmp);
}
//We asked an assistant about this and they said that this was the correct way.
//There was no need to take an ostream argument or return a string
void List::print_list(Node const *tmp) const
{
    if (tmp != nullptr)
    {
        cout << " -> " << tmp->value;
        print_list(tmp->next);
    }
}

bool List::is_empty() const
{
    return head == nullptr;
}

int List::size() const
{

    int length{0};
        Node *tmp;
    tmp = head;

    while (tmp)
    {
        tmp = tmp->next;
        length++;
    }

    return length;
}
