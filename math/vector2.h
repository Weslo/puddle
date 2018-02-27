#ifndef PUDDLE_VECTOR2_H_
#define PUDDLE_VECTOR2_H_

namespace puddle {
class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    float x() const;
    float y() const;

    Vector2& x(float x);
    Vector2& y(float y);

    Vector2& set(float x, float y);
private:
    float x_ { 0 };
    float y_ { 0 };
};
}

#endif
