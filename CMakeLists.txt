cmake_minimum_required(VERSION 2.6)
project(opengl-play)

if(APPLE)
    include_directories(/Developer/Headers/FlatCarbon)
    find_library(COREVID_LIB, CoreVideo)
    find_library(OPENGL_LIB OpenGL)
    find_library(IOKIT_LIB IOKit)
    find_library(COCOA_LIB Cocoa)
    find_library(CARBON_LIB Carbon)

    mark_as_advanced(
        COREVID_LIB
        OPENGL_LIB
        IOKIT_LIB
        COCOA_LIB
        CARBON_LIB
    )

    set(LIBS ${COREVID_LIB} ${OPENGL_LIB} ${IOKIT_LIB} ${COCOA_LIB} ${CARBON_LIB})
    set(CMAKE_CXX_COMPILER "clang++")
    set(CMAKE_CXX_STANDARD 14)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lglfw")
endif(APPLE)

add_subdirectory(${PROJECT_SOURCE_DIR}/glm)

include_directories(
    ${PROJECT_SOURCE_DIR}/glad
    ${PROJECT_SOURCE_DIR}/glad/KHR
    ${PROJECT_SOURCE_DIR}/puddle
    ${PROJECT_SOURCE_DIR}/puddle/engine
    ${PROJECT_SOURCE_DIR}/puddle/input
    ${PROJECT_SOURCE_DIR}/puddle/math
    ${PROJECT_SOURCE_DIR}/puddle/rendering
    ${PROJECT_SOURCE_DIR}/puddle/utils)

file(GLOB ENGINE_SRC ./puddle/engine/*.cpp)
file(GLOB INPUT_SRC ./puddle/input/*.cpp)
file(GLOB MATH_SRC ./puddle/math/*.cpp)
file(GLOB RENDERING_SRC ./puddle/rendering/*.cpp)
file(GLOB UTILS_SRC ./puddle/utils/*.cpp)

add_executable(opengl-play
    main.cpp
    glad/glad.c
    ${ENGINE_SRC}
    ${INPUT_SRC}
    ${MATH_SRC}
    ${RENDERING_SRC}
    ${UTILS_SRC})

target_link_libraries(opengl-play ${LIBS})

# Include tests
add_subdirectory(${PROJECT_SOURCE_DIR}/puddle/math/tests)
