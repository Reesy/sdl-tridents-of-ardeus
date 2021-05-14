#include <Collider.hpp>
#include <iostream>

Collider::Collider()
{

	std::cout << "Collider not yet implemented" << std::endl;
};

Collider::~Collider()
{
	std::cout << "Collider not yet implemented" << std::endl;
};

void Collider::receive(int _message)
{
	std::cout << "The message is: " << _message << std::endl;
	return;
}