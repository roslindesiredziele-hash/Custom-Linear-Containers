#define CATCH_CONFIG_MAIN

#include "../external/catch.hpp"

#include "../src/LinkedList.h"

TEST_CASE("Default constructor creates empty list")
{
    LinkedList L;

    REQUIRE(L.empty());
    REQUIRE(L.getlength() == 0);
}

