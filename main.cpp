#define GLFW_INCLUDE_GLCOREARB

#include <stdlib.h>
#include <stdio.h>
#include "glad/glad.h"
#include <GLFW/glfw3.h>
#include "engine/camera.h"
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
    glfwWindowHint (GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint (GLFW_CONTEXT_VERSION_MINOR, 2);
    glfwWindowHint (GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
    glfwWindowHint (GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
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

    // Enable z-buffer.
    glEnable(GL_DEPTH_TEST);

    // Create a camera.
    Camera camera = Camera();

    // Create a texture.
    Texture texture = Texture("../assets/checkermap.png");

    // Create a quad mesh.
    float vertices[] = {
        // positions            // tex coords
        0.5f,  0.5f, 0.0f,      1.0f, 1.0f,
        0.5f, -0.5f, 0.0f,      1.0f, 0.0f,
        -0.5f, -0.5f, 0.0f,     0.0f, 0.0f,
        -0.5f,  0.5f, 0.0f,     0.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 3,   // first triangle
        1, 2, 3    // second triangle
    };
    Mesh mesh = Mesh(vertices, sizeof(vertices), indices, sizeof(indices));

    // Create a shader and use it.
    Shader shader = Shader("../assets/diffuse.vert", "../assets/diffuse.frag");
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

        // Draw the triangle.
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

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
