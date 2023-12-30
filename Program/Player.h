#pragma once
#include <SDL.h>
#include <vector>
class Player
{
public:
	void move_right(SDL_Renderer* ren);
	void move_down(SDL_Renderer* ren);
	void move_up(SDL_Renderer* ren);
	void move_left(SDL_Renderer* ren);
	void setX(int x);
	void setY(int y);
	int getX();
	int getY();
	void Clear(SDL_Renderer* ren);
	void draw(SDL_Renderer* ren, int factor, int x, int y);
	
private:
	int x = 300;
	int y = 300;
	
};