#include "quaternion.h"
#include <math.h>

puddle::Quaternion::Quaternion()
    : Quaternion(0, 0, 0, 0)
{}

puddle::Quaternion::Quaternion(float x, float y, float z, float w)
    : Vector3::Vector3(x, y, z)
    , w_ { w }
{}

puddle::Quaternion puddle::Quaternion::from_angle_axis(float angle, const puddle::Vector3& axis) {
    float s = sin(angle / 2);
    return Quaternion(axis.x() * s, axis.y() * s, axis.z() * s, cos(angle / 2));
}

puddle::Vector3 puddle::Quaternion::euler_angles() const {
    float roll = atan2(+2.0 * (w_ * w_ + y_ * z_), +1.0 * (x_ * x_ + y_ * y_));
    float pitch = +2.0 * (w_ * y_ - z_ * x_);
    pitch = fabs(pitch) >= 1 ? copysign(M_PI / 2, pitch) : asin(pitch);
    float yaw = atan2(+2.0 * (w_ * z_ + x_ * y_), +1.0 - 2.0 * (y_ * y_ + z_ * z_));
    return puddle::Vector3(roll, pitch, yaw);
}

float puddle::Quaternion::w() const {
    return w_;
}
