#include "Road_cross.h"
#include<SDL.h>
#include<SDL_image.h>
#include<time.h>
#include "Load_texture.h"
#include "cap_fps.h"
#include "vehicle.h"
#include<iostream>

Road_cross::Road_cross(SDL_Renderer *renderer) {

	srand(time(NULL));
	this->renderer = renderer;
	cat_x = 0;
	run = false;
	cat_frame = 0;

	bgrect.x = bgrect.y = 0;
	bgrect.w = 1280;
	bgrect.h = 720;

	cat_rect.x = 0;
	cat_rect.y = 360;

	Load_texture loadPhoto;

	cat_sitting = loadPhoto.load_texture(this->renderer, "bilai.png");
	SDL_QueryTexture(cat_sitting, nullptr, nullptr, &cat_rect.w, &cat_rect.h);
	background = loadPhoto.load_texture(this->renderer, "Level 1 Roads.png");

	cat_run[0] = loadPhoto.load_texture(this->renderer, "catrun1.png");
	cat_run[1] = loadPhoto.load_texture(this->renderer, "catrun2.png");
	cat_run[2] = loadPhoto.load_texture(this->renderer, "catrun3.png");
	cat_run[3] = loadPhoto.load_texture(this->renderer, "catrun4.png");
	cat_run[4] = loadPhoto.load_texture(this->renderer, "catrun5.png");
	cat_run[5] = loadPhoto.load_texture(this->renderer, "catrun6.png");
	cat_run[6] = loadPhoto.load_texture(this->renderer, "catrun7.png");
	cat_run[7] = loadPhoto.load_texture(this->renderer, "catrun8.png");
	cat_run[8] = loadPhoto.load_texture(this->renderer, "catrun9.png");
	cat_run[9] = loadPhoto.load_texture(this->renderer, "catrun10.png");


	car[0] = loadPhoto.load_texture(this->renderer, "car1.png");
	car[1] = loadPhoto.load_texture(this->renderer, "car2.png");
	car[2] = loadPhoto.load_texture(this->renderer, "car3.png");
	car[3] = loadPhoto.load_texture(this->renderer, "car4.png");
	car[4] = loadPhoto.load_texture(this->renderer, "car5.png");
	car[5] = loadPhoto.load_texture(this->renderer, "car6.png");
	car[6] = loadPhoto.load_texture(this->renderer, "car7.png");

	speed[0] = 0.38;
	speed[1] = 0.45;
	speed[2] = 0.50;
	speed[3] = 0.62;
	speed[4] = 0.73;
	speed[5] = 0.88;

	first_car_x = 75;
	for (int i = 0; i < 9; i++) {
		car_ob[i] = new vehicle(car[rand() % 7],speed[rand() % 6], i % 2, first_car_x + i * 105);
	}

}

void Road_cross::draw() {

	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, nullptr, &bgrect);

	if (!run) SDL_RenderCopyEx(renderer, cat_sitting, nullptr, &cat_rect, 0, nullptr, SDL_FLIP_NONE);
	else {
		SDL_RenderCopyEx(renderer, cat_run[cat_frame], nullptr, &cat_rect, 0, nullptr, SDL_FLIP_NONE);
		cat_frame++;
		if (cat_frame >= 10) cat_frame = 0;
	}
	for (int i = 0; i < 9; i++) {
		car_ob[i]->draw(renderer);
	}
	SDL_RenderPresent(renderer);

}

void Road_cross::update() {

	if (keymove[SDL_SCANCODE_RIGHT]) {
		cat_x += 0.38;
		run = true;
	}
	else if (keymove[SDL_SCANCODE_LEFT]) {
		cat_x -= 0.38;
		run = true;
	}
	else run = false;

	for (int i = 0; i < 9; i++) {
		car_ob[i]->move();
	}
	
}

int Road_cross::exec() {

	//game loop
	SDL_Event event;
	auto prev_time = SDL_GetTicks();
	for (bool running = true; running;) {

		cat_rect.x = cat_x;
		for (int i = 0; i < 9; i++) {
			if (car_ob[i]->get_dir() && car_ob[i]->get_car_y() < -250) {
				car_ob[i] = new vehicle(car[rand() % 7],speed[rand() % 6], i % 2, first_car_x + i * 105);
			}
			else if (!car_ob[i]->get_dir() && car_ob[i]->get_car_y() > 1000) {
				car_ob[i] = new vehicle(car[rand() % 7], speed[rand() % 6], i % 2, first_car_x + i * 105);
			}
			else car_ob[i]->update();

			if (car_ob[i]->collision(&cat_rect)) {
				//SDL_Delay(5000);
			}
		}


		if (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
				break;
			}
		}

		keymove = SDL_GetKeyboardState(nullptr);
		auto cur_time = SDL_GetTicks();
		for (auto time = prev_time; time < cur_time; time++) {
			update();
		}

		prev_time = cur_time;

		draw();

		cap_fps fps;
		fps.cap_to(60, cur_time);

	}

	return 0;

}

