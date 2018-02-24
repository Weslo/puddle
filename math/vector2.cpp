#include "vector2.h"

puddle::Vector2::Vector2() : Vector2(0, 0)
{}

puddle::Vector2::Vector2(float x, float y)
    : x_ { x }
    , y_ { y }
{}

bool puddle::Vector2::operator==(const puddle::Vector2& other) const {
    return x() == other.x() && y() == other.y();
}

bool puddle::Vector2::operator!=(const puddle::Vector2& other) const {
    return x() != other.x() || y() != other.y();
}

float puddle::Vector2::x() const {
    return x_;
}

float puddle::Vector2::y() const {
    return y_;
}

puddle::Vector2& puddle::Vector2::x(float x) {
    x_ = x;
    return *this;
}

puddle::Vector2& puddle::Vector2::y(float y) {
    y_ = y;
    return *this;
}

puddle::Vector2& puddle::Vector2::set(float x, float y) {
    x_ = x;
    y_ = y;
    return *this;
}
