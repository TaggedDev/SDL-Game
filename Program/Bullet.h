#pragma once
#include <SDL.h>
class Bullet
{
private:
	int x, y;
public:
	void StartBullet(SDL_Renderer* ren, int x, int y, int sizex, int sizey);
};

