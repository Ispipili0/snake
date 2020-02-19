#ifndef PHYSICS_ELEMENT_H
#define PHYSICS_ELEMENT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include <memory>
#include <vector>

#include "../Geometry.h"

using namespace std;

class PhysicsElement;

typedef vector<shared_ptr<PhysicsElement> > PhysicsObjects;

class PhysicsElement
{
	public:

		PhysicsElement(const Rectangle& rect);
		virtual ~PhysicsElement();

		virtual void tick();

		float getRadius();
		Vec getCenter();


		Rectangle rect;

	protected:

		void changeSpeed(const Vec& vec);
		void setSpeed(const Vec& vec);

		void move(const Vec& vec);

	public:

		virtual int touchBy(const PhysicsObjects& objects);


		virtual string getActorType()
		{
			return "PhysicsElement";
		}
	
	private:
		
		Vec speed; 

		float radius;


};

#endif
