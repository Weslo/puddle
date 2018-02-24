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

    std::cout << "{ " << eulers.x() << ", " << eulers.y() << ", " << eulers.z() << " }" << std::endl;
    std::cout << "{ " << quat.x() << ", " << quat.y() << ", " << quat.z() << ", " << quat.w() << " }" << std::endl;
    std::cout << "{ " << converted.x() << ", " << converted.y() << ", " << converted.z() << " }" << std::endl;
    TEST_CHECK(compare_float(converted.x(), eulers.x(), epsilon));
    TEST_CHECK(compare_float(converted.y(), eulers.y(), epsilon));
    TEST_CHECK(compare_float(converted.z(), eulers.z(), epsilon));
}

TEST_LIST = {
    { "test", test_euler_to_quat }
};
