#include "vector3.h"

puddle::Vector3::Vector3() : Vector3(0, 0, 0)
{}

puddle::Vector3::Vector3(float x, float y, float z)
    : x_ { x }
    , y_ { y }
    , z_ { z }
{}

puddle::Vector3 puddle::Vector3::up() {
    return puddle::Vector3(0, 1, 0);
}

puddle::Vector3 puddle::Vector3::down() {
    return puddle::Vector3(0, -1, 0);
}

puddle::Vector3 puddle::Vector3::left() {
    return puddle::Vector3(-1, 0, 0);
}

puddle::Vector3 puddle::Vector3::right() {
    return puddle::Vector3(1, 0, 0);
}

puddle::Vector3 puddle::Vector3::forward() {
    return puddle::Vector3(0, 0, 1);
}

puddle::Vector3 puddle::Vector3::back() {
    return puddle::Vector3(0, 0, -1);
}

bool puddle::Vector3::operator==(const puddle::Vector3& other) const {
    return x() == other.x()
        && y() == other.y()
        && z() == other.z();
}

bool puddle::Vector3::operator!=(const puddle::Vector3& other) const {
    return !operator==(other);
}

puddle::Vector3 puddle::Vector3::operator+(const puddle::Vector3& other) const {
    return puddle::Vector3(x() + other.x(), y() + other.y(), z() + other.z());
}

puddle::Vector3& puddle::Vector3::operator+=(const puddle::Vector3& other) {
    x_ += other.x();
    y_ += other.y();
    z_ += other.z();
    return *this;
}

puddle::Vector3 puddle::Vector3::operator-(const puddle::Vector3& other) const {
    return puddle::Vector3(x() - other.x(), y() - other.y(), z() - other.z());
}

puddle::Vector3& puddle::Vector3::operator-=(const puddle::Vector3& other) {
    x_ -= other.x();
    y_ -= other.y();
    z_ -= other.z();
    return *this;
}

puddle::Vector3 puddle::Vector3::operator*(float scalar) const {
    return puddle::Vector3(x() * scalar, y() * scalar, z() * scalar);
}

puddle::Vector3 puddle::operator*(float scalar, const puddle::Vector3& vec) {
    return vec * scalar;
}

puddle::Vector3& puddle::Vector3::operator*=(float scalar) {
    x_ *= scalar;
    y_ *= scalar;
    z_ *= scalar;
    return *this;
}

puddle::Vector3 puddle::Vector3::operator/(float scalar) const {
    return puddle::Vector3(x() / scalar, y() / scalar, z() / scalar);
}

puddle::Vector3& puddle::Vector3::operator/=(float scalar) {
    x_ /= scalar;
    y_ /= scalar;
    z_ /= scalar;
    return *this;
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
