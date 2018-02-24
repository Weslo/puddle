#ifndef PUDDLE_QUATERNION_H_
#define PUDDLE_QUATERNION_H_

#include "vector3.h"

namespace puddle {
class Quaternion : public Vector3 {
public:
    Quaternion();
    Quaternion(float x, float y, float z, float w);

    static Quaternion from_angle_axis(float angle, const Vector3& axis);
    static Quaternion from_euler_angles(float x, float y, float z);

    Vector3 euler_angles() const;

    float w() const;

protected:
    float w_ { 0 };
};
}

#endif
