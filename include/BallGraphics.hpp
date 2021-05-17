#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.hpp>

class BallGraphics: public Graphics
{
    SDL_Rect positionRect = {0, 0, 0, 0};
    SDL_Rect textureRect = {0, 0, 0, 0};
    
    public:
        BallGraphics(SDL_Texture* _texture, SDL_Rect _textureRect);
        ~BallGraphics();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};