#ifndef PUDDLE_VECTOR3_H_
#define PUDDLE_VECTOR3_H_

namespace puddle {
class Vector3 {
public:
    Vector3();
    Vector3(float x, float y, float z);

    bool operator==(const Vector3& other) const;
    bool operator!=(const Vector3& other) const;

    float& x();
    float x() const;

    float& y();
    float y() const;

    float& z();
    float z() const;

    Vector3& set(float x, float y, float z);
private:
    float x_ { 0 };
    float y_ { 0 };
    float z_ { 0 };
};
}

#endif
