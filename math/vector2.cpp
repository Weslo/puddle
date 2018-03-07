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

puddle::Vector2 puddle::Vector2::operator+(const puddle::Vector2& other) const {
    return puddle::Vector2(x() + other.x(), y() + other.y());
}

puddle::Vector2& puddle::Vector2::operator+=(const puddle::Vector2& other) {
    x_ += other.x();
    y_ += other.y();
    return *this;
}

puddle::Vector2 puddle::Vector2::operator-(const puddle::Vector2& other) const {
    return puddle::Vector2(x() - other.x(), y() - other.y());
}

puddle::Vector2& puddle::Vector2::operator-=(const puddle::Vector2& other) {
    x_ -= other.x();
    y_ -= other.y();
    return *this;
}

puddle::Vector2 puddle::Vector2::operator*(float scalar) const {
    return puddle::Vector2(x() * scalar, y() * scalar);
}

puddle::Vector2 puddle::operator*(float scalar, const puddle::Vector2& vec) {
    return vec * scalar;
}

puddle::Vector2& puddle::Vector2::operator*=(float scalar) {
    x_ *= scalar;
    y_ *= scalar;
    return *this;
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
