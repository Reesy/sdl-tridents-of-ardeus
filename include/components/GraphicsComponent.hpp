#pragma once
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <interfaces/GraphicsInterface.hpp>

class GraphicsComponent: public GraphicsInterface
{
   
    public:
        GraphicsComponent();
        GraphicsComponent(SDL_Texture* _texture, SDL_Rect _textureRect);
        ~GraphicsComponent();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};