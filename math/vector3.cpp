#include "vector3.h"

puddle::Vector3::Vector3() : Vector3(0, 0, 0)
{}

puddle::Vector3::Vector3(float x, float y, float z)
    : puddle::Vector2(x, y)
    , z_ { z }
{}

float puddle::Vector3::z() const {
    return z_;
}

puddle::Vector3& puddle::Vector3::z(float z) {
    z_ = z;
    return *this;
}

puddle::Vector3& puddle::Vector3::set(float x, float y, float z) {
    puddle::Vector2::set(x, y);
    z_ = z;
    return *this;
}
