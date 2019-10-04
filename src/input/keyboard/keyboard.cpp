#include "keyboard.h"
#include <SDL2/SDL.h>

Keyboard::Keyboard() {
    for (int i = 0; i < NUM_KEYS; i++) {
        KEYS[i] = false;
    }
    closed = false;
}

void Keyboard::update() {

    /*SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            closed = true;
            break;
        case SDL_KEYDOWN:
            KEYS[event.key.keysym.sym] = true;
            break;
        case SDL_KEYUP:
            KEYS[event.key.keysym.sym] = false;
            break;
        default:
            break;
        }
    }*/
}

bool Keyboard::isUp(int index) {
    return !KEYS[index];
}

bool Keyboard::isDown(int index) {
    return KEYS[index];
}

bool Keyboard::isClosed() {
    return closed;
}