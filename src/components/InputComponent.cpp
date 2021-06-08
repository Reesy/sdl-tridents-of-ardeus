
#include <components/InputComponent.hpp>
#include <iostream>

void InputComponent::update(SDL_Event* _event)
{

    if (_event->type == SDL_KEYDOWN)
	{
		switch (_event->key.keysym.sym)
		{
			case SDLK_a:
                std::cout << "Update component called" << std::endl;
				break;
			case SDLK_d:
				break;
			default:
				break;
		};
	};

    return;
}