#pragma once
#include <SDL.h>
#include "Player.h"
#include <string>
#include <iostream>
using namespace std;

class Player
{
public:
	void move_right(SDL_Renderer* ren);
	void move_down(SDL_Renderer* ren);
	void move_up(SDL_Renderer* ren);
	void move_left(SDL_Renderer* ren);
	void draw(SDL_Renderer* ren, int factor, int x, int y);
	void shooting(SDL_Renderer* ren, Player player1, Player player2);
	int x = 300;
	int y = 300;
	int state = 1;
	bool isDead = false;
	string color;
	Player(int inputX, int inputY, string inputColor, SDL_Renderer* render) {
		x = inputX;
		y = inputY;
		color = inputColor;
	}
	// state
	// 1 - up
	// 2 - right
	// 3 - down
	// 4 - left
};