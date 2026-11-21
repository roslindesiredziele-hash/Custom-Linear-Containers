#include "Vec.h"
#include <algorithm>
#include <stdexcept>

Vec::Vec(int n)
{
    if (n < 0)
        throw std::invalid_argument("cannot initialize with negative capacity");

    cap = std::max(1, n);
    len = 0;
    mem = new int[cap];
}

Vec::~Vec()
{
    delete[] mem;
}

Vec::Vec(const Vec &other) : cap(other.cap),
                             len(other.len),
                             mem(new int[cap])
{
    for (int i = 0; i < len; i++)
    {
        mem[i] = other.mem[i];
    }
}

Vec& Vec::operator=(const Vec& other)
{
    if (this == &other)
    {
        return *this;
    }

    int* new_mem = new int[other.cap];

    for (int i = 0; i < other.len; i++)
    {
        new_mem[i] = other.mem[i];
    }

    delete[] mem;

    mem = new_mem;
    cap = other.cap;
    len = other.len;

    return *this;
}

Vec& Vec::operator=(Vec&& other) noexcept
{
    if (this == &other)
    {
        return *this;
    }

    delete[] mem;

    cap = other.cap;
    len = other.len;
    mem = other.mem;

    other.cap = 0;
    other.len = 0;
    other.mem = nullptr;

    return *this;
}

Vec::Vec(Vec&& other) noexcept
    : cap(other.cap),
      len(other.len),
      mem(other.mem)
{
    other.cap = 0;
    other.len = 0;
    other.mem = nullptr;
}

int &Vec::operator[](int i)
{
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return mem[i];
}

const int &Vec::operator[](int i) const
{
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return mem[i];
}

std::ostream &operator<<(std::ostream &ostr, const Vec &v)
{
    ostr << "[";

    for (int i = 0; i < v.size(); i++)
    {
        ostr << v[i];

        if (i != v.size() - 1)
            ostr << "; ";
    }

    ostr << "]";

    return ostr;
}

void Vec::swapInt(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int Vec::size() const
{
    return len;
}

int Vec::capacity() const
{
    return cap;
}

int &Vec::get(int i)
{
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return mem[i];
}

const int &Vec::get(int i) const
{
    if (i < 0 || i >= len)
        throw std::out_of_range("index out of range");
    return mem[i];
}

void Vec::pop()
{
    if (!empty())
        len--;
}

bool Vec::empty() const
{
    return len == 0;
}

void Vec::resize(int new_cap)
{
    int new_capacity = std::max(1, new_cap);
    int* new_mem = new int[new_capacity];
    int new_len = std::min(len, new_capacity);

    for (int i = 0; i < new_len; i++)
    {
        new_mem[i] = mem[i];
    }

    delete[] mem;

    mem = new_mem;
    cap = new_capacity;
    len = new_len;
}

void Vec::erase(int index)
{
    if(index < 0 || index >= len)
    {
        throw std::out_of_range("Index out of range");
    }

    for(int i = index; i < len - 1; i++)
    {
        mem[i] = mem[i + 1];
    }

    len--;
}

void Vec::erase(int first, int last)
{
    if (first > last)
        swapInt(first, last);

    if (first < 0 || last >= len)
    {
        throw std::out_of_range("the range selected is out of bounds");
    }

    int removed = last - first + 1;

    for (int i = first ; i + removed < len; i++)
    {
        mem[i] = mem[i + removed];
    }

    len -= removed;
}


void Vec::push(int el)
{
    if (len == cap)
    {
        if (cap > INT_MAX / 2)
        {
            throw std::overflow_error("capacity overflow");
        }
        
        resize(2 * cap);
    }

    mem[len] = el;
    len++;
}

int &Vec::first()
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[0];
}

const int &Vec::first() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[0];
}

int &Vec::last()
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[len - 1];
}

const int &Vec::last() const
{
    if (empty())
    {
        throw std::out_of_range("Vector is empty");
    }
    return mem[len - 1];
}

void Vec::clear()
{
    len = 0;
}

bool Vec::linearSearch(int x) const
{
    for (int i = 0; i < len; i++)
        if (mem[i] == x)
            return true;
    return false;
}

int Vec::binarySearch(int x) const
{
    int left = 0;
    int right = len - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (mem[mid] == x)
            return mid;

        if (mem[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

long long Vec::sum() const
{
    long long s = 0;
    for (int i = 0; i < len; i++)
        s += mem[i];
    return s;
}

double Vec::avg() const
{
    if (len == 0)
        return 0.0;

    return static_cast<double>(sum()) / len;
}

void Vec::reverse()
{
    for (int i = 0; i < len / 2; i++)
        swapInt(mem[i], mem[len - 1 - i]);
}

void Vec::reverse(int l, int r)
{
    if (l < 0 || r >= len || l > r)
    {
        throw std::out_of_range("given");
    }

    while (l < r)
    {
        swapInt(mem[l], mem[r]);
        l++;
        r--;
    }
}

void Vec::rotate(int x)
{
    if (len == 0)
        return;

    x = x % len;
    if (x < 0)
        x += len;

    if (x == 0)
        return;

    // Three-step rotation
    reverse();           // reverse whole vector
    reverse(0, x - 1);   // reverse first part
    reverse(x, len - 1); // reverse second part
}

int* Vec::begin()
{
    return mem;
}

const int* Vec::begin() const
{
    return mem;
}

int* Vec::end()
{
    return len == 0 ? mem : mem + len;
}

const int* Vec::end() const
{
    return len == 0 ? mem : mem + len;
}
