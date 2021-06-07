#include "../../deps/catch_amalgamated.hpp"
#include <Entities.hpp>
#include <Resources.hpp>

TEST_CASE("Addition test") 
{
    REQUIRE( 1 == 1);
}

SCENARIO("It should be possible to create a player entity")
{
    Entities* entities = new Entities();
    SDL_Texture* playerTexture = NULL;
    REQUIRE( entities != NULL);

    GIVEN ("I have an entity creation class ")
    {
        
        WHEN( "I create a playerEntity ")
        {
            GameEntity* playerEntity = entities->createPlayer(playerTexture);
            
            THEN ("It should have a Graphics component")
            {
                REQUIRE(playerEntity->components->GraphicsComponent != NULL);
            }

            THEN ("It should have an Animation component")
            {
                REQUIRE(playerEntity->components->GraphicsComponent != NULL);
            }

            THEN ("It should not have an AI component")
            {
                REQUIRE(playerEntity->components->AIComponent == NULL);
            }
        }

    }
}