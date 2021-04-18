#include "Player.h"
#include <iostream>
#include <SDL.h>

using namespace std;

void dr_lineX(SDL_Renderer* ren, int x, int y, int len) {
    for (int i = 0; i < len; i++) {
        SDL_RenderDrawPoint(ren, x + i, y);
    }
}
void full_rect_model(SDL_Renderer* ren, int x, int y, int lenx, int leny) {
    SDL_SetRenderDrawColor(ren, 255, 255, 255, 255);
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
void model_render(SDL_Renderer* ren, int x, int y, int sizex, int sizey) {
    full_rect_model(ren, x, y, sizex, sizey);
    SDL_RenderPresent(ren);
    full_rect_bckg(ren, x, y, sizex, sizey);
}

void Player::move_right(SDL_Renderer* ren)
{
    state = 2;
    int save = x;
    if (x + 70 >= 1088)
        while (x + 60 < 1088) {
            draw(ren, 1, x, y);
            x++;
        }
    else {
        while (x < save + 10) {
            draw(ren, 1, x, y);
            x++;
        }
    }
}
void Player::move_down(SDL_Renderer* ren)
{
    state = 3;
    int save1 = y;
    if (y + 70 >= 512) {
        while (y + 60 < 512) {
            draw(ren, 4, x, y);
            y++;
        }
    }
    else {
        while (y < save1 + 10) {
            draw(ren, 4, x, y); 
            y++;
        }
    }
}
void Player::move_left(SDL_Renderer* ren) {
    state = 4;
    int save1 = x;
    if (x - 10 <= 32) {
        while (x > 33) {
            draw(ren, 3, x, y);
            x--;
        }
    }
    else {
        while (x > save1 - 10) {
            draw(ren, 3, x, y);
            x--;
        }
    }
}
void Player::move_up(SDL_Renderer* ren) {
    state = 1;
    int save1 = y;
    if (y - 10 <= 32) {
        while (y > 32) {
            draw(ren, 2, x, y);
            y--;
        }
    }
    else{
        while (y > save1 - 10) {
            draw(ren, 2, x, y);
            y--;
        }
    }
}
void Player::shooting(SDL_Renderer* ren) {
    if (state == 2) {
        for (int i = x + 65; i < x + 400; i++) {
            model_render(ren, i, y + 25, 10, 10);
        }
    }
    if (state == 1) {
        for (int i = y - 10; i > y - 400; i--) {
            model_render(ren, x + 25, i, 10, 10);
        }
    }
    if (state == 4) {
        for (int i = x - 10; i > x - 400; i--) {
            model_render(ren, i, y + 25, 10, 10);
        }
    }
    if (state == 3) {
        for (int i = y + 65; i < y + 400; i++) {
            model_render(ren, x + 25, i, 10, 10);
        }
    }
}
