/*
Comment Here

*/
#include <stdio.h>
#include <SDL.h>
#include "lib.h"

const int screenx = 400; // 400 normal
const int screeny = 400; // 400 normal

SDL_Rect player = {(screenx - 50) / 2, (screeny - 50) / 2, 50, 50}; //player x y w h
const int playerr = 255; const int playerg = 0; const int playerb = 0; // Player colors
SDL_Rect enemy[] = {{20, 20, 60, 60},{(screenx - 100), 40, 100, 20},{(screenx - 60), (screeny - 100), 20, 100},{20, (screeny - 70), 60, 40}}; // enemy array x y w h
int edirection[] = {0, 2, 4, 6}; // enemy direction
const int enemyr = 0; const int enemyg = 0; const int enemyb = 255; // enemy rgb color

bool done = false;
bool start = false;
double espeed = 1; // Start Speed
const double rate = .01; // Rate of change in speed

int main(int argc, char* args[]) {
    gfxinit(screenx, screeny); // init SDL
    draw(); // draw attract
    while (!done) {
        //Input
        inputLoop(); // check for input
        while (!start & !done) {// pause program until window clicked
            inputLoop();
            if (SDL_GetMouseState(NULL, NULL) & SDL_BUTTON(SDL_BUTTON_LEFT)) { // Check if game has started
                start = true;
                timeStart(); // Start timer
                setupMouse();
            }
        }
        //Input Ends
        SDL_GetMouseState(&player.x, &player.y);
        for (int i =0; i <= enumber;i++) { // update enemy ai
            enemy[i] = updateai(enemy[i], edirection[i]);
            edirection[i] = changeDir(enemy[i], edirection[i]);
            enemy[i] = checkOnScreen(enemy[i]);
        }
        player = checkOnScreen(player);
        if (checkDeath() == true) { // check if dead
            timePassed();
            close();
            return 0;
        }
        draw();
        espeed += rate; // increase speed
    }
    close();
    return 0;
}

int draw() {
    clearScreen();
    fillRect(player, playerr, playerg, playerb);
    for (int i = 0; i <= enumber;i++) {
        fillRect(enemy[i], enemyr, enemyg, enemyb);
    }
    update();
    return 0;
}

int setupMouse() {
    SDL_ShowCursor(SDL_DISABLE);
    SDL_SetRelativeMouseMode(SDL_TRUE);
    return 0;
}
