#include "vector3.h"

math::Vector3::Vector3() {
    Set(0.0f, 0.0f, 0.0f);
}

math::Vector3::Vector3(float x, float y, float z) {
    Set(x, y, z);
}

void math::Vector3::Set(float x, float y, float z) {
    vector_ = glm::vec3(x, y, z);
}