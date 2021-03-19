#include "cap_fps.h"
#include<SDL.h>


void cap_fps::cap_to(int fps, Uint32 starting_tick)
{
	if (1000.0f / fps > SDL_GetTicks() - starting_tick) {
		SDL_Delay(1000.0f / fps - (SDL_GetTicks() - starting_tick));
	}
}
