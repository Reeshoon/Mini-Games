#pragma once
#include<string>
#include<SDL.h>
using namespace std;
class Window
{
public:
	Window(string title, int width, int height);
	~Window();

	inline bool isClosed() const {
		return _closed;
	}

private:
	bool init();

private:
	string _title;
	int _width = 800;
	int _height = 600;
	bool _closed = false;
	SDL_Window *_window = nullptr;

};
