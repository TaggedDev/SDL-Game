#include "Menu.h"
#include <SDL_mixer.h>
#include "Player.h"
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
void Menu::full_rect_modell(SDL_Renderer* ren, int x, int y, int lenx, int leny, int a) {
	if (a == 3) SDL_SetRenderDrawColor(ren, 192, 192, 192, 200);
	if (a == 2) SDL_SetRenderDrawColor(ren, 0, 200, 0, 200);
	if (a == 1) SDL_SetRenderDrawColor(ren, 128, 0, 0, 100);
	if (a == 0) SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	for (int i = y; i < y + leny; i++) {
		dr_lineXX(ren, x, i, lenx);
	}
}
int draw(Menu menu, SDL_Window* win, SDL_Renderer* ren) {
	//Highlite
	menu.full_rect_modell(ren, 390, 190, 260, 90, 3);
	menu.full_rect_modell(ren, 390, 190, 60, 90, 1);
	menu.full_rect_modell(ren, 500, 280, 50, 50, 2);
	//PLAY
	menu.P(ren, 400, 200);
	menu.L(ren, 460, 200);
	menu.A(ren, 550, 200);
	menu.Y(ren, 640, 200);
	//PLAY
	//RULES
	menu.question(ren, 508, 285);
	//RULES
	Player player1 = Player(50, 50, "Red", ren);
	//player1.draw(ren, 100, 100);

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
			if (e.key.keysym.sym == SDLK_q) {
				cout << "Rules place is here";
			}
			if (e.key.keysym.sym == SDLK_p) {
				SDL_DestroyRenderer(ren);
				SDL_DestroyWindow(win);
				done = 1;
			}
		}
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.x > 500 && e.button.x < 550 && e.button.y > 280 && e.button.y < 330) {
				cout << "Rules place is here/////////////////////////////";
			}
		}
	}
	return done;
}
int Menu::start(Menu menu, bool done) {
	SDL_Window* win;
	SDL_Renderer* ren;
	SDL_CreateWindowAndRenderer(1088, 512, 0, &win, &ren);
	SDL_SetRenderDrawColor(ren, 255, 0, 0, 0);
	draw(menu, win, ren);
	SDL_RenderPresent(ren);
	retra(done,ren, win);
	return done;
}
