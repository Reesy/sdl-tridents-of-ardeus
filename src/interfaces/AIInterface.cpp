
#include <iostream>
#include <interfaces/AIInterface.hpp>

AIInterface::AIInterface()
{
	std::cout << "AIInterface not yet implemented" << std::endl;
}

AIInterface::~AIInterface()
{
	std::cout << "AIInterface not yet implemented" << std::endl;
}

void AIInterface::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}