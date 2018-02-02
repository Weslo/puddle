#ifndef GAMEOBJECT_H_
#define GAMEOBJECT_H_

#include "../math/vector3.h"

// An object that exists in a game scene.
namespace engine {
class GameObject {
public:
    GameObject();
    virtual ~GameObject();
protected:
    math::Vector3 position;
    math::Vector3 rotation;
};
}

#endif