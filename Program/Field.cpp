#include "Field.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

void it_Line(SDL_Renderer* ren, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;

	int x = x1;
	int y = y1;

	if (dx == 0) {
		while (y < y2) {
			SDL_RenderDrawPoint(ren, x, y);
			y++;
		}
		return;
	}
	//cout << dx << " " << dy;
	float k = dy / dx;
	while (x <= x2) {
		SDL_RenderDrawPoint(ren, x, y);
		y += (int)k;
		x++;
	}
}

void it_Rectangle(SDL_Renderer* render, int x, int y, int length, int height) {
	it_Line(render, x, y, x + length, y);
	it_Line(render, x, y + height, x + length, y + height);
	it_Line(render, x, y, x, y + height);
	it_Line(render, x + length, y, x + length, y + height);
}


void a1pplySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = 60;
    pos.h = 60;
    SDL_RenderCopy(ren, tex, NULL, &pos);
}

void d1raw(SDL_Renderer* ren, int x, int y)
{
    SDL_Surface* surface = nullptr;
    surface = SDL_LoadBMP("src\\brick.bmp");

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

    a1pplySurface(x, y, tex, ren);
    SDL_RenderPresent(ren);
}


void Field::Render(SDL_Renderer* render)
{
	it_Rectangle(render, 0, 0, 1080, 500);
	d1raw(render, 10, 10);
	SDL_RenderPresent(render);
}
