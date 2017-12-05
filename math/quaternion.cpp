#include "quaternion.h"

math::Quaternion::Quaternion(float pitch, float yaw, float roll) {
    quaternion_ = glm::quat(glm::vec3(pitch, yaw, roll));
}