#include "vector2.h"

Vector2::Vector2(int16_t x, int16_t y) {
    X = x;
    Y = y;
}

int16_t Vector2::getX() {
    return X;
}

int16_t Vector2::getY() {
    return Y;
}

void Vector2::setX(int16_t x) {
    X = x;
}

int32_t Vector2::getCombined() {
    int32_t combined = X << 8;
    return combined + Y;
}

void Vector2::setY(int16_t y) {
    Y = y;
}

bool Vector2::operator==(Vector2 &other) const {
    return (X == other.X && Y == other.Y);
}
