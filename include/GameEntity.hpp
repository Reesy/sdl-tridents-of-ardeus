#pragma once
#include <Component.hpp>
#include <Graphics.hpp>
#include <array>

class GameEntity
{
	int x;
	int y;
	static const int MAX_COMPONENTS = 10;
	std::array<Component*, MAX_COMPONENTS> components = {0};
public:
	GameEntity(std::array<Component*, MAX_COMPONENTS> _components);
	~GameEntity();
	void send(int message);
};