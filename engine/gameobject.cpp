#include "gameobject.h"

engine::GameObject::GameObject() {
}

engine::GameObject::~GameObject() {
}

math::Vector3& engine::GameObject::position() {
    return position_;
}
