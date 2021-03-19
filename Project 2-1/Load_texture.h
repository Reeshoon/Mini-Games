#pragma once
#include<SDL.h>

class Load_texture
{
private:
	SDL_Surface *image;
public:
	SDL_Texture * load_texture(SDL_Renderer *renderer, const char *filename);
};
