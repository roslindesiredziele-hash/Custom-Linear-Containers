#define CATCH_CONFIG_MAIN

#include "../external/catch.hpp"

#include "../src/LinkedList.h"

TEST_CASE("Default constructor creates empty list")
{
    LinkedList L;

    REQUIRE(L.empty());
    REQUIRE(L.getlength() == 0);
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

