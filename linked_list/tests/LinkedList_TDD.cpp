#define CATCH_CONFIG_MAIN

#include "../external/catch.hpp"

#include "../src/LinkedList.h"

TEST_CASE("Default constructor creates empty list")
{
    LinkedList L;

    REQUIRE(L.empty());
    REQUIRE(L.getlength() == 0);
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

    REQUIRE(moved.getlength() == 2);

    REQUIRE(original.empty());
}

TEST_CASE("Append increases size")
{
    LinkedList L;

    L.append(10);
    L.append(20);
    L.append(30);

    REQUIRE(L.getlength() == 3);

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

    REQUIRE(L.getlength() == 3);

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

