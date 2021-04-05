#pragma once
#include <SDL.h>
class Player
{
public:
	void move(int x1, int y1);
	void shoot();
	void move_right(SDL_Renderer* ren, int y, int fp, int lp);
private:
	int x, y;
};

