#ifndef HEAD_OF_SNAKE_H
#define HEAD_OF_SNAKE_H

#include "BodyOfSnake.h"
#include "Actor.h"
#include "PhysicsElement.h"
#include "../Geometry.h"

#include <iostream>

#include <vector>

typedef vector<shared_ptr<Actor> > Objects;

class HeadOfSnake:public Actor
{
	public:
		HeadOfSnake(const Rectangle& rect, SDL_Texture* tex);
		virtual ~HeadOfSnake();

		void addFirstElement(const shared_ptr<Actor>& firstElement);
		
		virtual void tick();

		void moveIn(const Vec& sideOfMove);

		shared_ptr<Actor> getElementFromTurn();

		bool checkElementsInTurn();

		virtual int touchBy(const PhysicsObjects& objects);

	private:

		Objects bodyElements;

		Objects turnToCreate;

	public:
		void createNewElement();

		virtual string getActorType()
		{
			return "HeadOfSnake";
		}

};

#endif
