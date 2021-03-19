#include "hammering.h"
#include<SDL.h>
#include<SDL_image.h>
#include<time.h>
#include "Load_texture.h"
#include "cap_fps.h"
#include<iostream>
#include "pumpkin.h"
using namespace std;

hammering::hammering(SDL_Renderer *renderer)
{
	srand(time(NULL));
	this->renderer = renderer;
	move = false;
	ham_frame =0;

	bgrect.x = bgrect.y = 0;
	bgrect.w = 1280;
	bgrect.h = 720;

	ham_rect.x =900;
	ham_rect.y =250;
	ham_rect.w = 10;
	ham_rect.h = 10;
	hammer_x = 1000;

	Load_texture loadPhoto;

	hammer_still = loadPhoto.load_texture(this->renderer, "hammerstill.png");
	SDL_QueryTexture(hammer_still, nullptr, nullptr, &ham_rect.w, &ham_rect.h);
	background = loadPhoto.load_texture(this->renderer, "Level 2 hammering.jpg");
	if (background == NULL)
	{
		cout << "error\n";
	};

	cat_move[0] = loadPhoto.load_texture(this->renderer, "catpumpkin1.png");
	cat_move[1] = loadPhoto.load_texture(this->renderer, "catpumpkin2.png");
	cat_move[2] = loadPhoto.load_texture(this->renderer, "catpumpkin3.png");
	cat_move[3] = loadPhoto.load_texture(this->renderer, "catpumpkin4.png");

	hammer[0] = loadPhoto.load_texture(this->renderer, "hammer1.png");
	hammer[1] = loadPhoto.load_texture(this->renderer, "hammer2.png");
	hammer[2] = loadPhoto.load_texture(this->renderer, "hammer3.png");
	hammer[3] = loadPhoto.load_texture(this->renderer, "hammer4.png");
	hammer[4] = loadPhoto.load_texture(this->renderer, "hammer5.png");
	hammer[5] = loadPhoto.load_texture(this->renderer, "hammer6.png");
	hammer[6] = loadPhoto.load_texture(this->renderer, "hammer7.png");
	hammer[7] = loadPhoto.load_texture(this->renderer, "hammer8.png");
	hammer[8] = loadPhoto.load_texture(this->renderer, "hammer9.png");
	hammer[9] = loadPhoto.load_texture(this->renderer, "hammer10.png");
	hammer[10] = loadPhoto.load_texture(this->renderer, "hammer11.png");
	hammer[11] = loadPhoto.load_texture(this->renderer, "hammer12.png");
	hammer[12] = loadPhoto.load_texture(this->renderer, "hammer13.png");
	hammer[13] = loadPhoto.load_texture(this->renderer, "hammer14.png");
	hammer[14] = loadPhoto.load_texture(this->renderer, "hammer15.png");
	hammer[15] = loadPhoto.load_texture(this->renderer, "hammer16.png");
	hammer[16] = loadPhoto.load_texture(this->renderer, "hammer17.png");
	hammer[17] = loadPhoto.load_texture(this->renderer, "hammer18.png");
	hammer[18] = loadPhoto.load_texture(this->renderer, "hammer19.png");
	hammer[19] = loadPhoto.load_texture(this->renderer, "hammer20.png");
	hammer[20] = loadPhoto.load_texture(this->renderer, "hammer21.png");
	hammer[21] = loadPhoto.load_texture(this->renderer, "hammer22.png");
	hammer[22] = loadPhoto.load_texture(this->renderer, "hammer23.png");
	hammer[23] = loadPhoto.load_texture(this->renderer, "hammer24.png");
	hammer[24] = loadPhoto.load_texture(this->renderer, "hammer25.png");
	for (int i = 0;i < 25;i++)
	{
		if (hammer[i] == NULL)
		{
			cout << "error\n";
		};
	}
	first_cat_x = 75;
	for (int i = 0; i < 6; i++) {
		cat_ob[i] = new pumpkin(cat_move[0], first_cat_x + i * 175);
	}
	
	
}

void hammering::draw() {

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, nullptr, &bgrect);

	if (!move)
	{
		SDL_RenderCopyEx(renderer, hammer_still, nullptr, &ham_rect, 0, nullptr, SDL_FLIP_NONE);
		ham_frame = 0;
	}
	else if(move)
	{
		SDL_RenderCopyEx(renderer, hammer[ham_frame], nullptr, &ham_rect, 0, nullptr, SDL_FLIP_NONE);
		//cout << ham_frame << endl;
		ham_frame++;
		//cout << move << endl;
		//cout << "Hi" << endl;
		if (ham_frame>=25)
		{
			//move = false;
			ham_frame = 0;
		}
	}
	
	
	move = false;
	for (int i = 0; i < 6; i++) {
		cat_ob[i]->draw(renderer);
	}		
	
	SDL_RenderPresent(renderer);

}

void hammering::update(SDL_MouseButtonEvent& event,int flag) {

	/*if (key== SDL_BUTTON_RIGHT) {
		hammer_x += 0.20;
		move = false;
	}
	else if (key==SDL_BUTTON_LEFT) {
		hammer_x -= 0.20;
		move = false;
	}*/
	/*if (b.button == SDL_MOUSEBUTTONDOWN)
	{
		move = true;
	}
	else
	{
		move = false;
	}*/
	if (event.type == SDL_MOUSEBUTTONDOWN) {
		move = true;
		//cout << "A";
	}
	else if (event.type == SDL_MOUSEBUTTONUP) {
		move = false;
		//cout << "B";
	}
	
	else if(flag==15)
	{
		move = false;
	}
	



}

int hammering::exec() {

	//game loop
	SDL_Event event;
	auto prev_time = SDL_GetTicks();
	int flag=1;
	for (bool running = true; running;) {
		ham_rect.x = hammer_x;
		int a;
		int flag2 = 0;
		a = rand() % 6;
		if (flag == 15) {
			for (int i = 0;i < 6;i++)
			{
				if (i == a)
				{
					cat_ob[i] = new pumpkin(cat_move[3], first_cat_x + i * 175);
				}
				else
				{
					cat_ob[i] = new pumpkin(cat_move[0], first_cat_x + i * 175);
				}
			}
			flag = 0;
		}


		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				bool running = false;
				break;
			}
			//SDL_GetMouseState(&ham_rect.x, &ham_rect.y);
		    /*if (event.type == SDL_MOUSEBUTTONDOWN) {
				move = true;
				cout << "A";
			}
			else if (event.type == SDL_MOUSEBUTTONUP) {
				move = true;
				cout << "B";
			}
			else 
			{
				move=false;
			}*/
		}

		key = SDL_GetMouseState(&ham_rect.x,&ham_rect.y);
		auto cur_time = SDL_GetTicks();
		for (auto time = prev_time; time < cur_time; time++) {
			
				update(event.button,flag);
			
			
			}
		flag++;
		prev_time = cur_time;
		
		draw();

		cap_fps fps;
		fps.cap_to(60, cur_time);

	}

	return 0;

}


hammering::~hammering()
{
}
