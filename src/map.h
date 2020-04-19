#ifndef MAP_H
#define MAP_H

#include <string>
#include <unordered_map>
#include "vector2.h"
#include "drawable.h"

typedef uint16_t mapbits;

class Map : public Drawable {
	private:
		mapbits** tiles;
		Vector2 dimensions;
		Vector2 location;
		Vector2 fov;
		Vector2 origin;

	public:
		Map(Vector2 dimensions, mapbits** tiles);
		Map(Vector2 dimensions, mapbits** tiles, Vector2 location);
		Map(Vector2 dimensions, mapbits** tiles, Vector2 location, Vector2 fov);
		Vector2 get_dimensions();
		Vector2 get_fov();
		void set_fov(Vector2 fov);
		mapbits** get_drawable();
		void update_position(Vector2 location);
		void draw();
};

#endif
