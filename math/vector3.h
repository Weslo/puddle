#ifndef MATH_VECTOR3_H_
#define MATH_VECTOR3_H_

#include "glm/vec3.hpp"

namespace math {
class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);

    float x() const;
    float y() const;
    float z() const;

    Vector3& x(float x);
    Vector3& y(float y);
    Vector3& z(float z);

    Vector3& set(float x, float y, float z);
private:
    float x_;
    float y_;
    float z_;
};
}

#endif
