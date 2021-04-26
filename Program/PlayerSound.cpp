#include <stdio.h>
#include <SDL_mixer.h>
#include "Player.h"

void Player::playEnd() {

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}

	Mix_Chunk* gMusic = NULL;
	gMusic = Mix_LoadWAV("src\\tf2.wav");
	if (gMusic == NULL) {
		printf("Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError());
		return;
	}
	Mix_PlayChannel(-1, gMusic, 0);
}