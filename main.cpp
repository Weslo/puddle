#define GLFW_INCLUDE_GLCOREARB

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "glm/gtx/quaternion.hpp"
#include "puddle.h"

// Handle a GLFW error.
void HandleGlfwError(int error, const char* description) {
    fprintf(stderr, "GLFW error: %s\n", description);
}

// Entry point.
int main(int argc, char** argv) {

    // Initialize GLFW.
    glfwSetErrorCallback(HandleGlfwError);
    if(!glfwInit()) {
        exit(EXIT_FAILURE);
    }

    // Configure context for OSX.
#ifdef __APPLE__
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#endif

    // Create the window.
    GLFWwindow * window = glfwCreateWindow(640, 480, "OpenGL Engine", NULL, NULL);
    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Initialize the OpenGL context.
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);

    // Lock cursor to screen.
    // glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Enable z-buffer.
    glEnable(GL_DEPTH_TEST);

    // Create a camera.
    auto camera = (new puddle::GameObject)->add_component<puddle::Camera>();
    camera->gameobject()->position() = puddle::Vector3(0, 0, -3.0f);

    // Create a game object for the cube.
    auto cube = puddle::GameObject();

    // Create a texture.
    auto texture = puddle::Texture("../assets/checkermap.png");

    // Create a cube mesh.
    float cube_verts[] = {
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 0.0f,

        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,

        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,

        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,
         0.5f, -0.5f, -0.5f,  1.0f, 1.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
         0.5f, -0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f, -0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f, -0.5f, -0.5f,  0.0f, 1.0f,

        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f,
         0.5f,  0.5f, -0.5f,  1.0f, 1.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
         0.5f,  0.5f,  0.5f,  1.0f, 0.0f,
        -0.5f,  0.5f,  0.5f,  0.0f, 0.0f,
        -0.5f,  0.5f, -0.5f,  0.0f, 1.0f
    };
    auto mesh = puddle::Mesh(cube_verts, sizeof(cube_verts));

    // Create a shader and use it.
    auto shader = puddle::Shader("../assets/diffuse.vert", "../assets/diffuse.frag");
    shader.Use();
    shader.SetInt("u_texture", 0);

    // Do work while the window is open.
    while(!glfwWindowShouldClose(window)) {

        // Size and clear the viewport.
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        camera->aspect_ratio(width / height);

        // Update cursor input.
        double screen_x, screen_y;
        glfwGetCursorPos(window, &screen_x, &screen_y);
        puddle::input::Mouse::screen_pos(screen_x, screen_y);

        // Update WASD input.
        float camera_speed = 0.01f * glfwGetTime();
        puddle::Vector3 camera_pos = camera->gameobject()->position();
        if(glfwGetKey(window, GLFW_KEY_A)) {
            camera->gameobject()->position() += puddle::Vector3::right() * camera_speed;
        }
        if(glfwGetKey(window, GLFW_KEY_D)) {
            camera->gameobject()->position() += puddle::Vector3::left() * camera_speed;
        }
        if(glfwGetKey(window, GLFW_KEY_W)) {
            camera->gameobject()->position() += puddle::Vector3::forward() * camera_speed;
        }
        if(glfwGetKey(window, GLFW_KEY_S)) {
            camera->gameobject()->position() += puddle::Vector3::back() * camera_speed;
        }

        cube.rotation() = puddle::Quaternion(puddle::math::degrees_to_radians(glfwGetTime() * 10), puddle::Vector3(0, 1, 0));

        // Calculate cube rotation.
        glm::mat4x4 rotation = glm::toMat4(glm::quat(cube.rotation().w(), cube.rotation().x(), cube.rotation().y(), cube.rotation().z()));

        // Apply matrix transformations to cube.
        glm::mat4x4 model;
        glm::translate(model, glm::vec3(cube.position().x(), cube.position().y(), cube.position().z()));
        model *= rotation;
        shader.SetMatrix4x4("model", model);
        shader.SetMatrix4x4("view", camera->view());
        shader.SetMatrix4x4("projection", camera->projection());

        // Draw the cube.
        glDrawArrays(GL_TRIANGLES, 0, 36);

        // Prepare next frame.
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Free the window context.
    glfwDestroyWindow(window);

    // Exit process.
    glfwTerminate();
    exit(EXIT_SUCCESS);
}
