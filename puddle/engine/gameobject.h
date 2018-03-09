#ifndef PUDDLE_GAMEOBJECT_H_
#define PUDDLE_GAMEOBJECT_H_

#include <memory>
#include <typeindex>
#include <unordered_map>
#include "component.h"
#include "../math/vector3.h"
#include "../math/quaternion.h"

// An object that exists in a game scene.
namespace puddle {
class GameObject {
public:
    GameObject();
    virtual ~GameObject();

    puddle::Vector3& position();
    puddle::Vector3 position() const;

    puddle::Quaternion& rotation();
    puddle::Quaternion rotation() const;

    template<class T>
    T* const add_component() {
        std::type_index index(typeid(T));
        std::shared_ptr<T> c { new T(this) };
        components_[index] = c;
        return static_cast<T*>(c.get());
    }

    template<class T>
    bool has_component() const {
        std::type_index index(typeid(T));
        return components_.find(index) != components_.end();
    }

    template<class T>
    T* const get_component() {
        if(has_component<T>()) {
            return static_cast<T*>(components_[std::type_index(typeid(T))].get());
        }
        else {
            return nullptr;
        }
    }

private:
    puddle::Vector3 position_;
    puddle::Quaternion rotation_;
    std::unordered_map<std::type_index, std::shared_ptr<Component>> components_;
};
}

#endif
