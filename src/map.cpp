#include <string>
#include "map.h"
#include "vector2.h"
#include "drawable.h"

Map::Map(Vector2 dimensions, mapbits** tiles) {
    this->dimensions = dimensions;
    this->tiles = tiles;
}

Map::Map(Vector2 dimensions, mapbits** tiles, Vector2 location) {
    Map(dimensions, tiles);
    this->location = location;
}

Map::Map(Vector2 dimensions, mapbits** tiles, Vector2 location, Vector2 fov) {
    Map(dimensions, tiles, location);
    this->fov = fov;
}

Vector2 Map::get_dimensions() {
    return dimensions;
}

Vector2 Map::get_fov() {
    return fov;
}

void Map::set_fov(Vector2 fov) {
    this->fov = fov;
}

mapbits** Map::get_drawable() {

    int32_t x = (fov.getX() < location.getX()) ? 
        location.getX() : fov.getX();

    int32_t w = ((fov.getX() + location.getX() > dimensions.getX()) ? 
        dimensions.getX() : fov.getX() + location.getX()) - x;

    int32_t y = (fov.getY() < location.getY()) ? 
        location.getY() : fov.getY();

    int32_t h = ((fov.getY() + location.getY() > dimensions.getY()) ? 
        dimensions.getY() : fov.getY() + location.getY()) - y;


    mapbits** arr = new mapbits*[w];

    for (int32_t i = 0; i < h; i++) {
        arr[i] = new mapbits[h];

        for (int32_t j = 0; j < w; j++) {
            arr[i][j] = tiles[i+x][j+y];
        }
    }

    return arr;
}

void Map::draw() {
    mapbits** map = get_drawable();
}
