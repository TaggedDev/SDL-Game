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
	void move_right(SDL_Renderer* ren, Player& player1, Player& player2);
	void move_down(SDL_Renderer* ren, Player& player1, Player& player2);
	void move_up(SDL_Renderer* ren, Player& player1, Player& player2);
	void move_left(SDL_Renderer* ren, Player& player1, Player& player2);
	void GetSurface(SDL_Texture*& tex, SDL_Renderer* ren, SDL_Surface* surf, vector<vector<SDL_Color>>& pixelarray);
	void draw(SDL_Renderer* ren, int x, int y);
	void shooting(SDL_Renderer* ren, Player& player1, Player& player2);
	int x = 300;
	int y = 300;
	int state = 3;
	bool isDead = false;
	string color;
	SDL_Texture* tex;
	vector<vector<SDL_Color>> pixelarrayUp;
	vector<vector<SDL_Color>> pixelarrayRight;
	vector<vector<SDL_Color>> pixelarrayDown;
	vector<vector<SDL_Color>> pixelarrayLeft;
	Player(int inputX, int inputY, string inputColor, SDL_Renderer* render) {
		vector<vector<SDL_Color>> creater(60, vector<SDL_Color>(60));
		x = inputX;
		y = inputY;
		color = inputColor;
		pixelarrayUp = creater;
		pixelarrayDown = creater;
		pixelarrayLeft = creater;
		pixelarrayRight = creater;
		if (inputColor == "Blue") {
			GetSurface(tex, render, SDL_LoadBMP("src\\upbluetank.bmp"), pixelarrayUp);
			GetSurface(tex, render, SDL_LoadBMP("src\\rightbluetank.bmp"), pixelarrayRight);
			GetSurface(tex, render, SDL_LoadBMP("src\\downbluetank.bmp"), pixelarrayDown);
			GetSurface(tex, render, SDL_LoadBMP("src\\leftbluetank.bmp"), pixelarrayLeft);
		}
		else {
			GetSurface(tex, render, SDL_LoadBMP("src\\upredtank.bmp"), pixelarrayUp);
			GetSurface(tex, render, SDL_LoadBMP("src\\rightredtank.bmp"), pixelarrayRight);
			GetSurface(tex, render, SDL_LoadBMP("src\\downredtank.bmp"), pixelarrayDown);
			GetSurface(tex, render, SDL_LoadBMP("src\\leftredtank.bmp"), pixelarrayLeft);
		}

		
	}
	// state
	// 1 - up
	// 2 - right
	// 3 - down
	// 4 - left
};