#include "Load_texture.h"
#include<SDL.h>
#include<SDL_image.h>

SDL_Texture * Load_texture::load_texture(SDL_Renderer *renderer, const char *filename) {
	image = IMG_Load(filename);
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	return texture;
}