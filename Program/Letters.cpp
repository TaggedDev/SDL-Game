#include <SDL.h>
#include "Menu.h"

void Menu::P(SDL_Renderer* ren, int x, int y) {
	int a = 1;
	for (int i = y; i < y + 60; i++) {
		full_rect_modell(ren, x, i, 6, 6, 0);
	}
	for (int i = x; i < x + 30; i++) {
		full_rect_modell(ren, i, y, 4, 4, 0);
	}
	for (int i = x + 30; i > x; i--) {
		full_rect_modell(ren, i, y + 30, 4, 4, 0);
	}
	for (int i = y; i < y + 30; i++) {
		full_rect_modell(ren, x + 30, i, 4, 4, 0);
	}
}
void Menu::L(SDL_Renderer* ren, int x, int y) {
	for (int i = y; i < y + 60; i++)
		full_rect_modell(ren, x, i, 6, 6, 0);
	for (int i = x; i < x + 30; i++)
		full_rect_modell(ren, i, y + 62, 4, 4, 0);
}
void Menu::A(SDL_Renderer* ren, int x, int y) {
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
void Menu::Y(SDL_Renderer* ren, int x, int y) {
	for (int i = y; i < y + 26; i += 2) {
		full_rect_modell(ren, x, i, 5, 5, 0);
		x -= 2;
	}
	for (int i = y; i < y + 26; i += 2) {
		full_rect_modell(ren, x - 26, i, 5, 5, 0);
		x += 2;
	}
	x -= 26;
	for (int i = y + 26; i < y + 60; i++) {
		full_rect_modell(ren, x, i, 5, 5, 0);
	}
}
void Menu::question(SDL_Renderer* ren, int x, int y) {
	full_rect_modell(ren, x, y, 9, 14, 0);
	full_rect_modell(ren, x + 4, y - 4, 23, 4, 0);
	full_rect_modell(ren, x + 23, y, 9, 19, 0);
	full_rect_modell(ren, x + 18, y + 14, 5, 5, 0);
	full_rect_modell(ren, x + 14, y + 19, 9, 9, 0);
	full_rect_modell(ren, x + 14, y + 34, 9, 9, 0);
}