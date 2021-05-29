#include <iostream>
#include <interfaces/GraphicsInterface.hpp>

GraphicsInterface::GraphicsInterface()
{
	return;
}

GraphicsInterface::~GraphicsInterface()
{
	return;
}

void GraphicsInterface::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}