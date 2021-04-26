#pragma once
#include <SDL.h>
#include "Player.h"
class Bullet
{
public:
	bool isHit(Player player1, Player player2);
	void StartBullet(Bullet bullet, Player& player1, Player& player2, SDL_Renderer* ren, int sizex = 10, int sizey = 10);
	int x, y;
};

