include_directories("${PROJECT_SOURCE_DIR}/puddle/acutest")
include_directories("${PROJECT_SOURCE_DIR}/puddle/math")

add_executable(quaternion-tests
    ../vector2.cpp
    ../vector3.cpp
    ../quaternion.cpp
    quaternion-tests.cpp
    ../../acutest/acutest.h)

add_executable(vector2-tests
    ../vector2.cpp
    vector2-tests.cpp
    ../../acutest/acutest.h)


add_executable(vector3-tests
    ../vector3.cpp
    vector3-tests.cpp
    ../../acutest/acutest.h)
