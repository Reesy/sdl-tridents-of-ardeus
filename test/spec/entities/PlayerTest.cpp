#include "../../deps/catch_amalgamated.hpp"
#include <Entities.hpp>

TEST_CASE("Addition test") 
{
    REQUIRE( 1 == 1);
}

TEST_CASE("It should be possible to create a player entity")
{
    Entities* testEntities = new Entities();
    REQUIRE( testEntities == NULL);
}