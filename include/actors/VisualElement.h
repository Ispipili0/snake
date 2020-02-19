#ifndef VISUAL_ELEMENT_H
#define VISUAL_ELEMENT_H

#include <SDL2/SDL.h>
#include <memory>
#include "../Geometry.h"
#include "PhysicsElement.h"

using namespace std;

class VisualElement: public PhysicsElement
{
	public:
		VisualElement(SDL_Texture* tex, const Rectangle& rect);
		virtual ~VisualElement();

		void draw(SDL_Renderer* ren);

	private:
		SDL_Texture* tex;

	public:
		virtual string getActorType()
		{
			return "VisualElement";
		}

};

#endif
