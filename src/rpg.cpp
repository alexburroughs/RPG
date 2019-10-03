#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <memory>

#include "keyboard.h"

bool init();
bool loadMedia();
void close();

const int SCREEN_WIDTH = 1920;
const int SCREEN_HEIGHT = 1080;

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;

int main() {

    bool exit = false;
    auto keystate = std::make_shared<Keyboard>();

    init();

    while (!exit) {
        keystate->update();

        exit = keystate->isDown(SDLK_ESCAPE) || keystate->isClosed(); 
    }

    close();
}

bool init() {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {

        printf("SDL could not initialize");
        exit(1);
    }

    gWindow = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (gWindow == NULL) {
        
        printf("Window could not be created");
        exit(1);
    }

    gSurface = SDL_GetWindowSurface(gWindow);

    return true;
}

void close() {

}