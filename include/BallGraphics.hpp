#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.hpp>

class BallGraphics: public Graphics
{

    public:
        BallGraphics(SDL_Texture* _texture);
        ~BallGraphics();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};