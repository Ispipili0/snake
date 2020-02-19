#include "../../include/actors/Actor.h"

Actor::Actor(const Rectangle& rect, SDL_Texture* tex):VisualElement(tex, rect)
{}

Actor::~Actor()
{}

shared_ptr<Actor> Actor::getClone()
{}

void Actor::tick()
{
	PhysicsElement::tick();
}
