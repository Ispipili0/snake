#ifndef ACTOR_H
#define ACTOR_H

#include <SDL2/SDL.h>

#include <memory>

#include "VisualElement.h"
#include "PhysicsElement.h"
#include "../Geometry.h"

class Actor:public VisualElement
{
	public:
		Actor(const Rectangle& rect, SDL_Texture* tex);
		virtual ~Actor();

		virtual shared_ptr<Actor> getClone();

		virtual void tick();

	private:
		

	public:
		virtual string getActorType()
		{
			return "Actor";
		}

		
	
};

#endif
