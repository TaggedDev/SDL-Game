#include "Player.h"
#include <iostream>
#include <SDL.h>

using namespace std;

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

void applySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
    SDL_Rect pos;
    pos.x = 10;
    pos.y = 10;
    pos.w = 60;
    pos.h = 60;
    SDL_RenderCopy(ren, tex, NULL, &pos);
}

void Player::draw(SDL_Renderer* ren, int factor)
{
    SDL_Surface* surface = nullptr;
    if (factor == 1)
        surface = SDL_LoadBMP("rightbluetank.bmp");
    else if (factor == 2)
        surface = SDL_LoadBMP("upbluetank.bmp");
    else if (factor == 3)
        surface = SDL_LoadBMP("leftbluetank.bmp");
    else if (factor == 4)
        surface = SDL_LoadBMP("downbluetank.bmp");

    if (surface == nullptr) {
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        return;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(ren, surface);
    SDL_FreeSurface(surface);

    if (tex == nullptr) {
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        return;
    }

    applySurface(10, 10, tex, ren);
    SDL_RenderPresent(ren);
}

void Player::move_right(SDL_Renderer* ren)
{
    int save = x;
    if (x + 50 < 1081) {
        while (x < save + 100) {
            draw(ren, 1);
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
            draw(ren, 4);
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            y++;
        }
    }
}
void Player::move_left(SDL_Renderer* ren) {
    int save1 = x;
    if (x > 0) {
        while (x > save1 - 100) {
            draw(ren, 3);
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            x--;
        }
    }
}
void Player::move_up(SDL_Renderer* ren) {
    int save1 = y;
    if (y > 0) {
        while (y > save1 - 100) {
            draw(ren, 2);
            full_rect_model(ren, x, y, 50, 25);
            SDL_RenderPresent(ren);
            full_rect_bckg(ren, x, y, 50, 25);
            y--;
        }
    }
}
