#pragma once
#include <Component.hpp>

class AI : Component
{
public:
	AI();
	virtual ~AI();
	void receive(int message);
};