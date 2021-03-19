#pragma once
#include<SDL.h>
#include<SDL_image.h>

class initialization
{
private:
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	const int HEIGHT = 720;
	const int WIDTH = 1280;
public:
	void exec();
	initialization();
	~initialization();
};

