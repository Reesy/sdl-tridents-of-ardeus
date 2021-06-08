#pragma once
#include <SDL.h>
#include <interfaces/ComponentInterface.hpp>

class InputInterface: public ComponentInterface
{
    public:
    virtual void update(SDL_Event* _event) = 0;
};