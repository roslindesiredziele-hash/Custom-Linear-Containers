# Vec

[![C++ CI](https://github.com/roslindesiredziele-hash/Vector/actions/workflows/ci.yml/badge.svg)](https://github.com/roslindesiredziele-hash/Vector/actions/workflows/ci.yml)

A custom dynamic array implementation in modern C++ inspired by `std::vector`.

This project was developed to explore low-level memory management, dynamic storage growth strategies, value semantics, iterator design, and software testing practices in modern C++. The container implements automatic capacity growth using the table-doubling technique and supports common operations expected from a dynamic array.

---

## Features

### Memory Management

- Dynamic memory allocation
- Automatic capacity doubling
- RAII-compliant resource management
- Deep copy semantics
- Move semantics

### Element Access

- `operator[]`
- `get()`
- `first()`
- `last()`

### Capacity Management

- `size()`
- `capacity()`
- `empty()`
- `resize()`
- `clear()`

### Modification Operations

- `push()`
- `pop()`
- `deleteMe()`
- `deleteUs()`

### Searching

- `linearSearch()`
- `binarySearch()`

### Utility Algorithms

- `reverse()`
- `reverse(int l, int r)`
- `rotate()`
- `sum()`
- `avg()`

### Iterator Support

- `begin()`
- `end()`

Supports range-based loops:

```cpp
for (int value : vec)
{
    std::cout << value << '\n';
}
```

---

## Complexity Analysis

| Operation | Complexity |
|------------|------------|
| Access (`[]`) | O(1) |
| `push()` (amortized) | O(1) |
| `push()` (worst case) | O(n) |
| `pop()` | O(1) |
| `resize()` | O(n) |
| `deleteMe()` | O(n) |
| `deleteUs()` | O(n) |
| `linearSearch()` | O(n) |
| `binarySearch()` | O(log n) |
| `reverse()` | O(n) |
| `rotate()` | O(n) |

---

## Project Structure

```text
Vector
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── external/
│   └── catch.hpp
│
├── src/
│   ├── Vec.cpp
│   └── Vec.h
│
├── tests/
│   └── Vec_TDD.cpp
│
├── CMakeLists.txt
│
└── README.md
```

---

## Installation

Clone the repository:

```bash
git clone https://github.com/roslindesiredziele-hash/Vector.git
cd Vector
```

---

## Build

Configure the project:

```bash
cmake -S . -B build
```

Build the project:

```bash
cmake --build build
```

---

## Testing

Run all tests using CTest:

```bash
ctest --test-dir build -C Debug --output-on-failure
```

Run the test executable directly:

```bash
./build/Debug/Vec_TDD.exe
```

Expected output:

```text
===============================================================================
All tests passed (91 assertions in 36 test cases)
```

---

## Usage Examples

### Creating a Vector

```cpp
#include "Vec.h"

int main()
{
    Vec numbers(2);

    numbers.push(10);
    numbers.push(20);
    numbers.push(30);
}
```

---

### Element Access

```cpp
Vec v(3);

v.push(10);
v.push(20);
v.push(30);

std::cout << v[1] << '\n';
std::cout << v.first() << '\n';
std::cout << v.last() << '\n';
```

Output:

```text
20
10
30
```

---

### Deleting a Single Element

```cpp
Vec v(5);

v.push(10);
v.push(20);
v.push(30);

v.deleteMe(2);
```

Result:

```text
[10; 30]
```

---

### Deleting a Range

```cpp
Vec v(6);

for (int i = 1; i <= 6; i++)
{
    v.push(i);
}

v.deleteUs(2, 4);
```

Result:

```text
[1; 5; 6]
```

---

### Searching

```cpp
Vec v(5);

v.push(1);
v.push(3);
v.push(5);
v.push(7);
v.push(9);

std::cout << v.linearSearch(5) << '\n';
std::cout << v.binarySearch(5) << '\n';
```

Output:

```text
1
2
```

---

### Rotation

```cpp
Vec v(4);

v.push(1);
v.push(2);
v.push(3);
v.push(4);

v.rotate(1);
```

Result:

```text
[4; 1; 2; 3]
```

---

## Testing & Quality Assurance

The project uses:

- **Catch2** for unit testing
- **CTest** for test execution
- **CMake** for build configuration
- **GitHub Actions** for continuous integration

### Project Statistics

- 36 automated test cases
- 91 assertions
- Copy constructor coverage
- Move constructor coverage
- Assignment operator coverage
- Iterator testing
- Exception testing
- Dynamic resize testing

---

## Design Highlights

### Table Doubling Strategy

When capacity is exhausted, the vector automatically grows:

```cpp
if (len == cap)
{
    resize(2 * cap);
}
```

This provides amortized **O(1)** append operations.

### Value Semantics

The container supports:

- Copy construction
- Copy assignment
- Move construction

allowing safe and predictable ownership management.

### STL-Like Interface

Iterator support enables:

```cpp
for (int value : vec)
{
    // ...
}
```

making the container feel familiar to users of `std::vector`.

---

## Future Improvements

- Template support (`Vec<T>`)
- Custom iterator class
- Insert operations
- Shrink-to-fit functionality
- STL-compatible API
- Allocator support
- Strong exception guarantees

---

## Technologies

- C++17
- CMake
- Catch2
- CTest
- GitHub Actions

---

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź

> *Understanding how software works internally is the bestbuild software that lasts.*