#include "Player.h"
#include <SDL.h>
void Player::setX(int value) {
    x = value;
}
void Player::setY(int value) {
    y = value;
}
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

void Player::move_right(SDL_Renderer* ren)
{
    int save = x;
    if (x + 50 < 1081) {
        while (x < save + 100) {
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            x++;
        }
    }
}
void Player::move_down(SDL_Renderer* ren)
{
    int save1 = y;
    if (y + 25 < 501) {
        while (y < save1 + 100) {
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            y++;
        }
    }
}
void Player::move_left(SDL_Renderer* ren) {
    int save2 = x;
    if (x > 0) {
        while (x > save2 - 100) {
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            x--;
        }
    }
}
void Player::move_up(SDL_Renderer* ren) {
    int save3 = y;
    if (y > 0) {
        while (y > save3 - 100) {
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            y--;
        }
    }
}
