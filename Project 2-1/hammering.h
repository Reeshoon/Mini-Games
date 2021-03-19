#pragma once
#include<SDL.h>
#include "pumpkin.h"
class hammering
{
private:
	SDL_Texture *hammer_still, *cat_move[4], *background, *cat_cur, *hammer[25];
	SDL_Rect ham_rect, bgrect;
	SDL_Renderer *renderer;
    Uint32 key;
	float hammer_x;
	bool move;
	int flag;
	int ham_frame;
	pumpkin *cat_ob[6];
	//vehicle *car_ob[9];
	int first_cat_x,first_cat_y;
	//float speed[6];
public:
	hammering(SDL_Renderer *renderer);
	void draw();
	int exec();
	void update(SDL_MouseButtonEvent&,int flag);
	~hammering();
};

