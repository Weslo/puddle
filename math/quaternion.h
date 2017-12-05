#ifndef MATH_QUATERNION_H_
#define MATH_QUATERNION_H_

#include <glm/gtx/quaternion.hpp>
#include <glm/gtc/quaternion.hpp>

namespace math {
class Quaternion {
public:
    Quaternion(float pitch, float yaw, float roll);
    void SetEulerAngles(float pitch, float yaw, float roll);
private:
    glm::quat quaternion_;
};
} // namespace math

#endif // MATH_QUATERNION_H_