#include <math.h>
#include <memory>
#include "acutest.h"
#include "vector2.h"

bool compare_float(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void test_vector2_construct() {
    puddle::Vector2 a;
    puddle::Vector2 b(1, 2);
    puddle::Vector2 c { 3, 4 };
    auto d = std::make_unique<puddle::Vector2>(5, 6);

    TEST_CHECK(a.x() == 0);
    TEST_CHECK(b.y() == 2);
    TEST_CHECK(c.x() == 3);
    TEST_CHECK(d->y() == 6);
}

void test_vector2_equality() {
    puddle::Vector2 a(1, 2);
    puddle::Vector2 b(2, 3);

    TEST_CHECK(a != b);

    a = b;

    TEST_CHECK(b == a);
}

void test_vector2_addition() {
    puddle::Vector2 a(1, 2);
    puddle::Vector2 b = a + puddle::Vector2(3, 4);

    TEST_CHECK(b == puddle::Vector2(4, 6));

    b += puddle::Vector2(5, 6);

    TEST_CHECK(b == puddle::Vector2(9, 12));
}

void test_vector2_subtraction() {
    puddle::Vector2 a(10, 9);
    puddle::Vector2 b = a - puddle::Vector2(1, 2);

    TEST_CHECK(b == puddle::Vector2(9, 7));

    b -= puddle::Vector2(5, 6);

    TEST_CHECK(b == puddle::Vector2(4, 1));
}

void test_vector2_multiplication() {
    puddle::Vector2 vec(1, 2);

    TEST_CHECK(vec * 2 == puddle::Vector2(2, 4));
    TEST_CHECK(3 * vec == puddle::Vector2(3, 6));

    vec *= 4;

    TEST_CHECK(vec == puddle::Vector2(4, 8));
}

void test_vector2_division() {
    puddle::Vector2 vec(10, 20);

    TEST_CHECK(vec / 2 == puddle::Vector2(5, 10));

    vec /= 5;

    TEST_CHECK(vec == puddle::Vector2(2, 4));
}

TEST_LIST = {
    { "construction", test_vector2_construct },
    { "equality", test_vector2_equality },
    { "addition", test_vector2_addition },
    { "subtraction", test_vector2_subtraction },
    { "multiplication", test_vector2_multiplication },
    { "division", test_vector2_division }
};
