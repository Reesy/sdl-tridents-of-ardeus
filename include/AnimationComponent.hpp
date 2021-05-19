#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <Animation.hpp>

class AnimationComponent: public Animation
{
    protected:
        int numberOfFrames = 0;
        int frameDuration = 0;
        double animationFrameTimer = 0.0;
        int currentFrameNumber = 0;
    public:
        AnimationComponent(int _numberOfFrames,
                           int _frameDuration);
        ~AnimationComponent();
        void update(GameEntity& _gameEntity, double _dt);
};