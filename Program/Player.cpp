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

void applySurface(int x, int y, SDL_Texture* tex, SDL_Renderer* ren) {
    SDL_Rect pos;
    pos.x = x;
    pos.y = y;
    pos.w = 60;
    pos.h = 60;
    SDL_RenderCopy(ren, tex, NULL, &pos);
}

void Player::draw(SDL_Renderer* ren, int factor, int x, int y)
{
    SDL_Surface* surface = nullptr;
    if (factor == 1)
        surface = SDL_LoadBMP("src\\rightbluetank.bmp");
    else if (factor == 2)
        surface = SDL_LoadBMP("src\\upbluetank.bmp");
    else if (factor == 3)
        surface = SDL_LoadBMP("src\\leftbluetank.bmp");
    else if (factor == 4)
        surface = SDL_LoadBMP("src\\downbluetank.bmp");

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

    applySurface(x, y, tex, ren);
    SDL_RenderPresent(ren);
}

void Player::move_right(SDL_Renderer* ren)
{
    int save = x;
    if (x + 70 >= 1080)
        while (x + 60 < 1080) {
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
    int save1 = y;
    if (y + 70 >= 500) {
        while (y + 60 < 500) {
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
    int save1 = x;
    if (x - 10 <= 0) {
        while (x > 1) {
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
    int save1 = y;
    if (y - 10 <= 0) {
        while (y > 1) {
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
