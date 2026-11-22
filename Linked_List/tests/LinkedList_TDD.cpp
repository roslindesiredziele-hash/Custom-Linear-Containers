#define CATCH_CONFIG_MAIN

#include "../../external/catch.hpp"

#include "../src/LinkedList.h"

#include <utility>

TEST_CASE("Default constructor creates empty list")
{
    LinkedList L;

    REQUIRE(L.empty());
    REQUIRE(L.size() == 0);
}

TEST_CASE("Self assignment")
{
    LinkedList L;

    L.append(10);
    L.append(20);

    L = L;

    REQUIRE(L.size() == 2);
    REQUIRE(L[0] == 10);
    REQUIRE(L[1] == 20);
}

TEST_CASE("Copy constructor performs deep copy")
{
    LinkedList original;

    original.append(10);
    original.append(20);

    LinkedList copy(original);

    copy[0] = 999;

    REQUIRE(original[0] == 10);
    REQUIRE(copy[0] == 999);
}

TEST_CASE("Copy assignment performs deep copy")
{
    LinkedList original;

    original.append(1);
    original.append(2);

    LinkedList copy;

    copy = original;

    copy[0] = 100;

    REQUIRE(original[0] == 1);
    REQUIRE(copy[0] == 100);
}

TEST_CASE("Move constructor transfers ownership")
{
    LinkedList original;

    original.append(1);
    original.append(2);

    LinkedList moved(std::move(original));

    REQUIRE(moved.size() == 2);

    REQUIRE(original.empty());
}
TEST_CASE("Move assignment transfers ownership")
{
    LinkedList original;

    original.append(1);
    original.append(2);

    LinkedList moved;

    moved = std::move(original);

    REQUIRE(moved.size() == 2);

    REQUIRE(original.empty());
}

TEST_CASE("Operator[] throws for invalid index")
{
    LinkedList L;

    L.append(10);

    REQUIRE_THROWS_AS(
        L[-1],
        std::out_of_range);

    REQUIRE_THROWS_AS(
        L[1],
        std::out_of_range);
}

TEST_CASE("Append increases size")
{
    LinkedList L;

    L.append(10);
    L.append(20);
    L.append(30);

    REQUIRE(L.size() == 3);

    REQUIRE(L[0] == 10);
    REQUIRE(L[1] == 20);
    REQUIRE(L[2] == 30);
}

TEST_CASE("Prepend inserts at beginning")
{
    LinkedList L;

    L.prepend(10);
    L.prepend(20);
    L.prepend(30);

    REQUIRE(L.size() == 3);

    REQUIRE(L[0] == 30);
    REQUIRE(L[1] == 20);
    REQUIRE(L[2] == 10);
}

TEST_CASE("Front and back return correct elements")
{
    LinkedList L;

    L.append(10);
    L.append(20);
    L.append(30);

    REQUIRE(L.front() == 10);
    REQUIRE(L.back() == 30);
}

TEST_CASE("Front throws for empty list")
{
    LinkedList L;

    REQUIRE_THROWS_AS(
        L.front(),
        std::logic_error);
}

TEST_CASE("Back throws for empty list")
{
    LinkedList L;

    REQUIRE_THROWS_AS(
        L.back(),
        std::logic_error);
}

TEST_CASE("Clear removes all elements")
{
    LinkedList L;

    L.append(1);
    L.append(2);
    L.append(3);

    L.clear();

    REQUIRE(L.empty());
    REQUIRE(L.size() == 0);

    REQUIRE_THROWS_AS(
        L.front(),
        std::logic_error);
}

TEST_CASE("Resize grows list")
{
    LinkedList L;

    L.append(1);
    L.append(2);

    L.resize(5);

    REQUIRE(L.size() == 5);

    REQUIRE(L[0] == 1);
    REQUIRE(L[1] == 2);
    REQUIRE(L[2] == 0);
    REQUIRE(L[3] == 0);
    REQUIRE(L[4] == 0);
}

TEST_CASE("Resize shrinks list")
{
    LinkedList L;

    for(int i = 1; i <= 5; i++)
    {
        L.append(i);
    }

    L.resize(3);

    REQUIRE(L.size() == 3);

    REQUIRE(L[0] == 1);
    REQUIRE(L[1] == 2);
    REQUIRE(L[2] == 3);
}

TEST_CASE("Erase removes one element")
{
    LinkedList L;

    L.append(1);
    L.append(2);
    L.append(3);
    L.append(4);

    L.erase(1);

    REQUIRE(L.size() == 3);

    REQUIRE(L[0] == 1);
    REQUIRE(L[1] == 3);
    REQUIRE(L[2] == 4);
}

TEST_CASE("Erase range removes multiple elements")
{
    LinkedList L;

    for(int i = 1; i <= 6; i++)
    {
        L.append(i);
    }

    L.erase(1, 3);

    REQUIRE(L.size() == 3);

    REQUIRE(L[0] == 1);
    REQUIRE(L[1] == 5);
    REQUIRE(L[2] == 6);
}