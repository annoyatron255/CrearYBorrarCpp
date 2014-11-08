/*
Input Functions
*/
#include <stdio.h>
#include <SDL.h>
#include "lib.h"

SDL_Event event;

int inputLoop() {
    while (SDL_PollEvent(&event)) {
        windowEvent();
        key();
    }
    return 0;
}

int windowEvent() {
    switch (event.type) {
    case SDL_QUIT:
        done = true;
        break;
    }
    return 0;
}

int key() {
    if (event.type == SDL_KEYDOWN) {
        switch (event.key.keysym.sym) {
        case SDLK_ESCAPE: // check for keypresses
            done = true;
            break; // end case
        }
    }
    return 0;
}
