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
    (!len)? head = tail = new Box(v, NULL) : tail = tail -> nextbox = new Box(v, NULL);
}

void LinkedList::prepend(int v)
{
    head = new Box(v, head);
    (len == 0)? tail = head: head;
}
/*if(!len)
    {
        head = tail = new Box(v, NULL);
    }
    else
    {
        tail = tail -> nextbox = new Box(v, NULL);
    }*/