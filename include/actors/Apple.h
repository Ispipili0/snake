#ifndef APPLE_H
#define APPLE_H

#include "Actor.h"
#include "../Geometry.h"

class Apple:public Actor
{
	public:
		Apple(const Rectangle& rect, SDL_Texture* tex);
		~Apple();

	private:


	public:
		virtual string getActorType();

};

#endif
