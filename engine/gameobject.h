#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../math/vector3.h"

// An object that exists in a game scene.
class GameObject {
public:
    GameObject();
private:
    math::Vector3 position;
};

#endif