#ifndef MAP_H
#define MAP_H

#include <string>
#include "../../tools/fileloader.h"

class Map {
	
	private:
		int X;
		int Y;
		int** tileMap;
	public:
		Map();
		void loadMap(std::string filename, FileLoader fileLoader);
		int getX();
		int getY();
};


#endif
