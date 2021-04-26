#pragma once
#include <SDL.h>
#include <stdio.h>
class Menu 
{
public:
	void full_rect_modell(SDL_Renderer* ren, int x, int y, int lenx, int leny, int a);
	int start(Menu menu, bool done);
	//void retra(bool done, SDL_Renderer* ren, SDL_Window* win);
public:
	void P(SDL_Renderer* ren, int x, int y);
	void L(SDL_Renderer* ren, int x, int y);
	void A(SDL_Renderer* ren, int x, int y);
	void Y(SDL_Renderer* ren, int x, int y);
	void question(SDL_Renderer* ren, int x, int y);
};
