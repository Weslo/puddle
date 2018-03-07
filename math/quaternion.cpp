#include "quaternion.h"
#include <math.h>
#include "math.hpp"
#include "vector3.h"

puddle::Quaternion::Quaternion()
    : Quaternion(0, 0, 0, 0)
{}

puddle::Quaternion::Quaternion(float x, float y, float z, float w)
    : x_ { x }
    , y_ { y }
    , z_ { z }
    , w_ { w }
{}

puddle::Quaternion::Quaternion(float angle, const puddle::Vector3& axis)
    : w_ { cos(angle / 2) }
{
    float s = sin(angle / 2);
    x_ = axis.x() * s;
    y_ = axis.y() * s;
    z_ = axis.z() * s;
}

puddle::Quaternion::Quaternion(float roll, float pitch, float yaw) {

    // Cache the radians conversions.
    float rx = math::degrees_to_radians(roll) / 2;
    float ry = math::degrees_to_radians(pitch) / 2;
    float rz = math::degrees_to_radians(yaw) / 2;

    // Cache the trig.
    float sx = sin(rx);
    float cx = cos(rx);
    float sy = sin(ry);
    float cy = cos(ry);
    float sz = sin(rz);
    float cz = cos(rz);

    // Calculate the quat values.
    // Y and Z are swapped to convert to match coordinate spaces.
    x_ = sx * cy * cz + cx * sy * sz;
    y_ = cx * sy * cz - sx * cy * sz;
    z_ = cx * cy * sz + sx * sy * cz;
    w_ = cx * cy * cz - sx * sy * sz;
}

puddle::Quaternion::Quaternion(const Vector3& eulers)
    : puddle::Quaternion::Quaternion(eulers.x(), eulers.y(), eulers.z())
{}

puddle::Quaternion puddle::Quaternion::operator*(const Quaternion& other) const {
    return multiply(other);
}

puddle::Quaternion& puddle::Quaternion::normalize() {
    float magnitude = sqrt(x() * x() + y() * y() + z() * z() + w() * w());
    x_ = x() / magnitude;
    y_ = y() / magnitude;
    z_ = z() / magnitude;
    w_ = w() / magnitude;
    return *this;
}

puddle::Quaternion puddle::Quaternion::normalized() const {
    return puddle::Quaternion(*this).normalize();
}

puddle::Quaternion puddle::Quaternion::conjugate() const {
    return puddle::Quaternion(-x(), -y(), -z(), w());
}

puddle::Quaternion puddle::Quaternion::scale(float s) const {
    return puddle::Quaternion(x() * s, y() * s, z() * s, w() * s);
}

puddle::Quaternion puddle::Quaternion::multiply(const puddle::Quaternion& other) const {
    return Quaternion(
        x() * other.w() + z() * other.y() - y() * other.z() + w() * other.x(),
        x() * other.z() - z() * other.x() + y() * other.w() + w() * other.y(),
        -x() * other.y() + z() * other.w() + y() * other.x() + w() * other.z(),
        -x() * other.x() - z() * other.z() - y() * other.y() + w() * other.w()
    );
}

puddle::Vector3 puddle::Quaternion::euler_angles() const {
    float roll = atan2(2 * x() * w() - 2 * z() * y(), 1 - 2 * x() * x() - 2 * y() * y());
    float pitch = asin(2 * x() * z() + 2 * y() * w());
    float yaw = atan2(2 * z() * w() - 2 * x() * y(), 1 - 2 * z() * z() - 2 * y() * y());

    roll = math::radians_to_degrees(roll);
    pitch = math::radians_to_degrees(pitch);
    yaw = math::radians_to_degrees(yaw);

    return Vector3(roll, pitch, yaw);
}

float puddle::Quaternion::x() const {
    return x_;
}

float puddle::Quaternion::y() const {
    return y_;
}

float puddle::Quaternion::z() const {
    return z_;
}

float puddle::Quaternion::w() const {
    return w_;
}
