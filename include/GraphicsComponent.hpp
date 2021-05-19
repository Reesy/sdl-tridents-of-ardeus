#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.hpp>

class GraphicsComponent: public Graphics
{
   
    public:
        GraphicsComponent();
        GraphicsComponent(SDL_Texture* _texture, SDL_Rect _textureRect);
        ~GraphicsComponent();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};