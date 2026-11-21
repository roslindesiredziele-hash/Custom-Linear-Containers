#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>

class Linkedlist
{
    private:
    struct Box
    {
        int value;
        Box* nextbox;

        Box(int v, Box* b):
        value(v), nextbox(b)
        {}
    };

    struct Box* head;
    struct Box* tail;
    int len;

    public:
    Linkedlist();
};

#endif