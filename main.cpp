#define GLFW_INCLUDE_GLCOREARB

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include "math/glm/gtx/quaternion.hpp"
#include "math/quaternion.h"
#include "math/vector3.h"
#include "engine/camera.h"
#include "input/mouse.h"
#include "rendering/mesh.h"
#include "rendering/shader.h"
#include "rendering/texture.h"

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
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    // Enable z-buffer.
    glEnable(GL_DEPTH_TEST);

    // Create a camera.
    auto camera = puddle::Camera();

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

    // Create a model matrix for the cube.
    glm::mat4x4 model;

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
        camera.aspect_ratio(width / height);

        // Update cursor input.
        double screen_x, screen_y;
        glfwGetCursorPos(window, &screen_x, &screen_y);
        puddle::input::Mouse::screen_pos(screen_x, screen_y);

        // Update WASD input.
        float camera_speed = 0.01f;
        if(glfwGetKey(window, GLFW_KEY_A)) {
            camera.position().x(camera.position().x() + camera_speed * glfwGetTime());
        }
        if(glfwGetKey(window, GLFW_KEY_D)) {
            camera.position().x(camera.position().x() - camera_speed * glfwGetTime());
        }
        if(glfwGetKey(window, GLFW_KEY_W)) {
            camera.position().z(camera.position().z() + camera_speed * glfwGetTime());
        }
        if(glfwGetKey(window, GLFW_KEY_S)) {
            camera.position().z(camera.position().z() - camera_speed * glfwGetTime());
        }

        // Rotate the cube.
        puddle::Quaternion rot = puddle::Quaternion::from_angle_axis(2.0f * M_PI * (90.0f / 360.0f), puddle::Vector3(0, 1, 0));
        model = glm::toMat4(glm::quat(rot.x(), rot.y(), rot.z(), rot.w()));
        shader.SetMatrix4x4("model", model);
        shader.SetMatrix4x4("view", camera.view());
        shader.SetMatrix4x4("projection", camera.projection());

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
