#include "textureloader.h"
#include "logger.h"
#include "settings.h"
#include "debug.h"

#include <unordered_map>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_main.h>

Textureloader::Textureloader() {
    
}

SDL_Texture* Textureloader::load_texture(std::string filename, SDL_Renderer* g_renderer)
{
    //The final texture
    SDL_Texture* newTexture = NULL;

    //Load image at specified path
    SDL_Surface* loadedSurface = IMG_Load( filename.c_str() );
    if( loadedSurface == NULL )
    {
        ERROR( "Unable to load image " + filename + " SDL_image Error: " + IMG_GetError() );
    }
    else
    {
        //Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface( g_renderer, loadedSurface );
        if( newTexture == NULL )
        {
            ERROR( "Unable to create texture from " + filename + " SDL Error: " + SDL_GetError() );
        }

        //Get rid of old loaded surface
        SDL_FreeSurface( loadedSurface );
    }

    return newTexture;
}

std::unordered_map<std::string, SDL_Texture*>* Textureloader::load_textures(Settings* files, SDL_Renderer* g_renderer) {

    auto map = new std::unordered_map<std::string, SDL_Texture*>(); 

    auto iters = files->get_iter();
    auto it = iters.first;

    while (it != iters.second) {
        (*map)[it->first] = load_texture(it->second, g_renderer);
        it++;
    }

    return map;
}

Textureloader::~Textureloader() {}