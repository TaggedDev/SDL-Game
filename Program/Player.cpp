#include "Player.h"
#include <SDL.h>
int x = 200;
int y = 200;
void dr_lineX(SDL_Renderer* ren, int x, int y, int len) {
    for (int i = 0; i < len; i++) {
        SDL_RenderDrawPoint(ren, x + i, y);
    }
}
void full_rect_model(SDL_Renderer* ren, int x, int y, int lenx, int leny) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255,255);
    for (int i = y; i < y + leny; i++) {
        dr_lineX(ren, x, i, lenx);
    }
}
void full_rect_bckg(SDL_Renderer* ren, int x, int y, int lenx, int leny) {
    SDL_SetRenderDrawColor(ren, 0, 0, 0, 255);
    for (int i = y; i < y + leny; i++) {
        dr_lineX(ren, x, i, lenx);
    }
}

void Player::move_right(SDL_Renderer* ren, int x, int y)
{
    int save = x;
    while (x < save + 5) {
        full_rect_model(ren, x, y, 50, 25);
        SDL_RenderPresent(ren);
        full_rect_bckg(ren, x, y, 50, 25);
        x++;
    }

}
void Player::move_down(SDL_Renderer* ren, int x, int y)
{
    int save1 = y;
    while (y < save1 + 5) {
        full_rect_model(ren, x, y, 50, 25);
        SDL_RenderPresent(ren);
        full_rect_bckg(ren, x, y, 50, 25);
        y++;
    }
}
void Player::move_left(SDL_Renderer* ren, int x, int y) {
    int save1 = x;
    while (x > save1 - 5) {
        full_rect_model(ren, x, y, 50, 25);
        SDL_RenderPresent(ren);
        full_rect_bckg(ren, x, y, 50, 25);
        x--;
    }
}
void Player::move_up(SDL_Renderer* ren, int x, int y) {
    int save1 = y;
    while (y > save1 - 5) {
        full_rect_model(ren, x, y, 50, 25);
        SDL_RenderPresent(ren);
        full_rect_bckg(ren, x, y, 50, 25);
        y--;
    }
}
