#pragma once
#include <interfaces/ComponentInterface.hpp>

class ColliderInterface: ComponentInterface
{
public:
	ColliderInterface();
	virtual ~ColliderInterface();
	void receive(int message);
};