

#pragma once
#include <array>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <Graphics.hpp>

class TileComponent: public Graphics
{
    SDL_Rect textureRects[4];
    int tiles[600];

    public:
        TileComponent();
        TileComponent(SDL_Texture* _texture, 
                      SDL_Rect _textureRects [], 
                      int _tiles []);
        ~TileComponent();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};