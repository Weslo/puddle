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

TEST_LIST = {
    { "construction", test_vector2_construct },
    { "equality", test_vector2_equality },
    { "addition", test_vector2_addition }
};
