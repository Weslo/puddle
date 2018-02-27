#ifndef PUDDLE_VECTOR3_H_
#define PUDDLE_VECTOR3_H_

#include "vector2.h"

namespace puddle {
class Vector3 : public Vector2 {
public:
    Vector3();
    Vector3(float x, float y, float z);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    float z() const;
    Vector3& z(float z);

    Vector3& set(float x, float y, float z);
private:
    float z_ { 0 };
};
}

#endif
