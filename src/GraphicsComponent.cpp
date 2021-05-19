#include <GraphicsComponent.hpp>
#include <GameEntity.hpp>


GraphicsComponent::GraphicsComponent(SDL_Texture* _texture, SDL_Rect _textureRect)
{
    this->texture = _texture;
    this->textureRect = _textureRect;
    return;
};

GraphicsComponent::~GraphicsComponent()
{
    return;
};

void GraphicsComponent::render(GameEntity& _gameEntity, SDL_Renderer* _renderer)
{
    positionRect = {_gameEntity.x, _gameEntity.y, _gameEntity.w, _gameEntity.h};
	SDL_RenderCopy(_renderer, 
                   this->texture, 
                   &textureRect, 
                   &positionRect);
    return;
};