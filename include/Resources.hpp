#pragma once
#include <SDL_image.h>
#include <string>
#include <iostream>


class Resources
{
    public: 
        static SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren);
};