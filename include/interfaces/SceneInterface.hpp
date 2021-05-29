#pragma once

class SceneInterface
{
public:

	//Scene .attach bucket of entities, render/update basically goes through bucket checks existence of components and calls it

	SceneInterface();
	virtual ~SceneInterface();
};