#ifndef VISUAL_ELEMENT_H
#define VISUAL_ELEMENT_H

#include <SDL2/SDL.h>
#include <memory>

using namespace std;

class VisualElement
{
	public:
		VisualElement(SDL_Texture* tex, const shared_ptr<SDL_Rect>& rect);
		virtual ~VisualElement();

		void draw(SDL_Renderer* ren);

	private:
		SDL_Texture* tex;
		shared_ptr<SDL_Rect> rect;


};

#endif
