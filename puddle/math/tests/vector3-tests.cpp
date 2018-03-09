#include <math.h>
#include <memory>
#include "acutest.h"
#include "vector3.h"

bool compare_float(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void test_vector3_construct() {
    puddle::Vector3 a;
    puddle::Vector3 b(1, 2, 3);
    puddle::Vector3 c { 4, 5, 6 };
    auto d = std::make_unique<puddle::Vector3>(7, 8, 9);

    TEST_CHECK(a.x() == 0);
    TEST_CHECK(b.y() == 2);
    TEST_CHECK(c.z() == 6);
    TEST_CHECK(d->x() == 7);
}

void test_vector3_equality() {
    puddle::Vector3 a(1, 2, 3);
    puddle::Vector3 b(4, 5, 6);

    TEST_CHECK(a != b);

    a = b;

    TEST_CHECK(b == a);
}

void test_vector3_addition() {
    puddle::Vector3 a(1, 2, 3);
    puddle::Vector3 b = a + puddle::Vector3(4, 5, 6);

    TEST_CHECK(b == puddle::Vector3(5, 7, 9));

    b += puddle::Vector3(7, 8, 9);

    TEST_CHECK(b == puddle::Vector3(12, 15, 18));
}

void test_vector3_subtraction() {
    puddle::Vector3 a(10, 9, 8);
    puddle::Vector3 b = a - puddle::Vector3(1, 2, 3);

    TEST_CHECK(b == puddle::Vector3(9, 7, 5));

    b -= puddle::Vector3(4, 5, 6);

    TEST_CHECK(b == puddle::Vector3(5, 2, -1));
}

void test_vector3_multiplication() {
    puddle::Vector3 vec(1, 2, 3);

    TEST_CHECK(vec * 2 == puddle::Vector3(2, 4, 6));
    TEST_CHECK(3 * vec == puddle::Vector3(3, 6, 9));

    vec *= 4;

    TEST_CHECK(vec == puddle::Vector3(4, 8, 12));
}

void test_vector3_division() {
    puddle::Vector3 vec(10, 20, 30);

    TEST_CHECK(vec / 2 == puddle::Vector3(5, 10, 15));

    vec /= 5;

    TEST_CHECK(vec == puddle::Vector3(2, 4, 6));
}

TEST_LIST = {
    { "construction", test_vector3_construct },
    { "equality", test_vector3_equality },
    { "addition", test_vector3_addition },
    { "subtraction", test_vector3_subtraction },
    { "multiplication", test_vector3_multiplication },
    { "division", test_vector3_division }
};
