cmake_minimum_required(VERSION 3.10)

project(LinearContainersLibraryr)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_library(
    Vec
    Custom_Vector/src/Vec.cpp
)

add_library(
    LinkedList
    Linked_List/src/LinkedList.cpp
)

target_include_directories(
    Vec PUBLIC
    Custom_Vector/src
)

target_include_directories(
    LinkedList PUBLIC
    Linked_List/src
)

add_executable(
    Vec_TDD
    Custom_Vector/tests/Vec_TDD.cpp
)

add_executable(
    LinkedList_TDD
    Linked_List/tests/LinkedList_TDD.cpp
)

target_link_libraries(
    Vec_TDD
    Vec
)

target_link_libraries(
    LinkedList_TDD
    LinkedList
)

target_include_directories(
    Vec_TDD PRIVATE
    Custom_Vector/src
    external
)

target_include_directories(
    LinkedList_TDD PRIVATE
    Linked_List/src
    external
)

add_test(
    NAME VecTests
    COMMAND Vec_TDD
)

add_test(
    NAME LinkedListTests
    COMMAND LinkedList_TDD
)