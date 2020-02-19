#include "../../include/actors/HeadOfSnake.h"

HeadOfSnake::HeadOfSnake(const Rectangle& rect, SDL_Texture* tex):Actor(rect, tex)
{
	setSpeed(Vec(1.0f, 1.0f));
}

HeadOfSnake::~HeadOfSnake()
{
}

void HeadOfSnake::addFirstElement(const shared_ptr<Actor>& firstElement)
{
	if(bodyElements.empty())
	{
		bodyElements.push_back(firstElement);	
	}
}

void HeadOfSnake::tick()
{
	Actor::tick();
}

void HeadOfSnake::moveIn(const Vec& sideOfMove)
{
	setSpeed(sideOfMove);
}

shared_ptr<Actor> HeadOfSnake::getElementFromTurn()
{
	if(!turnToCreate.empty()){
		bodyElements.push_back(turnToCreate.back());
		turnToCreate.pop_back();
		return bodyElements.back();
	}

	return NULL;
}

bool HeadOfSnake::checkElementsInTurn()
{
	if(!turnToCreate.empty())return true;

	return false;
}

int HeadOfSnake::touchBy(const PhysicsObjects& objects)
{
	for(auto i = objects.begin(); i != objects.end(); i++)
	{
		if((*i)->getActorType() == "Apple")
		{
			return 1;
		}
	}
	return 0;
}

void HeadOfSnake::createNewElement()
{
	turnToCreate.push_back(bodyElements.back()->getClone());
}
