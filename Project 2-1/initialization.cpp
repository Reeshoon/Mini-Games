#include "initialization.h"
#include<iostream>
#include<SDL.h>
#include<SDL_image.h>
#include<time.h>
#include "Road_cross.h"
#include "hammering.h"
using namespace std;

initialization::initialization()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize. Error: " << SDL_GetError() << endl;
	}

	IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG);

	window = SDL_CreateWindow("game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
	if (window == NULL) {
		cout << "Could not create window " << SDL_GetError() << endl;
		exit(1);
	}

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

	srand(time(NULL));
}


initialization::~initialization()
{
}

void initialization::exec() {
	//Road_cross lv1(renderer);
	hammering lv1(renderer);
	lv1.exec();
}