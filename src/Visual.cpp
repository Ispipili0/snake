#include "../include/Visual.h"

Visual::Visual()
{}

Visual::~Visual()
{}

void Visual::setRenderer(SDL_Renderer* r)
{
	ren = r;
}

void Visual::draw()
{

	shared_ptr<SDL_Rect> rect(new SDL_Rect());
	
	rect->x = 0.0f;
	rect->y = 0.0f;
	rect->w = 1000.0f;
	rect->h = 1000.0f;


	VisualElement el(IMG_LoadTexture(ren, "distr/textures/1.jpg"), rect);

	SDL_RenderClear(ren);

	el.draw(ren);

	SDL_RenderPresent(ren);
}
