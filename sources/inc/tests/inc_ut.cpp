#include <catch2/catch_test_macros.hpp>

extern "C" {
#include "inc/inc.h"
}

TEST_CASE( "Test", "inc" ) {
    REQUIRE( inc(2) == 4 );
}
