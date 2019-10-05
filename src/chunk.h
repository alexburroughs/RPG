#ifndef CHUNK_H
#define CHUNK_H

#include "filestream.h"
#include <map>

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Chunk {
    private:
        mapbits** map;
        std::map<Direction, Chunk*> links;
    public:
        Chunk(mapbits** map);
        void add_link(Direction direction, Chunk* chunk);
        void remove_link(Direction direction);
        ~Chunk();
};

#endif