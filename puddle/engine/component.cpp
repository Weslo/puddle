#include "component.h"

puddle::Component::Component(GameObject* gameobject)
    : gameobject_ { gameobject }
{}

puddle::Component::~Component() {
}

puddle::Component::Component(const puddle::Component& other)
    : puddle::Component(other.gameobject_)
{}

puddle::Component& puddle::Component::operator=(const puddle::Component& other) {
    gameobject_ = other.gameobject_;
    return *this;
}

puddle::GameObject* const puddle::Component::gameobject() const {
    return gameobject_;
}
