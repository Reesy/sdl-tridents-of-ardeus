#include <TileComponent.hpp>
#include <GameEntity.hpp>

TileComponent::TileComponent()
{
    return;
};

TileComponent::TileComponent(SDL_Texture* _texture, 
                             SDL_Rect _textureRects [], 
                             int _tiles [])
{
    this->texture = _texture;
    
    for (int i = 0; i < 4; i++)
    {
        this->textureRects[i] = _textureRects[i];
    };

    for (int i = 0; i < 600; i++)
    {
        this->tiles[i] = _tiles[i];
    };

   // this->textureRect = _textureRects[0];
    return;
};


TileComponent::~TileComponent()
{
    return;
};

void TileComponent::render(GameEntity& _gameEntity, SDL_Renderer* _renderer)
{
    positionRect = {_gameEntity.x, 
                    _gameEntity.y, 
                    _gameEntity.w, 
                    _gameEntity.h};
    
    // 30 width 
    // 20 height
    for (int i = 0; i < 30; ++i)
    {
        for (int x = 0; x < 20; ++x)
        {
          //  std::cout << this->tiles[i*x];
            SDL_RenderCopy(_renderer, 
                           this->texture, 
                            &textureRects[this->tiles[ (x * 30) + i] ],
                            &positionRect);

            positionRect = {_gameEntity.x + (i * 40),
                    _gameEntity.y + (x * 40),
                    _gameEntity.w,
                    _gameEntity.h};
        };
     //   std::cout << std::endl;
   };

    return;
};