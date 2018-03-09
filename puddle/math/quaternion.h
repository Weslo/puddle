#ifndef PUDDLE_QUATERNION_H_
#define PUDDLE_QUATERNION_H_

namespace puddle {
class Vector3;
class Quaternion {
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

    float x() const;
    float y() const;
    float z() const;
    float w() const;

private:
    float x_ { 0 };
    float y_ { 0 };
    float z_ { 0 };
    float w_ { 0 };
};
}

#endif
