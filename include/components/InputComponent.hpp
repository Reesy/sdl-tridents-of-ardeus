#pragma once
#include <SDL.h>
#include <interfaces/InputInterface.hpp>

class InputComponent
{
    public:
        void update(SDL_Event* _event);

};