#include "debug.h"
#include "maploader.h"
#include "reader.h"
#include <deque>
#include "vector2.h"

Maploader::Maploader(Reader* reader) {
    this->reader = reader;
}

Map* Maploader::loadmap(std::string filename) {

   std::deque<mapbits>* deq = reader->readmap(filename);

    mapbits x = deq->front();
    deq->pop_front();

    mapbits y = deq->front();
    deq->pop_front();

    Vector2 dimensions(x,y);

    mapbits** arr;

    arr = new mapbits*[x];

    for (uint16_t i = 0; i < x; i++) {
        arr[i] = new mapbits[y];
    }

    for (uint16_t j = 0; j < y; j++) {
        for (uint16_t i = 0; i < x; i++) {
            arr[i][j] = deq->front();
            deq->pop_front();
        }
    }

    Map *m = new Map(dimensions, arr);

    return m;
}