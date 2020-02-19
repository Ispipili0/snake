#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>
#include <memory>
#include <string>

#include "Scene.h"

using namespace std;

class Game
{
	public:
		Game();
		~Game();

		void start();

	private:
		//SDL
		void SDLInit();
		void RendererInit();
		
		SDL_Window* win;
		SDL_Renderer* ren;

		//
		
		Scene* scene;



};

#endif
