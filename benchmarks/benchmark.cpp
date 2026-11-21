#include "Vec.h"
#include "LinkedList.h"

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

double BenchmarkVec(int);
double BenchmarkStdVector(int);
double BenchmarkLinkedList(int);

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq);
double AverageVec(int size, int runs);
double AverageStdVector(int size, int runs);



int main()
{
    return 0;
}


double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    return static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
}

double BenchmarkVec(int size)
{
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    Vec v(1);

    QueryPerformanceCounter(&start);

    for(int i = 0; i < size; i++)
    {
        v.push(i);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double BenchmarkStdVector(int size)
{
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

    std::vector<int> v;

    QueryPerformanceCounter(&start);

    for(int i = 0; i < size; i++)
    {
        v.push_back(i);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double BenchmarkLinkedList(int size)
{
    LARGE_INTEGER freq;
    LARGE_INTEGER start;
    LARGE_INTEGER end;

    QueryPerformanceFrequency(&freq);

   LinkedList L;

    QueryPerformanceCounter(&start);

    for(int i = 0; i < size; i++)
    {
        L.append(i);
    }

    QueryPerformanceCounter(&end);

    return MeasureMilliseconds(start, end, freq);
}

double AverageVec(int size, int runs)
{
    double total = 0;

    for(int i = 0; i < runs; i++)
    {
        total += BenchmarkVec(size);
    }

    return total / runs;
}

