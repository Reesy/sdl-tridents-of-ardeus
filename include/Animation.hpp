#pragma once
#include <Component.hpp>

class GameEntity;

class Animation: public Component
{
public:
    Animation();
    Animation(int _numberOfFrames,
              int _frameDuration);
    virtual ~Animation();
    virtual void update(GameEntity& _gameEntity, double _dt) = 0;
    void receive(int message);
};