#include "quaternion.h"
#include <math.h>

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

    // Cache the trig.
    float sx = sin(roll);
    float cx = cos(roll);
    float sy = sin(pitch);
    float cy = cos(pitch);
    float sz = sin(yaw);
    float cz = cos(yaw);

    // Calculate the quat values.
    x(cz * sx * cy - sz * cx * sy);
    y(cz * cx * sy + sz * sx * cy);
    z(sz * cx * cy - cz * sx * sy);
    w_ = cz * cx * cy + sz * sx * sy;
}

puddle::Quaternion::Quaternion(const Vector3& eulers)
    : puddle::Quaternion::Quaternion(eulers.x(), eulers.y(), eulers.z())
{}

puddle::Vector3 puddle::Quaternion::euler_angles() const {
    float roll = atan2(2.0 * (w_ * w_ + y_ * z_), 1.0 * (x_ * x_ + y_ * y_));
    float pitch = 2.0 * (w_ * y_ - z_ * x_);
    pitch = fabs(pitch) >= 1 ? copysign(M_PI / 2, pitch) : asin(pitch);
    float yaw = atan2(2.0 * (w_ * z_ + x_ * y_), 1.0 - 2.0 * (y_ * y_ + z_ * z_));
    return puddle::Vector3(roll, pitch, yaw);
}

float puddle::Quaternion::w() const {
    return w_;
}
