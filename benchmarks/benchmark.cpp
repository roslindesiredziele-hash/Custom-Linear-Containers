#include "Vec.h"
#include "LinkedList.h"

#include <Windows.h>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

double MeasureMilliseconds(LARGE_INTEGER start, LARGE_INTEGER end, LARGE_INTEGER freq)
{
    return static_cast<double>(end.QuadPart - start.QuadPart) * 1000.0 / freq.QuadPart;
}




