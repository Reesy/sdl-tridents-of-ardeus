#pragma once
#include <GameEntity.hpp>

class Entities
{
    public:
    Entities();
    ~Entities();
    GameEntity* createBall(SDL_Texture* _texture);
    GameEntity* createLevel(SDL_Texture* _texture);
    GameEntity* createPlayer(SDL_Texture* _texture);
    

};