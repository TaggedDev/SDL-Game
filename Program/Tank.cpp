#include "Tank.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

void applySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
	SDL_Rect pos;
	pos.x = 10;
	pos.y = 10;
	pos.w = 60;
	pos.h = 60;
	SDL_RenderCopy(ren, tex, NULL, &pos);
}

void Tank::draw(SDL_Renderer* ren)
{
	SDL_Surface* surface = SDL_LoadBMP("bluetank.bmp");
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
