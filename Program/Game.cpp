//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Field.h"

using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Event e;
	bool done = false, quit = false;
	while (!quit) {

		Field field;
		// Draw the 
		field.Render();

		if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
			std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		SDL_Window* win = SDL_CreateWindow("Hello World!", 100, 100, 640, 480, SDL_WINDOW_SHOWN);
		SDL_Renderer* ren = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		if (ren == nullptr) {
			std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
			return 1;
		}

		while (!done) {
			while (SDL_PollEvent(&e))
			{
				// ���� ������������ ��������� ������� ����
				if (e.type == SDL_QUIT)
				{
					SDL_DestroyRenderer(ren);
					SDL_DestroyWindow(win);
					SDL_Quit();
					quit = true;
				}
				// ���� ������������ ����� ������� �� ����������
				if (e.type == SDL_KEYDOWN)
				{
					printf("Oh my");
					quit = true;
				}
				// ���� ������������ ������� �����
				if (e.type == SDL_MOUSEBUTTONDOWN)
				{

					quit = true;
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