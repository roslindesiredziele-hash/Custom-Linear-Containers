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
double AverageLinkedList(int size,int runs);

int main()
{
    vector<int> sizes =
    {
        5,
        10,
        15,
        20,
        25,
        30,
        35,
        40,
        45,
        50,
        60,
        70,
        80,
        90,
        100,
        150,
        200,
        250,
        300,
        350,
        400,
        450,
        500,
        600,
        700,
        800,
        900,
        1000,
        1200,
        1400,
        1600,
        1800,
        2000,
        3000,
        4000,
        5000,
        10000,
        20000,
        50000,
        100000,
        500000,
        1000000
    };

    constexpr int runs = 20;

    ofstream file("data/data.csv");

    file << "Size," << "VecMs," << "StdVectorMs," << "LinkedListMs\n";

    for(int size : sizes)
    {
        double vecTime = AverageVec(size, runs);

        double stdTime = AverageStdVector(size, runs);

        double listTime = AverageLinkedList(size, runs);

        file << size << "," << vecTime << "," << stdTime << "," << listTime << "\n";

        cout << "Finished size " << size << '\n';
    }

    file.close();

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

double AverageStdVector(int size, int runs)
{
    double total = 0;

    for(int i = 0; i < runs; i++)
    {
        total += BenchmarkStdVector(size);
    }

    return total / runs;
}

double AverageLinkedList(int size,int runs)
{
    double total = 0;

    for(int i = 0; i < runs; i++)
    {
        total += BenchmarkLinkedList(size);
    }

    return total / runs;
}