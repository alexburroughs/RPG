#ifndef MAP_H
#define MAP_H

#include <string>
#include "fileloader.h"

class Map {
	
	private:
		int X;
		int Y;
		int** tileMap;
		FileLoader* fileLoader;
	public:
		Map(FileLoader* fileLoader);
		void loadMap(std::string filename);
		int getX();
		int getY();
};


#endif