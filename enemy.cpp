/*
Enemy AI
*/
#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "lib.h"

//int direction = 0;
/*
7 0 1
6 X 2
5 4 3
*/

SDL_Rect updateai(SDL_Rect rect, int dir) {
    switch (dir) {
    case 0:
        rect.x -= espeed;
        break;
    case 1:
        rect.x += espeed;
        rect.y -= espeed;
        break;
    case 2:
        rect.y += espeed;
        break;
    case 3:
        rect.x += espeed;
        rect.y += espeed;
        break;
    case 4:
        rect.x += espeed;
        break;
    case 5:
        rect.x -= espeed;
        rect.y += espeed;
        break;
    case 6:
        rect.y -= espeed;
        break;
    case 7:
        rect.x -= espeed;
        rect.y -= espeed;
        break;
    }
    return rect;
}

SDL_Rect checkOnScreen(SDL_Rect rect) {
    if ((rect.x + rect.w) > screenx) {
        rect.x = (screenx - rect.w);
    }
    if ((rect.y + rect.h) > screeny) {
        rect.y = (screeny - rect.h);
    }
    if (rect.x < 0) {
        rect.x = 0;
    }
    if (rect.y < 0) {
        rect.y = 0;
    }
    return rect;
}

int changeDir(SDL_Rect rect, int currentDir) {
    int dir = currentDir;
    if (((rect.x + rect.w) > screenx) || ((rect.y + rect.h) > screeny) || (rect.x < 0) || (rect.y < 0)) {
        dir = randDir();
    }
    return dir;
}

int randDir() {
    return (rand() % 7);
}
