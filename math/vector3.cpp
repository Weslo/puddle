#include "vector3.h"

math::Vector3::Vector3() : glm::vec3(0.0f, 0.0f, 0.0f) {
}

math::Vector3::Vector3(float x, float y, float z) : glm::vec3(x, y, z) {
}