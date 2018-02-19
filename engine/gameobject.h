#ifndef PUDDLE_GAMEOBJECT_H_
#define PUDDLE_GAMEOBJECT_H_

#include "../math/vector3.h"

// An object that exists in a game scene.
namespace puddle {
class GameObject {
public:
    GameObject();
    virtual ~GameObject();

    puddle::Vector3& position();
protected:
    puddle::Vector3 position_;
    puddle::Vector3 rotation_;
};
}

#endif
