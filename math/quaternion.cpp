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
