#pragma once
#include <SDL.h>
class Player
{
public:
	void move(int x1, int y1);
	void shoot();
	void move_right(SDL_Renderer* ren);
	void move_down(SDL_Renderer* ren);
	void move_up(SDL_Renderer* ren);
	void move_left(SDL_Renderer* ren);
	void setX(int x);
	void setY(int y);
	void draw(SDL_Renderer* ren, int factor);
private:
	int x = 300;
	int y = 300;
};