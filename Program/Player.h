#pragma once
#include <SDL.h>
class Player
{
public:
	void move(int x1, int y1);
	void shoot();
	void move_right(SDL_Renderer* ren, int x, int y);
	void move_down(SDL_Renderer* ren, int x, int y);
	void move_up(SDL_Renderer* ren, int x, int y);
	void move_left(SDL_Renderer* ren, int x, int y);
private:
	int x, y;
};

