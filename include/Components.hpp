#pragma once
#include <interfaces/AIInterface.hpp>
#include <interfaces/AnimationInterface.hpp>
#include <interfaces/ColliderInterface.hpp>
#include <interfaces/GraphicsInterface.hpp>
#include <interfaces/InputInterface.hpp>

struct Components
{
    AIInterface* AIComponent = nullptr;
    AnimationInterface* AnimationComponent = nullptr;
    ColliderInterface* ColliderComponent = nullptr;
    GraphicsInterface* GraphicsComponent = nullptr;
    InputInterface* InputComponent = nullptr;
};