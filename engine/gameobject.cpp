#include "gameobject.h"

puddle::GameObject::GameObject() {
}

puddle::GameObject::~GameObject() {
}

puddle::Vector3& puddle::GameObject::position() {
    return position_;
}

puddle::Quaternion& puddle::GameObject::rotation() {
    return rotation_;
}
