#include "../../include/actors/Apple.h"

Apple::Apple(const Rectangle& rect, SDL_Texture* tex):Actor(rect, tex)
{}

Apple::~Apple()
{}

string Apple::getActorType()
{
	return "Apple";
}
