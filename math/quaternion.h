#ifndef MATH_QUATERNION_H_
#define MATH_QUATERNION_H_

#include "glm/gtc/quaternion.hpp"

namespace math {
class Quaternion : public glm::quat {
public:
    Quaternion(float pitch, float yaw, float roll);
};
} // namespace math

#endif // MATH_QUATERNION_H_