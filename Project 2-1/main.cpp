#include<iostream>
#include<SDL.h>
#include "SDL_image.h"
#include<time.h>
#include "initialization.h"
using namespace std;

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
const int HEIGHT = 720;
const int WIDTH = 1280;

int main(int argc, char *argv[]) {

	initialization init;
	init.exec();
	return EXIT_SUCCESS;

}