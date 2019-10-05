#ifndef MAP_H
#define MAP_H

#include <string>


class Map {
	private:
		int X;
		int Y;
		int** tileMap;
	public:
		Map();
		Map(std::string file_name);
		int getX();
		int getY();
};

#endif