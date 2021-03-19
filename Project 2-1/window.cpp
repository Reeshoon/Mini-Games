#include "window.h"
#include<iostream>

Window::Window(string title, int width, int height) :
	_title(title), _width(width), _height(height)
{
	if (!init()) {
		_closed = true;
	}
}
Window::~Window() {
	SDL_DestroyWindow(_window);
	SDL_Quit();

}
bool Window::init() {
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		cout << "Failed";
		return 0;
	}
	_window = SDL_CreateWindow(
		_title.c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		_width, _height,
		0
	);
	if (_window == nullptr)
	{
		cout << "Failed";
		return 0;
	}
	return true;
}