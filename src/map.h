#ifndef MAP_H
#define MAP_H

#include <string>

class Map {
	private:
		int X;
		int Y;
<<<<<<< HEAD
		FileStream* fileStream;
=======
		int** tileMap;
>>>>>>> master
	public:
		Map();
		Map(std::string file_name);
		int getX();
		int getY();
};

#endif