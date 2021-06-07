#include <Resources.hpp>

SDL_Texture* Resources::loadTexture(const std::string &file, SDL_Renderer *ren)
{
    SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr)
	{
		std::cout << "Could not load texture" << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}
	return texture;
}