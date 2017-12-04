#ifndef VECTOR3_H_
#define VECTOR3_H_

#include "glm/vec3.hpp"

namespace math {
class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);
private:
    void Initialize(float x, float y, float z);
    glm::vec3 glm_vec;
};
} // namespace math

#endif