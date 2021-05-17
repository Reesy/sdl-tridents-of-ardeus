#pragma once
#include <AI.hpp>
#include <Collider.hpp>
#include <Graphics.hpp>

struct Components
{
    AI* AIComponent = nullptr;
    Collider* ColliderComponent = nullptr;
    Graphics* GraphicsComponent = nullptr;
};