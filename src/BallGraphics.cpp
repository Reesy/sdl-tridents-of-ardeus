#include <BallGraphics.hpp>
#include <GameEntity.hpp>

BallGraphics::BallGraphics(SDL_Texture* _texture)
{
    this->texture = _texture;
    return;
};

BallGraphics::~BallGraphics()
{
    return;
};

void BallGraphics::render(GameEntity& _gameEntity, SDL_Renderer* _renderer)
{
    _gameEntity.send(1446);
    SDL_Rect temp = {_gameEntity.x, _gameEntity.y, _gameEntity.w, _gameEntity.h};
    //Set up the circle on the next render frame.
    //TODO dont use temp;
	SDL_RenderCopy(_renderer, this->texture, &temp, &temp);
    return;
};