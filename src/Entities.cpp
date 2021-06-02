#include <Entities.hpp>
#include <components/AnimationComponent.hpp>
#include <components/GraphicsComponent.hpp>
#include <components/TileComponent.hpp>

Entities::Entities()
{

}

Entities::~Entities()
{

}

GameEntity* Entities::createBall(SDL_Texture* _texture)
{
    SDL_Rect BalltextureRect = {0, 0, 100, 100};
	Components* ballComponents = new Components;
	GraphicsComponent* graphicsComponent = new GraphicsComponent(_texture, 
                                                                 BalltextureRect);
	ballComponents->GraphicsComponent = graphicsComponent;
    
    GameEntity* ball = new GameEntity(ballComponents);

	return ball;
}

GameEntity* Entities::createLevel(SDL_Texture* _texture)
{
    SDL_Rect boundaryTextureRect = {0, 0, 40, 40};
	SDL_Rect grassTextureRect = {40, 0, 40, 40};
	SDL_Rect waterTextureRect = {0, 40, 40, 40};
	SDL_Rect skyTextureRect = {40, 40, 40, 40};
	SDL_Rect textureRects[4] = {boundaryTextureRect, grassTextureRect, waterTextureRect, skyTextureRect};

	int level[30 * 20] = 
	{
        0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,  0,0,0,0,0,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  2,2,2,2,2,  2,2,2,2,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,1,1,1,1,  1,1,1,1,2,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  2,2,2,2,2,  2,2,2,2,2,  1,1,1,1,1,  1,1,1,1,1,

        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,0,0,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,
        1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1,  1,1,1,1,1
	};

	Components* levelComponents = new Components;
	TileComponent* tileComponent = new TileComponent(_texture, 
													 textureRects, 
													 level, 
													 4 ,30, 20);
	levelComponents->GraphicsComponent = tileComponent;

    GameEntity* levelEntity = new GameEntity(levelComponents, 0, 0, 38, 38);
	return levelEntity;
}

GameEntity* Entities::createPlayer(SDL_Texture* _texture)
{
    SDL_Rect PlayerTextureRect = {0, 0, 40, 40};
	Components* playerComponents = new Components;
	GraphicsComponent* graphicsComponent = new GraphicsComponent(_texture,
                                                                 PlayerTextureRect);
	AnimationComponent* animationComponent = new AnimationComponent(2, 500);
	playerComponents->GraphicsComponent = graphicsComponent;
	playerComponents->AnimationComponent = animationComponent;

    GameEntity* playerEntity = new GameEntity(playerComponents);

	return playerEntity;
}
