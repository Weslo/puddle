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
    set(CMAKE_CXX_STANDARD 11)
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -stdlib=libc++ -lglfw")
endif(APPLE)

add_subdirectory(${PROJECT_SOURCE_DIR}/math/glm)

include_directories(
    ${PROJECT_SOURCE_DIR}/engine
    ${PROJECT_SOURCE_DIR}/glad
    ${PROJECT_SOURCE_DIR}/glad/KHR
    ${PROJECT_SOURCE_DIR}/input
    ${PROJECT_SOURCE_DIR}/math
    ${PROJECT_SOURCE_DIR}/rendering
    ${PROJECT_SOURCE_DIR}/utils)

file(GLOB ENGINE_SRC ./engine/*.cpp)
file(GLOB INPUT_SRC ./input/*.cpp)
file(GLOB MATH_SRC ./math/*.cpp)
file(GLOB RENDERING_SRC ./rendering/*.cpp)
file(GLOB UTILS_SRC ./utils/*.cpp)

add_executable(opengl-play
    main.cpp
    glad/glad.c
    ${ENGINE_SRC}
    ${INPUT_SRC}
    ${MATH_SRC}
    ${RENDERING_SRC}
    ${UTILS_SRC})

target_link_libraries(opengl-play ${LIBS})
