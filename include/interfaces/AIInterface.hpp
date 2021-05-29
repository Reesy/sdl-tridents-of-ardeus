#pragma once
#include <interfaces/ComponentInterface.hpp>

class AIInterface : ComponentInterface
{
public:
	AIInterface();
	virtual ~AIInterface();
	void receive(int message);
};