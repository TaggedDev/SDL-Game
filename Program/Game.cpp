//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Field.h"
#include "Player.h"

using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 600;

int main(int argc, char* args[])
{
	
	SDL_Event e;
	bool done = false, quit = false;
	while (!quit) {
		
		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &win, &ren);
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		//

		if (ren == nullptr) {
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		Field field;
		field.Render(ren);
		Player player;

		while (!done) {
			const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);

			SDL_PollEvent(&e);

			if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP)
			{
				if (keyboard_state_array[SDL_SCANCODE_UP])
				{
					player.move_up(ren);
				}
				if (keyboard_state_array[SDL_SCANCODE_DOWN]) {
					player.move_down(ren);
				}
				if (keyboard_state_array[SDL_SCANCODE_LEFT]) {
					player.move_left(ren);
				}
				if (keyboard_state_array[SDL_SCANCODE_RIGHT]) {
					player.move_right(ren);
				}
			}
		}
	}
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &render);
	return 0;
}