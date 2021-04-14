#include "Player.h"
#include <iostream>
#include <SDL.h>

using namespace std;

Uint32 getpixel(SDL_Surface* surface, int x, int y)
{
    int bpp = surface->format->BytesPerPixel;
    /* Here p is the address to the pixel we want to retrieve */
    Uint8* p = (Uint8*)surface->pixels + y * surface->pitch + x * bpp;

    switch (bpp)
    {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16*)p;
        break;

    case 3:
        if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32*)p;
        break;

    default:
        return 0;       /* shouldn't happen, but avoids warnings */
    }
}

void GetSurface(SDL_Texture*& tex, SDL_Renderer* ren, SDL_Surface* surf, vector<vector<SDL_Color>>& pixelarray) {
    SDL_Color rgb;
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            Uint32 data = getpixel(surf, i, j);
            SDL_GetRGB(data, surf->format, &rgb.r, &rgb.g, &rgb.b);
            pixelarray[i][j] = rgb;
        }
    }
}
void DrawSurface(SDL_Renderer* ren, vector<vector<SDL_Color>> pixelarray) {
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            SDL_SetRenderDrawColor(ren, pixelarray[i][j].r, pixelarray[i][j].g, pixelarray[i][j].b, pixelarray[i][j].a);
            SDL_RenderDrawPoint(ren, i, j);
        }
    }
}

void Player::setX(int value) {
    x = value;
}
void Player::setY(int value) {
    y = value;
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

    vector<vector<SDL_Color>> pixelarray(60, vector<SDL_Color>(60));
    SDL_Texture* tex;
    GetSurface(tex, ren, surface, pixelarray);
    DrawSurface(ren, pixelarray);
    SDL_FreeSurface(surface);
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
