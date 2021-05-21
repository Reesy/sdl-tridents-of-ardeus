#include <stdio.h>
#include <string> 
#include <iostream>
#include <AI.hpp>
#include <AnimationComponent.hpp>
#include <GameEntity.hpp>
#include <Graphics.hpp>
#include <GraphicsComponent.hpp>
#include <Collider.hpp>
#include <Scene.hpp>
#include <TileComponent.hpp>

#if __EMSCRIPTEN__
	#include <emscripten/emscripten.h>
	#include <SDL2/SDL.h>
	#include <SDL2/SDL_image.h>
#else
	#include <SDL.h>
	#include <SDL_image.h>
#endif

#if __EMSCRIPTEN__

//Example on how to interact with JS functions via emscripten if needed
EM_JS(int, canvas_get_width, (), {
  return canvas.width;
});

EM_JS(int, canvas_get_height, (), {
  return canvas.height;
});

#endif

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
SDL_Event *event = NULL;
SDL_Texture *circle = NULL;
SDL_Texture *playerTexture = NULL;
SDL_Texture *tileSheet = NULL;
SDL_Rect textureRect;
SDL_Rect positionRect;

bool quit = false;
bool falling = true;

int SCREEN_WIDTH = 640; //640;
int SCREEN_HEIGHT = 480;//480;

double dt = 10; //The interval between updating the physics. IE update physics every 100th of a second
double currentTime = SDL_GetTicks(); // in miliseconds
double accumulator = 0.0; //This will hold the accumulation of physics steps (any time left over if the graphics renders faster than the physics simulates)
double velocity = 1;    

//Scene objects
GameEntity* ballEntity = NULL;
GameEntity* playerEntity = NULL;
GameEntity* levelEntity = NULL;

SDL_Texture* loadTexture(const std::string &file, SDL_Renderer *ren)
{
	SDL_Texture *texture = IMG_LoadTexture(ren, file.c_str());
	if (texture == nullptr)
	{
		std::cout << "Could not load texture" << std::endl;
		std::cout << IMG_GetError() << std::endl;
	}
	return texture;
};

Components* createBall()
{
	SDL_Rect BalltextureRect = {0, 0, 100, 100};
	Components* ballComponents = new Components;
	GraphicsComponent* graphicsComponent = new GraphicsComponent(circle, BalltextureRect);
	ballComponents->GraphicsComponent = graphicsComponent;
	return ballComponents;
};


Components* createLevel()
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
	TileComponent* tileComponent = new TileComponent(tileSheet, 
													 textureRects, 
													 level, 
													 4 ,30, 20);
	levelComponents->GraphicsComponent = tileComponent;
	return levelComponents;
};

Components* createPlayer()
{
	SDL_Rect PlayerTextureRect = {0, 0, 40, 40};
	Components* playerComponents = new Components;
	GraphicsComponent* graphicsComponent = new GraphicsComponent(playerTexture, PlayerTextureRect);
	AnimationComponent* animationComponent = new AnimationComponent(2, 500);
	playerComponents->GraphicsComponent = graphicsComponent;
	playerComponents->AnimationComponent = animationComponent;
	return playerComponents;
};

void init()
{
	
	//Start up SDL and make sure it went ok
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		throw("SDL failed to initialise");
	};

	window = SDL_CreateWindow("Tridents Of Ardeus!", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (window == nullptr)
	{
		SDL_Quit();
		throw("Failed to create window");
	};

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	
	if(!SDL_RenderSetLogicalSize(renderer, 640, 480))
	{
		std::cout << SDL_GetError() << std::endl;
	};
	
	if (renderer == nullptr)
	{
		window = NULL;
		SDL_Quit();
		throw("Failed to create renderer");
	}
	
	
	event = new SDL_Event();

	circle = loadTexture("resources/example_texture.png", renderer);

	playerTexture = loadTexture("resources/player_spritesheet.png", renderer);

	tileSheet = loadTexture("resources/tilesheet.png", renderer);

	playerEntity = new GameEntity(createPlayer(), 
								 (SCREEN_WIDTH / 2) - 20, 
								 (SCREEN_HEIGHT / 2) - 20, 
								 40, 
								 40);

	levelEntity = new GameEntity(createLevel(), 0, 0, 38, 38);
};

void input()
{
	if (event->type == SDL_QUIT)
	{
		quit = true;
	};


	if (event->window.event == SDL_WINDOWEVENT_RESIZED)
	{
		SDL_GetWindowSize(window, &SCREEN_WIDTH, &SCREEN_HEIGHT); 
		std::cout << "The window was resized: " <<  SCREEN_WIDTH << std::endl;
	};


	if (event->type == SDL_KEYDOWN)
	{
		switch (event->key.keysym.sym)
		{
			case SDLK_a:
				levelEntity->x -= 40;
				break;
			case SDLK_d:
				levelEntity->x += 40;
				break;
			default:
				break;
		};
	};
};

void update(double _dt)
{
	playerEntity->components->AnimationComponent->update(*playerEntity, _dt);
};


void render()
{
	//Sets a background color for the scene
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	//clears previous frame.
	SDL_RenderClear(renderer);
	
	levelEntity->components->GraphicsComponent->render(*levelEntity, renderer);
	
	playerEntity->components->GraphicsComponent->render(*playerEntity, renderer);
	
	//Renders current frame.
	SDL_RenderPresent(renderer);
}

void mainLoop()
{
	double newTime = SDL_GetTicks(); //in miliseconds
	double frameTime = newTime - currentTime; //Essentially stores how long the previous frame ran for in miliseconds
	
	//limits frame time to 100th of a second
	if (frameTime > 250) 
	{
		std::cout << "UPPER BOUND HIT, LAG ENCOUNTERED" << std::endl;
		frameTime = 250; //Upper bound on the time between processing this loop. If physics simulation is slower than render calculation then the game could halt.
	};

	#if __EMSCRIPTEN__
		int canvasWidth = canvas_get_width();
		std::cout << "The canvas width was: " << canvasWidth << std::endl;
	#endif


	currentTime = newTime; 

	accumulator += frameTime; 

	while ( accumulator >= dt)
	{
		update(dt); //consumes dt 
		accumulator -= dt;
	};
	
	render(); //Produces dt (takes time to calculate)

	//Event Polling
	while (SDL_PollEvent(event))
	{
		input();
	};
};

int main(int, char**)
{
	init();

	//When creating a native app (.exe on windows or sh on OSX/Linux this will directly call mainLoop. when running in browser emscripten deals with calls to the main method)
	#if __EMSCRIPTEN__
		emscripten_set_main_loop(mainLoop, -1, 1);
	#else
		while (quit != true)
		{
			mainLoop();
		}
	#endif

	SDL_DestroyRenderer( renderer );
	SDL_DestroyWindow( window );
	renderer = NULL;
	window = NULL;
	IMG_Quit();
	SDL_Quit();

	return 0;
};