

#pragma once
#include <array>
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include <interfaces/GraphicsInterface.hpp>

class TileComponent: public GraphicsInterface
{
    SDL_Rect *textureRects;
    int *tiles;
    int tileMapWidth = 0;
    int tileMapHeight = 0;

    public:
        TileComponent();
        TileComponent(SDL_Texture* _texture, 
                      SDL_Rect _textureRects [], 
                      int _tiles [],
                      int _numberOfUniqueTiles,
                      int _tileMapWidth,
                      int _tileMapHeight);
        ~TileComponent();
        void render(GameEntity& _gameEntity, SDL_Renderer* _renderer);
};