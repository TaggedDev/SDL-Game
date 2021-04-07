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
	//Tank position
	int x = 300;
	int y = 300;
	//
	
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
			while (SDL_PollEvent(&e))
			{
				// Если пользователь попытался закрыть окно
				if (e.type == SDL_QUIT)
				{
					SDL_DestroyRenderer(ren);
					SDL_DestroyWindow(win);
					SDL_Quit();
					quit = true;
				}
				// Если пользователь нажал клавишу на клавиатуре
				/*if (e.type == SDL_KEYDOWN)
				{
					printf("Oh my");
					quit = true;
				}
				*/
				// Если пользователь щёлкнул мышью
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{
					quit = true;
				}
				// Tank movement
				if (e.type == SDL_KEYDOWN) {

					switch (e.key.keysym.sym) {
					case SDLK_d:
						player.move_right(ren, x, y);
						x += 5;
						continue;
					case SDLK_s:
						player.move_down(ren, x, y);
						y += 5;
						continue;
					case SDLK_w:
						player.move_up(ren, x, y);
						y -= 5;
						continue;
					case SDLK_a:
						player.move_left(ren, x, y);
						x -= 5;
						continue;
					}
					
				}
			}
		}
	}
	
	//SDL_Surface* screen = SDL_SetVideoMode(550, 420, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
	/*if (SDL_Init(SDL_INIT_EVENTS) < 0) {
		printf("Unable to run: %s", SDL_GetError());
		return 1;
	}*/

	SDL_Window* window;
	SDL_Renderer* render;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &render);

	

	
	
	return 0;
}