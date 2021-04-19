#include "Bullet.h"
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

void Bullet::StartBullet(SDL_Renderer* ren, int x, int y, int sizex, int sizey) {
    full_rect_model(ren, x, y, sizex, sizey);
    SDL_RenderPresent(ren);
    full_rect_bckg(ren, x, y, sizex, sizey);
}
