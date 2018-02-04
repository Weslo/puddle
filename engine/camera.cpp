#include "camera.h"

engine::Camera::Camera() : engine::GameObject() {
    position_.set(0.0f, 0.0f, -3.0f);
    view_ = glm::translate(view_, glm::vec3(position_.x(), position_.y(), position_.z()));
    projection_ = glm::perspective(glm::radians(45.0f), aspect_ratio_, 0.1f, 100.0f);
}

engine::Camera::~Camera() {

}

float engine::Camera::aspect_ratio() const {
    return aspect_ratio_;
}

engine::Camera& engine::Camera::aspect_ratio(float aspect_ratio) {
    aspect_ratio_ = aspect_ratio;
    return *this;
}
