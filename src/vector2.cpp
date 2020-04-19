#include "vector2.h"

Vector2::Vector2(int32_t x, int32_t y) {
    X = x;
    Y = y;
}

Vector2::Vector2(){

}

int32_t Vector2::getX() {
    return X;
}

int32_t Vector2::getY() {
    return Y;
}

void Vector2::setX(int32_t x) {
    X = x;
}

int64_t Vector2::getCombined() {
    int64_t combined = X << 8;
    return combined + Y;
}

void Vector2::setY(int32_t y) {
    Y = y;
}

bool Vector2::operator==(Vector2 &other) const {
    return (X == other.X && Y == other.Y);
}
