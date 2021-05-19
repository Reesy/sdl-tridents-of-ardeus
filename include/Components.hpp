#pragma once
#include <AI.hpp>
#include <Animation.hpp>
#include <Collider.hpp>
#include <Graphics.hpp>

struct Components
{
    AI* AIComponent = nullptr;
    Animation* AnimationComponent = nullptr;
    Collider* ColliderComponent = nullptr;
    Graphics* GraphicsComponent = nullptr;
};