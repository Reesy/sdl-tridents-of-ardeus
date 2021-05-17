#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.hpp>

class GraphicsComponent: public Graphics
{
    SDL_Rect positionRect = {0, 0, 0, 0};
    SDL_Rect textureRect = {0, 0, 0, 0};
    
    public:
        GraphicsComponent(SDL_Texture* _texture, SDL_Rect _textureRect);
        ~GraphicsComponent();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};