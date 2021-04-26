//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "Field.h"
#include "Player.h"
#include <SDL_mixer.h>
#include "Game.h"
#include "Menu.h"

using namespace std;
//Screen dimension constants
void MenuHandler(const Uint8* keyboard_state_array1, Menu& start, bool& done)
{
	if (keyboard_state_array1[SDL_SCANCODE_SPACE]) {
		start.start(done);
	}

}

void playStart() {

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}

	Mix_Chunk* gMusic = NULL;
	gMusic = Mix_LoadWAV("src\\start.wav");
	if (gMusic == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}
	Mix_PlayChannel(-1, gMusic, 0);
}

int main(int argc, char* args[])
{
	SDL_Event e;
	bool done = false, quit = false;
	Menu start;
	const int SCREEN_WIDTH = 1280;
	const int SCREEN_HEIGHT = 600;
	int point = 0;
	start.start(done);
	while (!quit) {
		SDL_Window* win;
		SDL_Renderer* ren;
		SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &win, &ren);
		SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
		playStart();
		Field field;
		field.Render(ren);
		Player player1 = Player(50, 50, "Red", ren);
		Player player2 = Player(600, 400, "Blue", ren);

		while (!done) {
			if (!(player1.isDead || player2.isDead)) {
				field.Update(ren, player1, player2);
				const Uint8* keyboard_state_array = SDL_GetKeyboardState(NULL);
				SDL_PollEvent(&e);
				if (e.type == SDL_KEYDOWN || e.type == SDL_KEYUP) EventHanlder(keyboard_state_array, player1, ren, player2);
			}
		}
	}
	SDL_Window* window;
	SDL_Renderer* render;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &render);
	return 0;
}
void EventHanlder(const Uint8* keyboard_state_array, Player& player1, SDL_Renderer* ren, Player& player2)
{
	/// <summary>
	/// First player controls
	/// </summary>
	if (keyboard_state_array[SDL_SCANCODE_UP]) player1.move_up(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_DOWN]) player1.move_down(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_LEFT]) player1.move_left(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_RIGHT]) player1.move_right(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_RSHIFT]) player1.shooting(ren, player1, player2);
	/// <summary>
	/// Second player controls
	/// <summary>
	if (keyboard_state_array[SDL_SCANCODE_W]) player2.move_up(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_S]) player2.move_down(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_A]) player2.move_left(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_D]) player2.move_right(ren, player1, player2);
	if (keyboard_state_array[SDL_SCANCODE_SPACE]) player2.shooting(ren, player2, player1);
}
