//Using SDL and standard IO
#include <SDL.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;
//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char* args[])
{
	SDL_Window* window;
	SDL_Renderer* ren;
	SDL_CreateWindowAndRenderer(SCREEN_WIDTH, SCREEN_HEIGHT, 0, &window, &ren);
	SDL_SetRenderDrawColor(ren, 255, 255, 0, 255);
	

	SDL_RenderPresent(ren);

	// Delay
	SDL_Delay(3000);

	//Destroy window
	SDL_DestroyWindow(window);

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}