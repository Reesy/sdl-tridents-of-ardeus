#pragma once
#include <interfaces/ComponentInterface.hpp>

class GameEntity;

class AnimationInterface: public ComponentInterface
{
public:
    AnimationInterface();
    AnimationInterface(int _numberOfFrames,
              int _frameDuration);
    virtual ~AnimationInterface();
    virtual void update(GameEntity& _gameEntity, double _dt) = 0;
    void receive(int message);
};