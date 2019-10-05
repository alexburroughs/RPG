#ifndef CHUNK_H
#define CHUNK_H

#include "filereader.h"
#include <unordered_map>
#include <cinttypes>

typedef uint16_t mapbits;

constexpr int CHUNK_SIZE = 64;

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

Direction get_inverse(Direction direction) {
    switch (direction) {
        case UP:
            return DOWN;
        case DOWN:
            return UP;
        case LEFT:
            return RIGHT;
        case RIGHT:
            return LEFT;
    }
}

class Chunk {
    private:
        mapbits** data;
        std::unordered_map<Direction, Chunk*> links;
    public:
        Chunk(mapbits** data);
        void add_link(Direction direction, Chunk* chunk);
        void remove_link(Direction direction);
        void remove();
        bool is_valid_link(Direction direction);
        Chunk* get_link(Direction direction);
        ~Chunk();
};

#endif