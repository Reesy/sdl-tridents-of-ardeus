#pragma once
#include <Component.hpp>

class Collider: Component
{
public:
	Collider();
	virtual ~Collider();
	void receive(int message);
};