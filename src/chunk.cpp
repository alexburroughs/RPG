#include <chunk.h>
#include "debug.h"

Chunk::Chunk(mapbits** data) {
    this->data = data;

    links[UP] = NULL;
    links[DOWN] = NULL;
    links[LEFT] = NULL;
    links[RIGHT] = NULL;
}

void Chunk::add_link(Direction direction, Chunk* chunk) {
    if (links[direction] == NULL)
        links[direction] = chunk;
    else
        DEBUG("Warning: can't assign link to non null direction")
}

void Chunk::remove_link(Direction direction) {
    links[direction] = NULL;
}

bool Chunk::is_valid_link(Direction direction) {
    return links[direction] == NULL;
}

void Chunk::remove() {
    for (int i = UP; i < RIGHT; i++) {
        links[(Direction)i]->remove_link(get_inverse((Direction)i));
    }
}

Chunk* Chunk::get_link(Direction direction) {
    if (links[direction] != NULL)
        return links[direction];
    else {
        DEBUG("Error: trying to get link to a null direction")
        DEBUG("exiting...")
        exit(1);
    }

}

Chunk::~Chunk() {

    if (data != NULL) {
        for (int i = 0; i < CHUNK_SIZE; i++) {

            if (data[i])
            delete[] data[i];
        }

        delete[] data;
    }

    links.clear();
    
}