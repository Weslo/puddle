#ifndef MATH_VECTOR3_H_
#define MATH_VECTOR3_H_

#include "glm/vec3.hpp"

namespace math {
class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);

    float get_x() const;
    float get_y() const;
    float get_z() const;

    Vector3& set_x(float x);
    Vector3& set_y(float y);
    Vector3& set_z(float z);

    Vector3& set(float x, float y, float z);
private:
    float x_;
    float y_;
    float z_;
};
} // namespace math

#endif // MATH_VECTOR3_H_
