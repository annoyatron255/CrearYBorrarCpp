/*
Timer Control
*/
#include <cstdio>
#include <SDL.h>
#include "lib.h"

Uint32 startTime = 0;

int timeStart() {
    Uint32 startTime = SDL_GetTicks();
    return 0;
}

int timePassed() {
    printf("Milliseconds since start %i\n", (SDL_GetTicks() - startTime));
    //SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION, "Score", (SDL_GetTicks() - startTime), NULL);
    return 0;
}
