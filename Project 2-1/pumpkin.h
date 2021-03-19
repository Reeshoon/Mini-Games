#pragma once
#include<SDL.h>
class pumpkin
{
private:
	SDL_Texture *cat_pumpkin;
	SDL_Rect cat_rect;

public:
	pumpkin(SDL_Texture *texture, int cat_x);
	void draw(SDL_Renderer *renderer);
	bool collision(SDL_Rect *rect);
	~pumpkin();
};

