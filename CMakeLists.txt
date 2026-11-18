cmake_minimum_required(VERSION 3.10)

project(CustomDynamicVector)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

enable_testing()

add_library(
    Vec
    src/Vec.cpp
)

target_include_directories(
    Vec PUBLIC src
)

add_executable(
    Vec_TDD
    tests/Vec_TDD.cpp
)

target_link_libraries(
    Vec_TDD
    Vec
)

target_include_directories(Vec_TDD PRIVATE
    src
    external
)

add_test(
    NAME VecTests
    COMMAND Vec_TDD
)