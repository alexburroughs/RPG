#include <string>
#include "map.h"

Map::Map(FileLoader* fileLoader) {
    this->fileLoader = fileLoader;
};

int Map::getX() {
    return X;
    };
    
int Map::getY() {
    return Y;
};

void Map::loadMap(std::string filename) {

} 