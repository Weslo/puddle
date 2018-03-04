#include "gameobject.h"

puddle::GameObject::GameObject() {
}

puddle::GameObject::~GameObject() {
}

puddle::Vector3 puddle::GameObject::position() const {
    return position_;
}

puddle::GameObject& puddle::GameObject::position(const puddle::Vector3& position) {
    position_ = position;
    return *this;
}

puddle::Quaternion puddle::GameObject::rotation() const {
    return rotation_;
}

puddle::GameObject& puddle::GameObject::rotation(const puddle::Quaternion& rotation) {
    rotation_ = rotation;
    return *this;
}
