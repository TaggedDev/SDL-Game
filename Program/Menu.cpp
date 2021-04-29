#include "Menu.h"
#include <SDL_mixer.h>
#include "Player.h"
#include <iostream>
#include <SDL.h>
using namespace std;
bool isRules = false;

int draw(Menu menu, SDL_Window* win, SDL_Renderer* ren) {
	menu.full_rect_modell(ren, 390, 190, 260, 90, 3);
	menu.full_rect_modell(ren, 390, 190, 60, 90, 1);
	menu.full_rect_modell(ren, 500, 280, 50, 50, 2);
	menu.P(ren, 400, 200);
	menu.L(ren, 460, 200);
	menu.A(ren, 550, 200);
	menu.Y(ren, 640, 200);
	menu.question(ren, 508, 285);
	Player player1 = Player(50, 50, "Red", ren);
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
		if (e.type == SDL_MOUSEBUTTONDOWN) {
			if (e.button.x > 500 && e.button.x < 550 && e.button.y > 280 && e.button.y < 330 && !isRules) {
				cout << "Vasha zadacha - popast v tank protivnika odyn raz. Upravlenie:\nSiniy tank: WASD + Space\nKrasny tank: STRELKI + RShift";
				isRules = true;
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
