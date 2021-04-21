#pragma once
#include <SDL.h>
#include "Player.h"
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Player
{
public:
	void move_right(SDL_Renderer* ren);
	void move_down(SDL_Renderer* ren);
	void move_up(SDL_Renderer* ren);
	void move_left(SDL_Renderer* ren);
	void GetSurface(SDL_Texture*& tex, SDL_Renderer* ren, SDL_Surface* surf, vector<vector<SDL_Color>>& pixelarray);
	void draw(SDL_Renderer* ren, int factor, int x, int y);
	void shooting(SDL_Renderer* ren, Player player1, Player player2);
	int x = 300;
	int y = 300;
	int state = 1;
	bool isDead = false;
	string color;
	SDL_Texture* tex;
	vector<vector<SDL_Color>> pixelarray;
	//SDL_Surface* sur;
	Player(int inputX, int inputY, string inputColor, SDL_Renderer* render) {
		vector<vector<SDL_Color>> creater(60, vector<SDL_Color>(60));
		x = inputX;
		y = inputY;
		color = inputColor;
		pixelarray = creater;
	}
	// state
	// 1 - up
	// 2 - right
	// 3 - down
	// 4 - left
};