#include "camera.h"

float puddle::Camera::aspect_ratio() const {
    return aspect_ratio_;
}

void puddle::Camera::aspect_ratio(float aspect_ratio) {
    aspect_ratio_ = aspect_ratio;
    projection_ = glm::perspective(glm::radians(45.0f), aspect_ratio_, 0.1f, 100.0f);
}

glm::mat4x4 puddle::Camera::view() const {
    return glm::translate(view_, glm::vec3(gameobject()->position().x(), gameobject()->position().y(), gameobject()->position().z()));
}

glm::mat4x4 puddle::Camera::projection() const {
    return projection_;
}
