#include "camera.h"

engine::Camera::Camera() : engine::GameObject() {
    position_.set(0.0f, 0.0f, -3.0f);
}

engine::Camera::~Camera() {

}
