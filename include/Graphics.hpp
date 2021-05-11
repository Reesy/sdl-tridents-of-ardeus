#pragma once
#include <Component.hpp>

class Graphics: public Component
{
public:
	Graphics();
	~Graphics();
	void render();
	void receive(int message);
};