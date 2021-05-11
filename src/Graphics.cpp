#include <Graphics.hpp>
#include <iostream>
#include <SDL_image.h>

Graphics::Graphics()
{
	std::cout << "Graphics constructor not yet implemented" << std::endl;
	return;
};

Graphics::~Graphics()
{
	std::cout << "Graphics destructor not yet implemented" << std::endl;
};

void Graphics::render()
{
	
};

void Graphics::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}