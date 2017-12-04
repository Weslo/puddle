#include "mesh.h"

#include "../glad/glad.h"
#include <GLFW/glfw3.h>

Mesh::Mesh(float* vertices) {
    
    // Create a VAO.
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    // Create a VBO.
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
}

Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vertex_array);
    glDeleteBuffers(1, &vertex_buffer);
}