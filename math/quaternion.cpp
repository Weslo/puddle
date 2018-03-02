#include "quaternion.h"
#include <math.h>
#include "math.hpp"

puddle::Quaternion::Quaternion()
    : Quaternion(0, 0, 0, 0)
{}

puddle::Quaternion::Quaternion(float x, float y, float z, float w)
    : Vector3::Vector3(x, y, z)
    , w_ { w }
{}

puddle::Quaternion::Quaternion(float angle, const puddle::Vector3& axis)
    : w_ { cos(angle / 2) }
{
    float s = sin(angle / 2);
    x(axis.x() * s);
    y(axis.y() * s);
    z(axis.z() * s);
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
    x(sx * cy * cz + cx * sy * sz);
    y(cx * sy * cz - sx * cy * sz);
    z(cx * cy * sz + sx * sy * cz);
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
    x(x() / magnitude);
    y(y() / magnitude);
    z(z() / magnitude);
    w(w() / magnitude);
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

float puddle::Quaternion::w() const {
    return w_;
}

puddle::Quaternion& puddle::Quaternion::w(float w) {
    w_ = w;
    return *this;
}
