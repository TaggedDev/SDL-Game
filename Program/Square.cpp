#include "Menu.h"
#include <SDL.h>
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