#include <stdlib.h>
#include <stdio.h>
#include <GLFW/glfw3.h>

// Create a static array of verts for our test triangle.
static const GLfloat triangle_verts[] = {
    -1.0f, -1.0f, 0.0f,
    1.0f, -1.0f, 0.0f,
    0.0f, 1.0f, 0.0f
};

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

    // Create the window.
    GLFWwindow * window = glfwCreateWindow(640, 480, "OpenGL Engine", NULL, NULL);
    if(!window) {
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    // Initialize the OpenGL context.
    glfwMakeContextCurrent(window);

    // Do work while the window is open.
    while(!glfwWindowShouldClose(window)) {

        // Size and clear the viewport.
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);

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
