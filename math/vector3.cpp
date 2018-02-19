#include "vector3.h"

math::Vector3::Vector3() : Vector3(0, 0, 0)
{}

math::Vector3::Vector3(float x, float y, float z)
    : math::Vector2(x, y)
    , z_ { z }
{}

float math::Vector3::z() const {
    return z_;
}

math::Vector3& math::Vector3::z(float z) {
    z_ = z;
    return *this;
}

math::Vector3& math::Vector3::set(float x, float y, float z) {
    math::Vector2::set(x, y);
    z_ = z;
    return *this;
}
