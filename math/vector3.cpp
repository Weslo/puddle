#include "vector3.h"

puddle::Vector3::Vector3() : Vector3(0, 0, 0)
{}

puddle::Vector3::Vector3(float x, float y, float z)
    : x_ { x }
    , y_ { y }
    , z_ { z }
{}

bool puddle::Vector3::operator==(const Vector3& other) const {
    return x() == x()
        && y() == y()
        && z() == z();
}

bool puddle::Vector3::operator!=(const Vector3& other) const {
    return !operator==(other);
}

float& puddle::Vector3::x() {
    return x_;
}

float puddle::Vector3::x() const {
    return x_;
}

float& puddle::Vector3::y() {
    return y_;
}

float puddle::Vector3::y() const {
    return y_;
}

float& puddle::Vector3::z() {
    return z_;
}

float puddle::Vector3::z() const {
    return z_;
}

puddle::Vector3& puddle::Vector3::set(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
    return *this;
}
