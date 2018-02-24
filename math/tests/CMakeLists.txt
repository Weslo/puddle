include_directories("${PROJECT_SOURCE_DIR}/acutest")
include_directories("${PROJECT_SOURCE_DIR}/math")

add_executable(quaternion-tests
    ../vector2.cpp
    ../vector3.cpp
    ../quaternion.cpp
    quaternion-tests.cpp
    ../../acutest/acutest.h)
