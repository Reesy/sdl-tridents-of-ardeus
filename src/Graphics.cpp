#include <iostream>
#include <Graphics.hpp>

Graphics::Graphics()
{
	return;
}

Graphics::~Graphics()
{
	return;
}

void Graphics::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}