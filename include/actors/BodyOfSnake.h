#ifndef BODY_OF_SNAKE_H
#define BODY_OF_SNAKE_H

#include "Actor.h"
#include "../Geometry.h"
#include <memory>

class BodyOfSnake:public Actor
{
	public:
		BodyOfSnake(const Rectangle& rect, SDL_Texture* tex, const shared_ptr<Actor>& target);
		virtual ~BodyOfSnake();

		void setNewWaifu(const shared_ptr<Actor>& target);

		virtual void tick();

		virtual shared_ptr<Actor> getClone();
	
	private:
		shared_ptr<Actor> waifu;

		void stalk();
		
	public:
		virtual string getActorType()
		{
			return "BodyOfSnake";
		}


};

#endif
