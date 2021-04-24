#include "Menu.h"
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
void full_rect_modell(SDL_Renderer* ren, int x, int y, int lenx, int leny, int a) {
	if (a == 3) SDL_SetRenderDrawColor(ren, 192, 192, 192, 200);
	if (a == 2) SDL_SetRenderDrawColor(ren, 0, 200, 0, 200);
	if (a == 1) SDL_SetRenderDrawColor(ren, 128, 0, 0, 100);
	if (a == 0) SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
	for (int i = y; i < y + leny; i++) {
		dr_lineXX(ren, x, i, lenx);
	}
}
void P(SDL_Renderer* ren, int x, int y) {
	int a = 1;
	for (int i = y; i < y + 60 ; i++) {
		full_rect_modell(ren, x, i, 6, 6, 0);
	}
	for (int i = x; i < x + 30; i++) {
		full_rect_modell(ren, i, y, 4, 4, 0);
	}
	for (int i = x + 30; i > x ; i--) {
		full_rect_modell(ren, i, y + 30, 4, 4, 0);
	}
	for (int i = y; i < y + 30; i++) {
		full_rect_modell(ren, x + 30, i, 4, 4, 0);
	}
}
void L(SDL_Renderer* ren, int x, int y) {
	for (int i = y; i < y + 60; i++)
		full_rect_modell(ren, x, i, 6, 6, 0);
	for (int i = x; i < x + 30; i++)
		full_rect_modell(ren, i, y + 62, 4, 4, 0);
}
void A(SDL_Renderer* ren, int x, int y) {
	for (int i = y; i < y + 60; i += 2) {
		full_rect_modell(ren, x, i, 5, 5, 0);
		x--;
	}
	x += 30;
	for (int i = y; i < y + 60; i += 2) {
		full_rect_modell(ren, x, i, 5, 5, 0);
		x++;
	}
	x -= 15;
	for (int i = x; i > x - 30; i--) {
		full_rect_modell(ren, i, y + 30, 5, 5, 0);
	}
	
}
void Y(SDL_Renderer* ren, int x, int y) {
	for (int i = y; i < y + 26; i += 2) {
		full_rect_modell(ren, x, i, 5, 5, 0);
		x-=2;
	}
	for (int i = y;  i < y + 26; i += 2) {
		full_rect_modell(ren, x - 26, i, 5, 5, 0);
		x+=2;
	}
	x -= 26;
	for (int i = y + 26; i < y + 60; i++) {
		full_rect_modell(ren, x, i, 5, 5, 0);
	}
}
void question(SDL_Renderer* ren, int x, int y) {
	full_rect_modell(ren, x, y, 9, 14, 0);
	full_rect_modell(ren, x + 4, y - 4, 23, 4, 0);
	full_rect_modell(ren, x + 23, y, 9, 19, 0);
	full_rect_modell(ren, x + 18, y + 14, 5, 5, 0);
	full_rect_modell(ren, x + 14, y + 19, 9, 9, 0);
	full_rect_modell(ren, x + 14, y + 34, 9, 9, 0);
}
int draw(SDL_Window* win, SDL_Renderer* ren) {
	//Highlite
	full_rect_modell(ren, 390, 190, 260, 90, 3);
	full_rect_modell(ren, 390, 190, 60, 90, 1);
	full_rect_modell(ren, 500, 280, 50, 50, 2);
	//PLAY
	P(ren, 400, 200);
	L(ren, 460, 200);
	A(ren, 550, 200);
	Y(ren, 640, 200);
	//PLAY
	//RULES
	question(ren, 508, 285);
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
