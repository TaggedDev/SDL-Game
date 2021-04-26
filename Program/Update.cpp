#include <SDL.h>
#include "Player.h"
#include "Field.h"

void Field::Update(SDL_Renderer* render, Player player1, Player player2)
{
	SDL_SetRenderDrawColor(render, 0, 0, 0, 255);
	player2.draw(render, player2.x, player2.y);
	player1.draw(render, player1.x, player1.y);
	SDL_RenderPresent(render);
}