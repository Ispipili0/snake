#include "../include/game.h"

Game::Game()
{
	SDLInit();
	RendererInit();
}

Game::~Game()
{}

void Game::start()
{
	SDL_Event event;

	while(true)
	{
		SDL_PollEvent(&event);

		if(event.type == SDL_QUIT)
		{
			break;
		}
	}
}

void Game::SDLInit()
{
	SDL_DisplayMode displayMode;
	
	if(SDL_Init(SDL_INIT_EVERYTHING)!=0)
	{
		//log later TODO
	}

	int request = SDL_GetDesktopDisplayMode(0, &displayMode);

	win = SDL_CreateWindow("My own snake", 0, 0, displayMode.w, displayMode.h, SDL_WINDOW_SHOWN);

	if(win == nullptr)
	{
		//log this shit
	}


}

void Game::RendererInit()
{
	ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED|SDL_RENDERER_PRESENTVSYNC);

	if(ren == nullptr)
	{
		//log this shit again
	}
}



