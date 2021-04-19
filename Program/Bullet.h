#pragma once
#include <SDL.h>
#include "Player.h"
class Bullet
{
public:
	bool isHit(Player player1, Player player2);
	void StartBullet(Player player1, Player player2, SDL_Renderer* ren, int x, int y, int sizex, int sizey);
	int x, y;
};

