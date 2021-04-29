#include "Bullet.h"
#include "Player.h"
#include <SDL.h>
#include <iostream>

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

bool Bullet::isHit(Player player1, Player player2) {
    int posX1 = player1.x;
    int posY1 = player1.y;
    int posX2 = player2.x;
    int posY2 = player2.y;

    if (x >= posX1 && x <= posX1 + 60 && y >= posY1 && y <= posY1 + 60) return true;
    if (x >= posX2 && x <= posX2 + 60 && y >= posY2 && y <= posY2 + 60) return true;
    return false;
}

void Bullet::StartBullet(Bullet bullet, Player& player1, Player& player2, SDL_Renderer* ren, int sizex, int sizey) {
    if (player1.isDead || player2.isDead)
        return;
    if (x == 1087 || x == 1 || y == 1 || y == 511)
        return;
    if (isHit(player1, player2)) {
        player1.playEnd();
        player1.isDead = true;
        if (player1.color == "Blue")
            cout << "Siniy igrok vigral" << endl;
        else
            cout << "Krasny igrok vigral" << endl;
        return;
    }
    full_rect_model(ren, x, y, sizex, sizey);
    SDL_RenderPresent(ren);
    full_rect_bckg(ren, x, y, sizex, sizey);
    
}
