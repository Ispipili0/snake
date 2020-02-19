#include "../../include/actors/VisualElement.h"


VisualElement::VisualElement(SDL_Texture* tex, const Rectangle& rect):tex(tex),
	PhysicsElement(rect)
{}

VisualElement::~VisualElement()
{
	SDL_DestroyTexture(tex);
}

void VisualElement::draw(SDL_Renderer* ren)
{
	SDL_Rect r = rect.getSDLRect();
	SDL_RenderCopy(ren, tex, NULL, &r);
}
