# Linear Containers Library

[![C++ CI](https://github.com/roslindesiredziele-hash/Custom-Linear-Containers/actions/workflows/ci.yml/badge.svg)](https://github.com/roslindesiredziele-hash/Custom-Linear-Containers/actions/workflows/ci.yml)

A collection of custom sequential container implementations written in modern C++17.

This project explores low-level memory management, dynamic storage strategies, value semantics, move semantics, algorithm complexity analysis, and software testing practices through the implementation of two fundamental linear data structures:

- **Vec** – a dynamic array inspired by `std::vector`
- **LinkedList** – a singly linked list with head and tail pointers

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
- O(1) prepend operation
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
~Container();

Container(const Container&);
Container& operator=(const Container&);

Container(Container&&) noexcept;
Container& operator=(Container&&) noexcept;
```

This ensures safe resource ownership, predictable value semantics, and efficient transfers of resources.

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

Build (Debug):

```bash
cmake --build build --config Debug
```

Build (Release):

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
build/Debug/Vec_TDD.exe

build/Debug/LinkedList_TDD.exe
```

### Latest Results

#### Vec

```text
All tests passed (112 assertions in 42 test cases)
```

#### LinkedList

```text
All tests passed (48 assertions in 17 test cases)
```

#### Total

```text
59 test cases
160 assertions
```

CTests:

```text
100% tests passed out of 2

VecTests ................. Passed
LinkedListTests .......... Passed
```

---

## Usage Examples

### Vec

```cpp
Vec numbers(2);

numbers.push(10);
numbers.push(20);
numbers.push(30);

std::cout << numbers << '\n';
```

Output:

```text
[10; 20; 30]
```

### Erasing an Element

```cpp
Vec v(5);

v.push(10);
v.push(20);
v.push(30);

v.erase(1);
```

Result:

```text
[10; 30]
```

### Erasing a Range

```cpp
Vec v(6);

for (int i = 1; i <= 6; i++)
{
    v.push(i);
}

v.erase(1, 3);
```

Result:

```text
[1; 5; 6]
```

---

### LinkedList

```cpp
LinkedList list;

list.append(10);
list.append(20);
list.prepend(5);

std::cout << list.front() << '\n';
std::cout << list.back() << '\n';
```

Output:

```text
5
20
```

---

## Continuous Integration

The project uses GitHub Actions to automatically:

- Configure the project using CMake
- Build Debug configurations
- Build Release configurations
- Execute all unit tests
- Validate pushes and pull requests

---

## Testing & Quality Assurance

The project uses:

- **Catch2** for unit testing
- **CTest** for test execution
- **CMake** for build configuration
- **GitHub Actions** for continuous integration

### Coverage Highlights

#### Vec

- Copy constructor
- Copy assignment
- Move constructor
- Move assignment
- Self move assignment
- Iterator support
- Dynamic resizing
- ExceptionSingle element erase
- Range erase
- Search algorithms
- Reverse and rotate operations

#### LinkedList

- Copy constructor
- Copy assignment
- Move constructor
- Move assignment
- Self assignment
- Append and prepend
- Front and back access
- Resize operations
- Single element erase
- Range erase
- Exception handling

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

- Template support (`LinkedList<T>`)
- Insert operations
- Bidirectional iterator support
- Merge operations
- Splice operations

---

## Author

**Desire Roslin Dziele**  
Computer Science Student  
University of Łódź

> Understanding how software works internally is the best way to build software that lasts.