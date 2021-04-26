#include "Field.h"
#include "Player.h"
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

void line(SDL_Renderer* ren, int x1, int y1, int x2, int y2) {
	int dx = x2 - x1;
	int dy = y2 - y1;
	int x = x1;
	int y = y1;
	if (dx == 0) {
		while (y < y2) {
			SDL_RenderDrawPoint(ren, x, y);
			y++;
		}
		return; }
	float k = dy / dx;
	while (x <= x2) {
		SDL_RenderDrawPoint(ren, x, y);
		y += (int)k;
		x++; }
}

void rectangle(SDL_Renderer* render, int x, int y, int length, int height) {
	line(render, x, y, x + length, y);
	line(render, x, y + height, x + length, y + height);
	line(render, x, y, x, y + height);
	line(render, x + length, y, x + length, y + height);
}

void applySurfaceField(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = 32;
    pos.h = 32;
    SDL_RenderCopy(ren, tex, NULL, &pos);
}

void drawfield(SDL_Renderer* ren, int x, int y)
{
    SDL_Surface* surface = nullptr;
    surface = SDL_LoadBMP("src\\brick.bmp");
    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);
    applySurfaceField(x, y, tex, ren);
    SDL_RenderPresent(ren);
}

void Field::Render(SDL_Renderer* render)
{
	rectangle(render, 0, 0, 1088, 512);
	for (int i = 0; i < 1113; i += 32) {
		Block blck1 = Block(i, 512);
		blocks.push_back(blck1);
	}
	for (int i = 512; i > 0; i -= 32) {
		Block blck1 = Block(1088, i);
		blocks.push_back(blck1);
	}
	for (int i = 1088; i > 0; i -= 32) {
		Block blck1 = Block(i, 0);
		blocks.push_back(blck1);
	}
	for (int i = 0; i < 513; i += 32) {
		Block blck1 = Block(0, i);
		blocks.push_back(blck1);
	}
	for (Block block : blocks) {
		drawfield(render, block.getX(), block.getY());
	}
	SDL_RenderPresent(render);
}
