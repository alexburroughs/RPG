#include <string>
#include "map.h"

Map::Map(FileStream* fileStream) {
    this->fileStream = fileStream;
};

int Map::getX() {
    return X;
    };
    
int Map::getY() {
    return Y;
};

void Map::loadMap(std::string filename) {

} 