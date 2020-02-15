#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <memory>

#include "Visual.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void setModules();

		void start();

	private:
		//SDL
		void SDLInit();
		void RendererInit();
		
		SDL_Window* win;
		SDL_Renderer* ren;
		//
		
		unique_ptr<Visual> visual;

};

#endif
