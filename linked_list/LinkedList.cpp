#include "LinkedList.h"

#include <stdexcept>

LinkedList::LinkedList():
 head(nullptr), tail(nullptr), len(0)
 {

 }

 LinkedList::~LinkedList()
 {
    clear();
 }

int LinkedList::getlength() const
{
    return len;
}

bool LinkedList::empty() const
{
    return len == 0;
}

void LinkedList::clear()
{
    Box* ptr = head;

    while(ptr)
    {
        Box* b = ptr -> nextbox;

        delete ptr;
        ptr = b;
    }

    head = nullptr;
    tail = nullptr;
    len = 0;
}

std::ostream& operator<< (std::ostream &ostr, const class LinkedList &L)
{
    struct LinkedList::Box * ptr = L.head;
    ostr << " [ ";
    
    for(int i = 0; i < L.len; i++)
    {
        ostr << ptr -> value;
        if(i != L.len - 1)
            ostr << "; ";
        ptr = ptr->nextbox;
    }

    ostr << "]";

    return ostr;
}

int& LinkedList::operator[](int index)
{
    if(index < 0 || index >= len)
    {
        throw std::out_of_range("Index out of range");
    }

    Box* ptr = head;

    for(int i = 0; i < index; i++)
    {
        ptr = ptr -> nextbox;
    }
    
    return ptr->value;
}

const int& LinkedList::operator[](int index) const
{
    if(index < 0 || index >= len)
    {
        throw std::out_of_range("Index out of range");
    }

    Box* ptr = head;

    for(int i = 0; i < index; i++)
    {
        ptr = ptr -> nextbox;
    }
    
    return ptr->value;
}

void LinkedList::append(int v)
{
    if(!len)
    {
        head = tail = new Box(v,nullptr);
    }
    else
    {
        tail = tail -> nextbox = new Box(v,nullptr);
    }

    len++;
}

void LinkedList::prepend(int v)
{
    head = new Box(v, head);

    if(len == 0)
    {
        tail = head;
    }

    len++;
}