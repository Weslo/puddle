#ifndef MATH_VECTOR3_H_
#define MATH_VECTOR3_H_

#include "glm/vec3.hpp"

namespace math {
class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);
    
    void Set(float x, float y, float z);
private:
    glm::vec3 vector_;
};
} // namespace math

#endif // MATH_VECTOR3_H_