#pragma once
#include <SDL.h>
class Tank
{
public:
	void move(int x1, int y1);
	void shoot();
	void draw(SDL_Renderer* ren);
private:
	int x, y;
};

