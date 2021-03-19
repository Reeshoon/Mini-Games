#pragma once
#include<SDL.h>

class vehicle
{
private:
	SDL_Texture *car;
	SDL_Rect car_rect;
	float car_y, speed;
	bool dir;
public:
	vehicle();
	vehicle(SDL_Texture *texture,float speed, bool dir, int car_x);
	void move();
	void update();
	void draw(SDL_Renderer *renderer);
	float get_car_y();
	bool get_dir();
	bool collision(SDL_Rect *rect);
};

