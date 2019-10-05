#ifndef MAP_H
#define MAP_H

#include <string>
#include "filestream.h"

class Map {
	
	private:
		int X;
		int Y;
		int** tileMap;
		FileStream* fileStream;
	public:
		Map(FileStream* fileStream);
		void loadMap(std::string filename);
		int getX();
		int getY();
};


#endif