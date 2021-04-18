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
    r = 1;
    l = 0;
    u = 0;
    d = 0;
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
    d = 1;
    r = 0;
    l = 0;
    u = 0;
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
    l = 1;
    r = 0;
    u = 0;
    d = 0;
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
    u = 1;
    r = 0;
    l = 0;
    d = 0;
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
    if (r == 1) {
        for (int i = x + 65; i < x + 400; i++) {
            model_render(ren, i, y + 25, 10, 10);
        }
    }
    if (u == 1) {
        for (int i = y - 10; i > y - 400; i--) {
            model_render(ren, x + 25, i, 10, 10);
        }
    }
    if (l == 1) {
        for (int i = x - 10; i > x - 400; i--) {
            model_render(ren, i, y + 25, 10, 10);
        }
    }
    if (d == 1) {
        for (int i = y + 65; i < y + 400; i++) {
            model_render(ren, x + 25, i, 10, 10);
        }
    }
}
