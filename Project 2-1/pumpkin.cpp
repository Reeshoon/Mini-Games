#include "pumpkin.h"


void pumpkin::draw(SDL_Renderer *renderer) {
	 SDL_RenderCopyEx(renderer, cat_pumpkin, nullptr, &cat_rect, 0, NULL,SDL_FLIP_NONE);
	
}
bool pumpkin::collision(SDL_Rect *rect) {
	return SDL_HasIntersection(&cat_rect, rect);
}
pumpkin::pumpkin(SDL_Texture *texture, int cat_x)
{
	this->cat_pumpkin = texture;
	SDL_QueryTexture(cat_pumpkin, nullptr, nullptr, &cat_rect.w, &cat_rect.h);
	cat_rect.y = 550;
	cat_rect.x = cat_x;
}

pumpkin::~pumpkin()
{
}
