#include <SDL2/SDL.h>
#include <iostream>
#include <stdlib.h>
#include <memory>

#include "keyboard.h"

#include "settings.h"
#include "settingsloader.h"
#include "reader.h"
#include "csvreader.h"
#include "debug.h"

bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
bool loadMedia();
void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;

int main() {

    bool exit = false;
    Settingsloader sl(new CsvReader());

    auto keystate = std::make_shared<Keyboard>();
    Settings* settings = sl.loadsettings("config/game.properties");
    DEBUG("wtests")
    DEBUG(settings->get_value("screen_width"))
    DEBUG("wteste")

    int SCREEN_WIDTH = stoi(settings->get_value("screen_width"));
    int SCREEN_HEIGHT = stoi(settings->get_value("screen_height"));

    DEBUG(settings->get_value("screen_width"))

    init(SCREEN_WIDTH, SCREEN_HEIGHT);

    while (!exit) {
        keystate->update();

        exit = keystate->isDown(SDLK_ESCAPE) || keystate->isClosed(); 
    }

    close();
}

bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT) {

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