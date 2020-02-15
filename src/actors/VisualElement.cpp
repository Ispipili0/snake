#include "../../include/actors/VisualElement.h"


VisualElement::VisualElement(SDL_Texture* tex, const shared_ptr<SDL_Rect>& rect):tex(tex),
	rect(rect)
{}

VisualElement::~VisualElement()
{
	SDL_DestroyTexture(tex);
}

void VisualElement::draw(SDL_Renderer* ren)
{
	SDL_RenderCopy(ren, tex, NULL, &(*rect));
}
