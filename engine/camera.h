#ifndef PUDDLE_CAMERA_H_
#define PUDDLE_CAMERA_H_

#include "gameobject.h"
#include "../math/glm/vec3.hpp"
#include "../math/glm/mat4x4.hpp"
#include "../math/glm/gtc/matrix_transform.hpp"

namespace puddle {
class Camera : public Component {
    using Component::Component;
public:
    float aspect_ratio() const;
    void aspect_ratio(float aspect_ratio);

    glm::mat4x4 view() const;
    glm::mat4x4 projection() const;
private:

    float aspect_ratio_;

    glm::mat4x4 view_;
    glm::mat4x4 projection_;
};
}

#endif
