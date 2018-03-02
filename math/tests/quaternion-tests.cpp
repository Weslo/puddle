#include <iostream>
#include <math.h>
#include "acutest.h"
#include "vector3.h"
#include "quaternion.h"

bool compare_float(float a, float b, float epsilon) {
    return fabs(a - b) < epsilon;
}

void test_euler_to_quat(void) {
    float epsilon { 0.01f };
    puddle::Vector3 eulers(30, 60, 40);
    puddle::Quaternion quat(eulers);
    puddle::Vector3 converted(quat.euler_angles());

    TEST_CHECK(compare_float(converted.x(), eulers.x(), epsilon));
    TEST_CHECK(compare_float(converted.y(), eulers.y(), epsilon));
    TEST_CHECK(compare_float(converted.z(), eulers.z(), epsilon));
}

void test_quat_normalize(void) {
    float epsilon { 0.01f };
    puddle::Quaternion not_normal(14, 11, 21, 4);
    puddle::Quaternion normal(not_normal.normalized());

    TEST_CHECK(compare_float(not_normal.x(), 14, epsilon));

    TEST_CHECK(compare_float(normal.x(), 0.513, epsilon));
    TEST_CHECK(compare_float(normal.y(), 0.403, epsilon));
    TEST_CHECK(compare_float(normal.z(), 0.754, epsilon));
    TEST_CHECK(compare_float(normal.w(), 0.146, epsilon));
}

void test_quat_conjugate(void) {
    float epsilon { 0.01f };
    puddle::Quaternion quat(1, 2, 3, 4);
    puddle::Quaternion conjugate(quat.conjugate());

    TEST_CHECK(compare_float(quat.x(), 1, epsilon));
    TEST_CHECK(compare_float(conjugate.x(), -1, epsilon));
    TEST_CHECK(compare_float(conjugate.w(), 4, epsilon));
}

void test_quat_scale(void) {
    float epsilon { 0.01f };
    puddle::Quaternion quat(1, 2, 3, 4);
    puddle::Quaternion scaled(quat.scale(6));

    TEST_CHECK(compare_float(quat.x(), 1, epsilon));
    TEST_CHECK(compare_float(scaled.x(), 6, epsilon));
    TEST_CHECK(compare_float(scaled.w(), 24, epsilon));
}

void test_quat_mult(void) {
    float epsilon { 0.01f };
    puddle::Quaternion a(30, 60, 40);
    puddle::Quaternion b(20, 0, 0);
    puddle::Quaternion result(a * b);
    puddle::Quaternion compare(50, 60, 40);

    TEST_CHECK(compare_float(result.x(), compare.x(), epsilon));
    TEST_CHECK(compare_float(result.y(), compare.y(), epsilon));
    TEST_CHECK(compare_float(result.z(), compare.z(), epsilon));
    TEST_CHECK(compare_float(result.w(), compare.w(), epsilon));
}

TEST_LIST = {
    { "euler to quat", test_euler_to_quat },
    { "normalization", test_quat_normalize },
    { "conjugation", test_quat_conjugate },
    { "scaling", test_quat_scale },
    { "multiplication", test_quat_mult }
};
