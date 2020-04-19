#ifndef VECTOR2_H
#define VECTOR2_H

#include <cinttypes>
#include <functional>

class Vector2 {
    private:
        int32_t X;
        int32_t Y;
    public:
        Vector2(int32_t x, int32_t y);
        Vector2();

        int32_t getX ();
        int32_t getY ();

        int64_t getCombined ();

        void setX (int32_t x);
        void setY (int32_t y);
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

      return ((hash<int32_t>()(k.getX()) ^ (hash<int32_t>()(k.getY()) << 1)) >> 1);
    }
  };
}

#endif