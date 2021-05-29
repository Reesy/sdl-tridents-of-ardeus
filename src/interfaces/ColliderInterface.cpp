#include <iostream>
#include <interfaces/ColliderInterface.hpp>

ColliderInterface::ColliderInterface()
{

	std::cout << "ColliderInterface not yet implemented" << std::endl;
}

ColliderInterface::~ColliderInterface()
{
	std::cout << "ColliderInterface not yet implemented" << std::endl;
}

void ColliderInterface::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}