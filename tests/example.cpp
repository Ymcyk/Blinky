#include <catch2/catch_test_macros.hpp>
#include <fff.h>

#include <cstdint>

DEFINE_FFF_GLOBALS;

void DISPLAY_init();

FAKE_VOID_FUNC(DISPLAY_init);

uint32_t factorial( uint32_t number ) {
    return number <= 1 ? number : factorial(number-1) * number;
}

TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial( 1) == 1 );
    REQUIRE( factorial( 2) == 2 );
    REQUIRE( factorial( 3) == 6 );
    REQUIRE( factorial(10) == 3'628'800 );

    DISPLAY_init();

    REQUIRE( DISPLAY_init_fake.call_count == 1 );
}
