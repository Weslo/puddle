#ifndef ENGINE_CAMERA_H_
#define ENGINE_CAMERA_H_

#include "gameobject.h"
#include "../math/glm/vec3.hpp"
#include "../math/glm/mat4x4.hpp"
#include "../math/glm/gtc/matrix_transform.hpp"

namespace engine {
class Camera : public GameObject {
public:
    Camera();
    ~Camera() override;

    float aspect_ratio() const;
    Camera& aspect_ratio(float aspect_ratio);

    glm::mat4x4 view() const;
    glm::mat4x4 projection() const;
private:

    float aspect_ratio_;

    glm::mat4x4 view_;
    glm::mat4x4 projection_;
};
}

#endif
