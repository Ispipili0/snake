#include "../../include/actors/PhysicsElement.h"


PhysicsElement::PhysicsElement(const Rectangle& rect):
	rect(rect),
	speed(0.0f, 0.0f)
{
	radius = rect.size.x/2;
}

PhysicsElement::~PhysicsElement()
{}

void PhysicsElement::tick()
{
	move(speed);
	
}

float PhysicsElement::getRadius()
{
	return radius;
}

Vec PhysicsElement::getCenter()
{
	return Vec(rect.pos + rect.size/Vec(2.0f, 2.0f));
}

void PhysicsElement::changeSpeed(const Vec& vec)
{
	speed += vec;
}

void PhysicsElement::setSpeed(const Vec& vec)
{
	speed = vec;
}

void PhysicsElement::move(const Vec& vec)
{
	rect.move(vec);
	
}

int PhysicsElement::touchBy(const PhysicsObjects& objects)
{
	return 0;
}

