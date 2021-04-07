#include "Tank.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;

//bool load() {
//	SDL_Surface* flower = NULL;
//	SDL_Surface* scr = NULL;
//	flower = SDL_LoadBMP("flower.png");
//	if (flower == NULL) {
//		cout << "Can't load " << SDL_GetError() << endl;
//		return false;
//	}
//	flower = SDL_ConvertSurface(flower, scr->format, NULL);
//	if (flower == NULL) {
//		cout << "Can't convert" << SDL_GetError() << endl;
//		return false;
//	}
//
//	return true;
//}

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

	SDL_RenderCopy(ren, tex, NULL, NULL);
	SDL_RenderPresent(ren);
}
