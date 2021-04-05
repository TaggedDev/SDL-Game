#include "Player.h"
#include <SDL.h>
void dr_lineX(SDL_Renderer* ren, int x, int y, int len) {
    for (int i = 0; i < len; i++) {
        SDL_RenderDrawPoint(ren, x + i, y);
    }
}
void full_rect(SDL_Renderer* ren, int x, int y, int lenx, int leny) {
    for (int i = y; i < y + leny; i++) {
        dr_lineX(ren, x, i, lenx);
    }
}

void Player::move_right(SDL_Renderer* ren, int y, int fp, int lp)
{
    for (int s = fp; s < lp; s++) {
        SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
        full_rect(ren, s, y, 50, 25);
        SDL_RenderPresent(ren);
        SDL_SetRenderDrawColor(ren, 0, 0, 0, 0);
        SDL_RenderClear(ren);
    }
}
