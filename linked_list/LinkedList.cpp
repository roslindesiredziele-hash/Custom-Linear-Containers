#include "LinkedList.h"

LinkedList::LinkedList():
 head(nullptr), tail(nullptr), len(0)
 {

 }

 LinkedList::~LinkedList()
 {
    clear();
 }

int LinkedList::getlength()
{
    return len;
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
}

std::ostream& operator<< (std::ostream &ostr, class LinkedList &L)
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
}

int& LinkedList::operator[](int index)
{
    Box* ptr = head;
    for(int i = 0; i < index; i++)
    {
        ptr = ptr -> nextbox;
    }
    
    return ptr->value;
}

void LinkedList::append(int v)
{
    (!len)? head = tail = new Box(v,nullptr) : tail = tail -> nextbox = new Box(v,nullptr);
    len++;
}

void LinkedList::prepend(int v)
{
    head = new Box(v, head);
    (len == 0)? tail = head: head;
}
/*if(!len)
    {
        head = tail = new Box(v,nullptr);
    }
    else
    {
        tail = tail -> nextbox = new Box(v,nullptr);
    }*/