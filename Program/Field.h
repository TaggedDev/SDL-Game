#pragma once
#include <SDL.h>
#include "Block.h"
#include "Player.h"
#include <vector>
using namespace std;
class Field
{
public:
	void Update(SDL_Renderer* render, Player player1, Player player2);
	void Render(SDL_Renderer* render);
	vector <Block> blocks;	
};

