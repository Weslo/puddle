#ifndef PUDDLE_COMPONENT_H_
#define PUDDLE_COMPONENT_H_

namespace puddle {
class GameObject;
class Component {
    friend class GameObject;
public:
    virtual ~Component();

    Component(const Component& other);
    Component& operator=(const Component& other);

    GameObject* const gameobject() const;
private:
    Component(GameObject* gameobject);

    GameObject* gameobject_;
};
}

#endif
