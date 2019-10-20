#ifndef VECTOR2_H
#define VECTOR2_H

#include <cinttypes>
#include <functional>

class Vector2 {
    private:
        int16_t X;
        int16_t Y;
    public:
        Vector2(int16_t x, int16_t y);
        Vector2();

        int16_t getX ();
        int16_t getY ();

        int32_t getCombined ();

        void setX (int16_t x);
        void setY (int16_t y);
        bool operator==(Vector2 &other) const;
};

/*
    hash implementation for the vector2 class
*/

namespace std {

  template <>
  struct hash<Vector2> {
    std::size_t operator()(Vector2& k) const {
      
      using std::size_t;
      using std::hash;

      return ((hash<int16_t>()(k.getX()) ^ (hash<int16_t>()(k.getY()) << 1)) >> 1);
    }
  };
}

#endif