#ifndef PUDDLE_VECTOR2_H_
#define PUDDLE_VECTOR2_H_

namespace puddle {
class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    float x() const;
    float y() const;

    Vector2& x(float x);
    Vector2& y(float y);

    Vector2& set(float x, float y);
protected:
    float x_;
    float y_;
};
}

#endif