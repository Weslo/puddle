#include "vector2.h"

math::Vector2::Vector2() : Vector2(0, 0)
{}

math::Vector2::Vector2(float x, float y)
    : x_ { x }
    , y_ { y }
{}

float math::Vector2::x() const {
    return x_;
}

float math::Vector2::y() const {
    return y_;
}

math::Vector2& math::Vector2::x(float x) {
    x_ = x;
    return *this;
}

math::Vector2& math::Vector2::y(float y) {
    y_ = y;
    return *this;
}

math::Vector2& math::Vector2::set(float x, float y) {
    x_ = x;
    y_ = y;
    return *this;
}
