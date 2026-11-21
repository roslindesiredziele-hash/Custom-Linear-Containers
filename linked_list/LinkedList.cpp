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

 LinkedList::LinkedList(const LinkedList& other):
      head(nullptr),
      tail(nullptr),
      len(0)
{
    Box* ptr = other.head;

    while(ptr)
    {
        append(ptr->value);
        ptr = ptr->nextbox;
    }
}

LinkedList& LinkedList::operator=(const LinkedList& other)
{
    if(this == &other)
    {
        return *this;
    }

    clear();

    Box* ptr = other.head;

    while(ptr)
    {
        append(ptr->value);
        ptr = ptr->nextbox;
    }

    return *this;
}

LinkedList::LinkedList(LinkedList&& other) noexcept:
      head(other.head),
      tail(other.tail),
      len(other.len)
{
    other.head = nullptr;
    other.tail = nullptr;
    other.len = 0;
}

LinkedList& LinkedList::operator=(LinkedList&& other) noexcept
{
    if(this == &other)
    {
        return *this;
    }

    clear();

    head = other.head;
    tail = other.tail;
    len = other.len;

    other.head = nullptr;
    other.tail = nullptr;
    other.len = 0;

    return *this;
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

int LinkedList::getlength() const
{
    return len;
}

bool LinkedList::empty() const
{
    return len == 0;
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

void LinkedList::resize(int newSize)
{
    if(newSize < 0)
    {
        throw std::invalid_argument("Negative size");
    }

    if(newSize == len)
    {
        return;
    }

    // Grow
    while(len < newSize)
    {
        append(0);
    }

    // Shrink
    while(len > newSize)
    {
        erase(len - 1);
    }
}

void LinkedList::erase(int index)
{
    if(index < 0 || index >= len)
    {
        throw std::out_of_range("Index out of range");
    }

    if(index == 0)
    {
        Box* doomed = head;
        head = head->nextbox;
        delete doomed;
        len--;

        if(len == 0)
        {
            tail = nullptr;
        }

        return;
    }

    Box* prev = head;

    for(int i = 0; i < index - 1; i++)
    {
        prev = prev->nextbox;
    }

    Box* doomed = prev -> nextbox;

    prev -> nextbox = doomed -> nextbox;

    if(doomed == tail)
    {
        tail = prev;
    }

    delete doomed;

    len--;
}

void LinkedList::erase(int first, int last)
{
    if(first > last)
    {
        int temp = first;
        first = last;
        last = temp;
    }

    if(first < 0 || last < 0 || last >= len)
    {
        throw std::out_of_range("Invalid range");
    }

    int count = last - first + 1;
    
    for(int i = 0; i < count; i++)
    {
        erase(first);
    }
}