#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

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
		
		void startGameWhile();


};

#endif
