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

void LinkedList::append(int v)
{
    if(!len)
    {
        head = tail = new Box(v, NULL);
    }
    else
    {
        tail = tail -> nextbox = new Box(v, NULL);
    }
}