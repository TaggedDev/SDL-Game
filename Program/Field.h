#pragma once
#include <SDL.h>
#include "Block.h"
#include <vector>
using namespace std;
class Field
{
public:
	void Render(SDL_Renderer* render);

private:
	vector<Block> blocks;
};

