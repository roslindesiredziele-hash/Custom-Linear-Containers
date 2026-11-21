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
        100,
        500,
        1000,
        5000,
        10000,
        20000,
        50000,
        100000,
        500000,
        1000000
    };

    constexpr int runs = 20;

    ofstream file("benchmarks/data/data.csv");

    if(!file)
    {
        cerr << "Failed to open data.csv\n";
        return 1;
    }

    file << "Size," << "VecMs," << "StdVectorMs," << "LinkedListMs\n";

    for(int size : sizes)
    {
        double vecTime = AverageVec(size, runs);

        double stdTime = AverageStdVector(size, runs);

        double listTime = AverageLinkedList(size, runs);

        file << size << "," << vecTime << "," << stdTime << "," << listTime << "\n";

        cout << "Finished size " << size << '\n' << flush;
    }

    file.close();

    ofstream capacityfile("benchmarks/data/capacity_growth.csv");

    if(!capacityfile)
    {
        cerr << "Failed to open capacity_growth.csv\n";
        return 1;
    }
    
    capacityfile << "Size,Capacity\n";
    Vec v(1);
    
    capacityfile << 0 << "," << v.capacity() << '\n';
    
    for(int i = 0; i < 1000000; i++)
    {
        int oldCapacity = v.capacity();
        v.push(i);
        
        if(v.capacity() != oldCapacity)
        {
            capacityfile << v.size() << "," << v.capacity() << '\n';
        }
    }

    capacityfile.close();

    ofstream stdCapacityfile("benchmarks/data/std_capacity_growth.csv");

    if(!stdCapacityfile)
    {
        cerr << "Failed to open std_capacity_growth.csv\n";
        return 1;
    }
    
    stdCapacityfile << "Size,Capacity\n";
    
    std::vector<int> stdVec;
    
    stdCapacityfile << 0 << "," << stdVec.capacity() << '\n';
    
    for(int i = 0; i < 1000000; i++)
    {
        size_t oldCapacity = stdVec.capacity();
        
        stdVec.push_back(i);
        
        if(stdVec.capacity() != oldCapacity)
        {
            stdCapacityfile << stdVec.size() << "," << stdVec.capacity() << '\n';
        }
    }
    
    stdCapacityfile.close();
    
    cout << "Benchmark complete.\n";

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