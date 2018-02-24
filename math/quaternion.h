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

    Vector3 euler_angles() const;

    float w() const;

protected:
    float w_ { 0 };
};
}

#endif
