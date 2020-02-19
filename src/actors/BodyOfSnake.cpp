#include "../../include/actors/BodyOfSnake.h"

BodyOfSnake::BodyOfSnake(const Rectangle& rect, SDL_Texture* tex, const shared_ptr<Actor>& target):Actor(rect, tex),
	waifu(target)
{
	setSpeed(Vec(1.0f, 1.0f));
}

BodyOfSnake::~BodyOfSnake()
{}

void BodyOfSnake::tick()
{
	stalk();

	Actor::tick();
}

void BodyOfSnake::setNewWaifu(const shared_ptr<Actor>& target)
{
	waifu = target;
}

shared_ptr<Actor> BodyOfSnake::getClone()
{
	shared_ptr<BodyOfSnake> newEl(shared_ptr<BodyOfSnake>(new BodyOfSnake(*this)));

	newEl->setNewWaifu(shared_ptr<Actor>(this));

	return newEl;
}

void BodyOfSnake::stalk()
{
	Vec normal = waifu->getCenter() - getCenter();

	Vec normalPos = normal;

	if(normalPos.x < 0)normalPos.x = -normalPos.x;
	if(normalPos.y < 0)normalPos.y = -normalPos.y;

	//normal /= Vec(normalPos.x+normalPos.y, normalPos.x+normalPos.y);
	normal /= Vec(100.0f, 100.0f);

	setSpeed(normal);
}
