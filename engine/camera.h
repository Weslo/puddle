#ifndef CAMERA_H_
#define CAMERA_H_

#include "gameobject.h"
#include "../math/glm/vec3.hpp"
#include "../math/glm/mat4x4.hpp"

namespace engine {
class Camera : public GameObject {
public:
    Camera();
    ~Camera() override;
private:
    glm::mat4x4 model_;
    glm::mat4x4 view_;
    glm::mat4x4 projection_;
};
}

#endif
