#include "gameobject.h"

puddle::GameObject::GameObject() {
}

puddle::GameObject::~GameObject() {
}

puddle::Vector3& puddle::GameObject::position() {
    return position_;
}
