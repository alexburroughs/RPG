#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>
#include <iostream>
#include <stdlib.h>
#include <memory>

#include "keyboard.h"

#include "settings.h"
#include "settingsloader.h"
#include "textureloader.h"
#include "reader.h"
#include "csvreader.h"
#include "debug.h"

bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT);
bool loadMedia();
//void close();

SDL_Window* gWindow = NULL;
SDL_Surface* gSurface = NULL;
SDL_Renderer* gRenderer = NULL;

int main() {
    
    bool exit = false;
    Settingsloader sl(new CsvReader());
    Textureloader tl = Textureloader();

    auto keystate = std::make_shared<Keyboard>();
    Settings* settings = sl.loadsettings("config/game.properties", "");
    Settings* assets = sl.loadsettings("config/textures.properties", "Tiles");

    int SCREEN_WIDTH = stoi(settings->get_value("screen_width"));
    DEBUG("Accessed screen width")
    int SCREEN_HEIGHT = stoi(settings->get_value("screen_height"));

    init(SCREEN_WIDTH, SCREEN_HEIGHT);

    auto asset_map = tl.load_textures(assets, gRenderer);

    SDL_Rect dest;
    dest.x = 0;
    dest.y = 0;
    dest.h = 320;
    dest.w = 320;

    while (!exit) {
        
        if (SDL_RenderCopy(gRenderer, (*asset_map)["grass"],NULL, &dest ) < 0) {
            ERROR((std::string)"Error drawing: " + SDL_GetError());
        }

        SDL_RenderPresent(gRenderer);

        keystate->update();

        exit = keystate->isDown(SDLK_ESCAPE) || keystate->isClosed(); 
    }

    //close();
}

bool init(int SCREEN_WIDTH, int SCREEN_HEIGHT) {

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {

        ERROR("SDL could not initialize");
        exit(1);
    }

    DEBUG("SDL initialized")

    gWindow = SDL_CreateWindow("RPG", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

    if (gWindow == NULL) {
        
        ERROR("Window could not be created");
        exit(1);
    }

    DEBUG("Window created")

    gSurface = SDL_GetWindowSurface(gWindow);

    gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
    if( gRenderer == NULL )
    {
        ERROR( (std::string)"Renderer could not be created! SDL Error: " + SDL_GetError() );
    }
    else
    {
        //Initialize renderer color
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

        //Initialize PNG loading
        int imgFlags = IMG_INIT_PNG;
        if( !( IMG_Init( imgFlags ) & imgFlags ) )
        {
            ERROR( (std::string)"SDL_image could not initialize! SDL_image Error: " + IMG_GetError() );
        }
    }

    return true;
}