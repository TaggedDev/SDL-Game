#pragma once
#include <SDL.h>
class Player
{
public:
	void move_right(SDL_Renderer* ren);
	void move_down(SDL_Renderer* ren);
	void move_up(SDL_Renderer* ren);
	void move_left(SDL_Renderer* ren);
	void setX(int x);
	void setY(int y);
	void draw(SDL_Renderer* ren, int factor, int x, int y);
	void shooting(SDL_Renderer* ren);
private:
	int x = 300;
	int y = 300;
	
	int state; 
	// state
	// 1 - up
	// 2 - right
	// 3 - down
	// 4 - left
};