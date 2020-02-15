#ifndef VISUAL_H
#define VISUAL_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>

#include "actors/VisualElement.h"

class Visual
{
	public:
		Visual();
		~Visual();

		void setRenderer(SDL_Renderer* r);

		void draw();

	private:
		SDL_Renderer* ren;

		
};

#endif
