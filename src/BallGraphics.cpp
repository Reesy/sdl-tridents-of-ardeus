#include <BallGraphics.hpp>
#include <GameEntity.hpp>

BallGraphics::BallGraphics(SDL_Texture* _texture, SDL_Rect _textureRect)
{
    this->texture = _texture;
    this->textureRect = _textureRect;
    return;
};

BallGraphics::~BallGraphics()
{
    return;
};

void BallGraphics::render(GameEntity& _gameEntity, SDL_Renderer* _renderer)
{
    positionRect = {_gameEntity.x, _gameEntity.y, _gameEntity.w, _gameEntity.h};
	SDL_RenderCopy(_renderer, 
                   this->texture, 
                   &textureRect, 
                   &positionRect);
    return;
};