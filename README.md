# Vec

A custom dynamic array implementation in modern C++ inspired by `std::vector`.

## Features

- Dynamic memory allocation
- Capacity doubling
- Deep copy semantics
- Move semantics
- Iterator support
- Bounds-checked element access
- Single element deletion
- Range deletion
- Search operations
- Container utility functions

## Implemented Operations

### Access

- `operator[]`
- `get()`
- `first()`
- `last()`

### Capacity

- `size()`
- `capacity()`
- `empty()`
- `resize()`

### Modification

- `push()`
- `pop()`
- `clear()`
- `deleteMe()`
- `deleteUs()`

### Algorithms

- `linearSearch()`
- `binarySearch()`
- `reverse()`
- `rotate()`

### Statistics

- `sum()`
- `avg()`

## Testing

- Catch2
- CTest
- GitHub Actions

## Technologies

- C++17
- CMake
- Catch2
- GitHub Actions