#include <AnimationComponent.hpp>
#include <GameEntity.hpp>
#include <iostream>

AnimationComponent::AnimationComponent(int _numberOfFrames, int _frameDuration)
{
    this->numberOfFrames = _numberOfFrames;
    this->frameDuration = _frameDuration;
    return;
};

AnimationComponent::~AnimationComponent()
{
    return;
};

void AnimationComponent::update(GameEntity& _gameEntity, double _dt)
{
    if (_gameEntity.components->GraphicsComponent == nullptr)
    {
        std::cout << "AnimationComponent::update, Entity was built without a graphics component" << std::endl;
        return;
    };

    animationFrameTimer += _dt;

    if (animationFrameTimer >= frameDuration)
    {  
        animationFrameTimer = 0;
        if (currentFrameNumber >= (numberOfFrames - 1))
        {

            currentFrameNumber = 0;
            _gameEntity.components->GraphicsComponent->textureRect.x = 0;
            //_textureRect->x = 0;
            return;
        };

        currentFrameNumber++;

        _gameEntity.components->GraphicsComponent->textureRect.x = currentFrameNumber *   _gameEntity.components->GraphicsComponent->textureRect.w;
       // _textureRect->x = currentFrameNumber * width;
    };

    return;

};
