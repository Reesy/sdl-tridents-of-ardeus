#include <components/TileComponent.hpp>
#include <GameEntity.hpp>

TileComponent::TileComponent()
{
    return;
}

TileComponent::TileComponent(SDL_Texture* _texture, 
                             SDL_Rect _textureRects [], 
                             int _tiles [],
                             int _numberOfUniqueTiles,
                             int _tileMapWidth,
                             int _tileMapHeight)
{
    this->tileMapWidth = _tileMapWidth;
    this->tileMapHeight = _tileMapHeight;
    this->texture = _texture;
    
    this->textureRects = new SDL_Rect[_numberOfUniqueTiles];
    for (int i = 0; i < _numberOfUniqueTiles; i++)
    {
        this->textureRects[i] = _textureRects[i];
    };
    
    this->tiles = new int[_tileMapWidth * _tileMapHeight];
    for (int i = 0; i < (_tileMapWidth * _tileMapHeight); i++)
    {
        this->tiles[i] = _tiles[i];
    };

    return;
}


TileComponent::~TileComponent()
{
    return;
}

void TileComponent::render(GameEntity& _gameEntity, SDL_Renderer* _renderer)
{
    positionRect = {_gameEntity.x, 
                    _gameEntity.y, 
                    _gameEntity.w, 
                    _gameEntity.h};
    
    for (int x = 0; x < this->tileMapWidth; ++x)
    {
        for (int y = 0; y < this->tileMapHeight; ++y)
        {
            positionRect.x = _gameEntity.x + (x * _gameEntity.w);
            positionRect.y = _gameEntity.y + (y * _gameEntity.h);
            
            SDL_RenderCopy(_renderer, 
                           this->texture, 
                           &textureRects[this->tiles[ (y * this->tileMapWidth) + x] ],
                           &positionRect);
        };
   };

    return;
}