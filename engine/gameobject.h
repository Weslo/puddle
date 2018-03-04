#ifndef PUDDLE_GAMEOBJECT_H_
#define PUDDLE_GAMEOBJECT_H_

#include "../math/vector3.h"
#include "../math/quaternion.h"

// An object that exists in a game scene.
namespace puddle {
class GameObject {
public:
    GameObject();
    virtual ~GameObject();

    puddle::Vector3 position() const;
    puddle::GameObject& position(const Vector3& position);

    puddle::Quaternion rotation() const;
    puddle::GameObject& rotation(const Quaternion& quaternion);
private:
    puddle::Vector3 position_;
    puddle::Quaternion rotation_;
};
}

#endif
