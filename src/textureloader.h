#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include "settings.h"
#include <string>
#include <SDL2/SDL.h>
#include <unordered_map>

class Textureloader {

    private:
        SDL_Texture * load_texture(std::string filename, SDL_Renderer* g_renderer);
    public:
        Textureloader();
        std::unordered_map<std::string, SDL_Texture*>* load_textures(Settings* files, SDL_Renderer* g_renderer);
        ~Textureloader();
};

#endif