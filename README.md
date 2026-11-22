# Linear Containers Library

[![C++ CI](https://github.com/roslindesiredziele-hash/Custom-Linear-Containers/actions/workflows/ci.yml/badge.svg)](https://github.com/roslindesiredziele-hash/Custom-Linear-Containers/actions/workflows/ci.yml)

A collection of custom sequential container implementations written in modern C++17.

This project explores low-level memory management, dynamic storage strategies, value semantics, move semantics, algorithm complexity analysis, and software testing practices through the implementation of two fundamental linear data structures:

- **Vec** - a dynamic array inspired by `std::vector`
- **LinkedList** - a singly linked list with head and tail pointers

The repository emphasizes correctness, maintainability, testing, and modern C++ design principles.

---

## Features

### Vec (Dynamic Array)

- Dynamic contiguous storage
- Automatic capacity growth using table doubling
- O(1) random access
- Rule of Five implementation
- Deep copy semantics
- Move semantics
- Bounds-checked access
- Iterator support
- Range-based loop support
- Search algorithms
- Utility algorithms

#### Operations

```cpp
push()
pop()

erase(index)
erase(first, last)

resize()
clear()

first()
last()

linearSearch()
binarySearch()

reverse()
reverse(first, last)
rotate()

sum()
avg()
```

---

### LinkedList

- Singly linked list implementation
- Head and tail pointers
- O(1) append operation
- Rule of Five implementation
- Deep copy semantics
- Move semantics
- Dynamic resizing
- Single element removal
- Range removal
- Constant-time front/back access

#### Operations

```cpp
append()
prepend()

erase(index)
erase(first, last)

resize()
clear()

front()
back()

operator[]
size()
empty()
```

---

## Complexity Analysis

| Operation | Vec | LinkedList |
|------------|------------|------------|
| Access by index | O(1) | O(n) |
| Front access | O(1) | O(1) |
| Back access | O(1) | O(1) |
| Append | O(1) amortized | O(1) |
| Prepend | O(n) | O(1) |
| Erase | O(n) | O(n) |
| Resize | O(n) | O(n) |
| Linear search | O(n) | O(n) |
| Binary search | O(log n) | N/A |
| Reverse | O(n) | N/A |
| Rotate | O(n) | N/A |

---

## Design Highlights

### Rule of Five

Both containers implement:

```cpp
Destructor
Copy Constructor
Copy Assignment
Move Constructor
Move Assignment
```

providing predictable value semantics and safe ownership management.

---

### Table Doubling Strategy

The vector grows geometrically when capacity is exhausted:

```cpp
if (len == cap)
{
    resize(2 * cap);
}
```

This strategy provides:

- O(1) amortized append
- Efficient memory growth
- Similar behavior to `std::vector`

---

### Iterator Support

`Vec` supports range-based loops:

```cpp
Vec values(4);

values.push(1);
values.push(2);
values.push(3);
values.push(4);

for (int value : values)
{
    std::cout << value << '\n';
}
```

---

## Project Structure

```text
Custom-Linear-Containers
│
├── .github/
│   └── workflows/
│       └── ci.yml
│
├── external/
│   └── catch.hpp
│
├── Custom_Vector/
│   ├── src/
│   │   ├── Vec.h
│   │   └── Vec.cpp
│   │
│   └── tests/
│       └── Vec_TDD.cpp
│
├── Linked_List/
│   ├── src/
│   │   ├── LinkedList.h
│   │   └── LinkedList.cpp
│   │
│   └── tests/
│       └── LinkedList_TDD.cpp
│
├── CMakeLists.txt
└── README.md
```

---

## Build

Clone the repository:

```bash
git clone https://github.com/roslindesiredziele-hash/Custom-Linear-Containers.git

cd Custom-Linear-Containers
```

Configure:

```bash
cmake -S . -B build
```

Build:

```bash
cmake --build build --config Debug
```

Release build:

```bash
cmake --build build --config Release
```

---

## Testing

Run all tests:

```bash
ctest --test-dir build -C Debug --output-on-failure
```

Run individual test suites:

```bash
./build/Debug/Vec_TDD.exe

./build/Debug/LinkedList_TDD.exe
```

---

## Continuous Integration

The project uses GitHub Actions to automatically:

- Configure the project using CMake
- Build Debug configurations
- Build Release configurations
- Run all unit tests
- Verify changes on every push and pull request

---

## Technologies

- C++17
- CMake
- Catch2
- CTest
- GitHub Actions

---

## Future Improvements

### Vec

- Template support (`Vec<T>`)
- Insert operations
- Shrink-to-fit functionality
- Custom iterator class
- STL-compatible API
- Allocator support

### LinkedList

- Bidirectional iterator support
- Insert operations
- Template support (`LinkedList<T>`)
- Merge and splice operations

-r

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź

> Understanding how software works internally is the best way to build software that lasts.