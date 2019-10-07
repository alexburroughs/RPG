#ifndef MAP_H
#define MAP_H

#include <string>
#include "chunk.h"
#include <unordered_map>
#include <utility>

class Map {
	private:
		int X;
		int Y;
		std::unordered_map<std::pair<int, int>, Chunk*> chunk_map;
		void load_chunk(std::pair<int, int> chunk_pos);
		void unload_chunk(std::pair<int, int> chunk_pos);
	public:
		Map(std::pair<int,int> player_pos);
		Map(std::string file_name, std::pair<int,int> player_pos);
		int getX();
		int getY();
		mapbits** get_drawable();
		void update_chunks(std::pair<int, int> player_pos);
};

#endif