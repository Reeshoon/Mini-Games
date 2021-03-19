#include "vehicle.h"
#include<iostream>

vehicle::vehicle() {
	this->dir = 0;
	this->car = NULL;
	car_y = 0;
	car_rect.y = 0;
	car_rect.x = 0;
}

vehicle::vehicle(SDL_Texture *texture, float speed, bool dir, int car_x) {
	this->dir = dir;
	this->car = texture;
	this->speed = speed;
	SDL_QueryTexture(car, nullptr, nullptr, &car_rect.w, &car_rect.h);
	if (dir) car_y = 1000;
	else car_y = -300;
	car_rect.y = car_y;
	car_rect.x = car_x;
}

void vehicle::move() {
	if (!dir) car_y += speed;
	else car_y -= speed;
}

void vehicle::update() {
	car_rect.y = car_y;
}

void vehicle::draw(SDL_Renderer *renderer) {
	if (!dir) SDL_RenderCopyEx(renderer, car, nullptr, &car_rect, 0, NULL, SDL_FLIP_VERTICAL);
	else SDL_RenderCopyEx(renderer, car, nullptr, &car_rect, 0, NULL, SDL_FLIP_NONE);
}

float vehicle::get_car_y() {
	return car_y;
}

bool vehicle::get_dir() {
	return dir;
}

bool vehicle::collision(SDL_Rect *rect) {
	return SDL_HasIntersection(&car_rect, rect);
}