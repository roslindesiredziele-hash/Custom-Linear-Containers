cmake_minimum_required(VERSION 3.10)

project(CustomDynamicVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_library
(
    Vec
    src/Vec.cpp
)

add_library(
    LinkedList
    linked_list/src/LinkedList.cpp
)

target_include_directories(
    Vec PUBLIC src
)

add_executable(
    Vec_TDD
    tests/Vec_TDD.cpp
)

add_executable(
    LinkedList_TDD
    linked_list/tests/LinkedList_TDD.cpp
)

target_link_libraries(
    Vec_TDD
    Vec
)

target_link_libraries(
    LinkedList_TDD
    LinkedList
)

target_include_directories(Vec_TDD PRIVATE
    src
    external
)

target_include_directories(
    LinkedList PUBLIC
    linked_list/src
)

target_include_directories(
    LinkedList_TDD PRIVATE
    linked_list/src
    external
)

add_test
(
    NAME VecTests
    COMMAND Vec_TDD
)

add_test(
    NAME LinkedListTests
    COMMAND LinkedList_TDD
)