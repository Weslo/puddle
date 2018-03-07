#ifndef PUDDLE_VECTOR2_H_
#define PUDDLE_VECTOR2_H_

namespace puddle {
class Vector2 {
public:
    Vector2();
    Vector2(float x, float y);

    bool operator==(const Vector2& other) const;
    bool operator!=(const Vector2& other) const;

    Vector2 operator+(const Vector2& other) const;
    Vector2& operator+=(const Vector2& other);

    Vector2 operator-(const Vector2& other) const;
    Vector2& operator-=(const Vector2& other);

    Vector2 operator*(float scalar) const;
    Vector2& operator*=(float scalar);

    Vector2 operator/(float scalar) const;
    Vector2& operator/=(float scalar);

    float& x();
    float x() const;

    float& y();
    float y() const;

    Vector2& set(float x, float y);
private:
    float x_ { 0 };
    float y_ { 0 };
};

Vector2 operator*(float scalar, const Vector2& vec);
}

#endif
