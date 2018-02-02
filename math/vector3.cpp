#include "vector3.h"

math::Vector3::Vector3() : Vector3(0, 0, 0)
{}

math::Vector3::Vector3(float x, float y, float z)
    : x_ { x }
    , y_ { y }
    , z_ { z }
{}

float math::Vector3::get_x() const {
    return x_;
}

float math::Vector3::get_y() const {
    return y_;
}

float math::Vector3::get_z() const {
    return z_;
}

math::Vector3& math::Vector3::set_x(float x) {
    x_ = x;
    return *this;
}

math::Vector3& math::Vector3::set_y(float y) {
    y_ = y;
    return *this;
}

math::Vector3& math::Vector3::set_z(float z) {
    z_ = z;
    return *this;
}

math::Vector3& math::Vector3::set(float x, float y, float z) {
    x_ = x;
    y_ = y;
    z_ = z;
    return *this;
}
