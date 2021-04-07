#include "Tank.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void applySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
	SDL_Rect pos;
	int w, h;
	w = 32;
	h = 32;
	pos.x = x;
	pos.y = y;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);
	//SDL_QueryTexture(tex, NULL, NULL, &w, &h);
	SDL_RenderCopy(ren, tex, NULL, &pos);
}

void Tank::draw(SDL_Renderer* ren)
{
	SDL_Surface* surface = SDL_LoadBMP("D:\\Code\\C++\\sdl_game\\SDL-Game\\Program\\x64\\Debug\\flower.bmp");
	if (surface == nullptr) {
		std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
		return;
	}

	SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
	SDL_FreeSurface(surface);

	if (tex == nullptr) {
		std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
		return;
	}

	applySurface(10, 10, tex, ren);
	SDL_RenderPresent(ren);
}
