#include "Menu.h"
#include <iostream>
#include <SDL.h>
using namespace std;
void dr_lineXX(SDL_Renderer* ren, int x, int y, int len) {
	for (int i = 0; i < len; i++) {
		SDL_RenderDrawPoint(ren, x + i, y);
	}
}
void dr_lineYY(SDL_Renderer* ren, int x, int y, int len) {
	SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	for (int i = 0; i < len; i++) {
		SDL_RenderDrawPoint(ren, x, y + i);
	}
}
void full_rect_modell(SDL_Renderer* ren, int x, int y, int lenx, int leny, int a) {
	if (a == 1) SDL_SetRenderDrawColor(ren, 255, 0, 0, 255);
	if (a == 0) SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	for (int i = y; i < y + leny; i++) {
		dr_lineXX(ren, x, i, lenx);
	}
}
int draw(SDL_Window* win, SDL_Renderer* ren) {
	//Das ist P, runter, Die Farbe ist rot, das sieht doch besser aus, wissen sie, na ja, die erste Buchstabe muss bisschen überzeugender sein
	int a = 1;
	for (int i = 10; i < 60; i++) {
		full_rect_modell(ren, 10, i, 2, 2, 1);
		full_rect_modell(ren, 40, i, 2, 2, 0);
	}
	for (int i = 10; i < 30; i++) {
		full_rect_modell(ren, i ,10, 2, 2, 1);
		full_rect_modell(ren, 30, i, 2, 2, 1);
	}
	for (int i = 30; i > 10; i--) {
		full_rect_modell(ren, i, 30, 2, 2, 1);
	}
	for (int i = 40; i < 65; i++) {
		full_rect_modell(ren, i, 60, 2, 2, 0);
	}
	//P Ende
	return 0;
}
int retra(bool done, SDL_Renderer* ren, SDL_Window* win) {
	SDL_Event e;
	while (done == 0) {
		SDL_PollEvent(&e);
		if (e.type == SDL_KEYDOWN) {
			if (e.key.keysym.sym == SDLK_ESCAPE) {
				SDL_DestroyRenderer(ren);
				SDL_DestroyWindow(win);
				SDL_Quit();
				done = 1;
			}
			if (e.key.keysym.sym == SDLK_p) {
				SDL_DestroyRenderer(ren);
				SDL_DestroyWindow(win);
				done = 1;
			}
		}
	}
	return done;
}
int Menu::start(bool done) {
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_CreateWindowAndRenderer(1088, 512, 0, &win, &ren);
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
	draw(win, ren);
	SDL_RenderPresent(ren);
	retra(done,ren, win);
	return done;
}
