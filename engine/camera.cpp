#include "camera.h"

engine::Camera::Camera() : engine::GameObject() {
    position = math::Vector3(0.0f, 0.0f, -3.0f);
}
