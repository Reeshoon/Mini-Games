#pragma once
#include<SDL.h>
#include "vehicle.h"

class Road_cross
{
private:
	SDL_Texture *cat_sitting, *cat_run[10], *background, *cat_cur, *car[7];
	SDL_Rect cat_rect, bgrect;
	SDL_Renderer *renderer;
	const Uint8 *keymove;
	float cat_x;
	bool run;
	int cat_frame;
	vehicle *car_ob[9];
	int first_car_x;
	float speed[6];
public:
	Road_cross(SDL_Renderer *renderer);
	void draw();
	int exec();
	void update();
};
