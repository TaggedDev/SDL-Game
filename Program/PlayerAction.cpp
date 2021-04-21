#include "Player.h"
#include <iostream>
#include <SDL.h>
#include "Bullet.h"

using namespace std;

void Player::move_right(SDL_Renderer* ren)
{
    state = 2;
    int save = x;
    if (x + 70 >= 1088)
        while (x + 60 < 1088) {
            draw(ren, x, y);
            x++;
        }
    else {
        while (x < save + 10) {
            draw(ren, x, y);
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
            draw(ren, x, y);
            y++;
        }
    }
    else {
        while (y < save1 + 10) {
            draw(ren, x, y); 
            y++;
        }
    }
}
void Player::move_left(SDL_Renderer* ren) {
    state = 4;
    int save1 = x;
    if (x - 10 <= 32) {
        while (x > 33) {
            draw(ren, x, y);
            x--;
        }
    }
    else {
        while (x > save1 - 10) {
            draw(ren, x, y);
            x--;
        }
    }
}
void Player::move_up(SDL_Renderer* ren) {
    state = 1;
    int save1 = y;
    if (y - 10 <= 32) {
        while (y > 32) {
            draw(ren, x, y);
            y--;
        }
    }
    else{
        while (y > save1 - 10) {
            draw(ren, x, y);
            y--;
        }
    }
}
void Player::shooting(SDL_Renderer* ren, Player player1, Player player2) {
    Bullet bullet;
    if (state == 2) {
        for (int i = 65; i < 400; i++) {
            bullet.x = player1.x + i;
            bullet.y = player1.y + 25;
            bullet.StartBullet(bullet, player1, player2, ren);
        }
    }
    if (state == 1) {
        for (int i = -5; i > -335; i--) {
            bullet.x = player1.x + 25;
            bullet.y = player1.y + i;
            bullet.StartBullet(bullet, player1, player2, ren);
        }
    }
    if (state == 4) {
        for (int i = -5; i > -370; i--) {
            bullet.x = player1.x + i;
            bullet.y = player1.y + 25;
            bullet.StartBullet(bullet, player1, player2, ren);
        }
    }
    if (state == 3) {
        for (int i = 65; i < 400; i++) {
            bullet.x = player1.x + 25;
            bullet.y = player1.y + i;
            bullet.StartBullet(bullet, player1, player2, ren);
        }
    }
}
