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
    puddle::Quaternion normal = not_normal.normalized();

    TEST_CHECK(compare_float(not_normal.x(), 14, epsilon));

    TEST_CHECK(compare_float(normal.x(), 0.513, epsilon));
    TEST_CHECK(compare_float(normal.y(), 0.403, epsilon));
    TEST_CHECK(compare_float(normal.z(), 0.754, epsilon));
    TEST_CHECK(compare_float(normal.w(), 0.146, epsilon));
}

TEST_LIST = {
    { "euler to quat", test_euler_to_quat },
    { "normalization", test_quat_normalize }
};
