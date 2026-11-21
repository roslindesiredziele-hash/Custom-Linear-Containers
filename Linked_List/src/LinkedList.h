#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <ostream>

class LinkedList
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
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList& other);
    LinkedList& operator = (const LinkedList& other);
    LinkedList(LinkedList&& other) noexcept;
    LinkedList& operator = (LinkedList&& other) noexcept;

    friend std::ostream &operator<<(std::ostream &ostr, const class LinkedList &L);

    int& operator[](int);
    const int& operator[](int) const;

    int getlength() const;
    bool empty() const;

    int& front();
    const int& front() const;

    int& back();
    const int& back() const;

    void append(int);
    void prepend(int);

    void clear();
    void resize(int);
    void erase(int);
    void erase(int, int);

};

#endif