#ifndef PUDDLE_QUATERNION_H_
#define PUDDLE_QUATERNION_H_

#include "vector3.h"

namespace puddle {
class Quaternion : public Vector3 {
public:
    Quaternion();
    Quaternion(float x, float y, float z, float w);
    Quaternion(float angle, const Vector3& axis);
    Quaternion(float roll, float pitch, float yaw);
    Quaternion(const Vector3& eulers);

    Quaternion operator*(const Quaternion& other) const;

    Quaternion& normalize();
    Quaternion normalized() const;

    Quaternion conjugate() const;
    Quaternion scale(float s) const;
    Quaternion multiply(const Quaternion& other) const;

    Vector3 euler_angles() const;

    float w() const;
    Quaternion& w(float w);

protected:
    float w_ { 0 };
};
}

#endif
