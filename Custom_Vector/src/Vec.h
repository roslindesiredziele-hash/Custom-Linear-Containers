#ifndef VEC_H
#define VEC_H

#include <ostream>

class Vec
{
private:
    int cap;
    int len;
    int* mem;

    void swapInt(int &a, int &b);

public:
    Vec(int n);
    ~Vec();

    Vec& operator=(Vec&& other) noexcept;
    Vec(Vec&& other) noexcept;

    Vec(const Vec& other);
    Vec& operator=(Vec cpy);
    

    int& operator[](int);
    const int& operator[](int) const;

    int size() const;
    int capacity() const;

    int& get(int);
    const int& get(int) const;

    void pop();
    bool empty() const;

    void resize(int);
    
    void erase(int);
    void erase(int, int);

    void push(int);

    int& first();
    const int& first() const;

    int& last();
    const int& last() const;

    void clear();

    bool linearSearch(int) const;
    int binarySearch(int) const;

    long long sum() const;
    double avg() const;

    void reverse();
    void reverse(int, int);
    void rotate(int);

    int* begin ();
    const int* begin() const;

    int* end();
    const int* end() const;
};

std::ostream& operator<<(std::ostream& ostr, const Vec& v);

#endif
