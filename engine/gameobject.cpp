#include "gameobject.h"

puddle::GameObject::GameObject() {
}

puddle::GameObject::~GameObject() {
}

puddle::Vector3& puddle::GameObject::position() {
    return position_;
}

void puddle::GameObject::position(const puddle::Vector3& position) {
    position_ = position;
}

puddle::Quaternion& puddle::GameObject::rotation() {
    return rotation_;
}

void puddle::GameObject::rotation(const puddle::Quaternion& rotation) {
    rotation_ = rotation;
}
