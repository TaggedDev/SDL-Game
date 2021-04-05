#pragma once
#include <SDL.h>
#include "Tank.h"
#include <vector>
using namespace std;
class Field
{
public:
	void Render(SDL_Renderer* render);

private:
	vector<Tank> enemies;
};

