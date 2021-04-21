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

void Player::GetSurface(SDL_Texture*& tex, SDL_Renderer* ren, SDL_Surface* surf, vector<vector<SDL_Color>>& pixelarray) {
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

void DrawSurface(SDL_Renderer* ren, vector<vector<SDL_Color>> pixelarray, int newx, int newy) {
    for (int i = 0; i < 60; i++)
    {
        for (int j = 0; j < 60; j++)
        {
            SDL_SetRenderDrawColor(ren, pixelarray[i][j].r, pixelarray[i][j].g, pixelarray[i][j].b, pixelarray[i][j].a);
            SDL_RenderDrawPoint(ren, i + newx, j + newy);
        }
    }
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

    GetSurface(tex, ren, surface, pixelarray);
    DrawSurface(ren, pixelarray, x, y);
    SDL_FreeSurface(surface);
    SDL_RenderPresent(ren);
}