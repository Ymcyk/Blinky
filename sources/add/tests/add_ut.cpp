#include <catch2/catch_test_macros.hpp>

#include <cstdint>

extern "C" {
#include "add/add.h"
}

TEST_CASE( "Test", "add" ) {
    REQUIRE( add(2, 2) == 4 );
}
