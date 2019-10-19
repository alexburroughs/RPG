#ifndef MAPLOADER_H
#define MAPLOADER_H

#include "map.h"
#include <string>
#include "reader.h"

class Maploader {
    private:
        Reader* reader;
    public:
        Maploader(Reader* reader);
        Map* loadmap(std::string filename);
};

#endif