#include "mesh.h"

#include <iostream>
#include "../glad/glad.h"
#include <GLFW/glfw3.h>

Mesh::Mesh(float* vertices, int length) {

    // Create a VAO.
    glGenVertexArrays(1, &vertex_array);
    glBindVertexArray(vertex_array);

    // Create a VBO.
    glGenBuffers(1, &vertex_buffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
    glBufferData(GL_ARRAY_BUFFER, length, vertices, GL_STATIC_DRAW);
}

Mesh::~Mesh() {
}
