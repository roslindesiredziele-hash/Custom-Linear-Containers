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
    ~Linkedlist();

    friend std::ostream &operator<<(std::ostream &ostr, class Linkedlist &L);
    int& operator[](int);
    const int& operator[](int) const;

    int getlength();

    void append(int);
    void prepend(int);

    void clear();
    void resize(int);

};

#endif