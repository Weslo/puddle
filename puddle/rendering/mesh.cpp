#include "mesh.h"
#include "../glad/glad.h"
#include "GLFW/glfw3.h"

puddle::Mesh::Mesh(float* vertices, unsigned int num_vertices) {

    // Create a vertex array object.
    glGenVertexArrays(1, &vertex_array_);
    glBindVertexArray(vertex_array_);

    // Create a vertex buffer object.
    glGenBuffers(1, &vertex_buffer_);
    glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer_);
    glBufferData(GL_ARRAY_BUFFER, num_vertices, vertices, GL_STATIC_DRAW);

    // Position attribute.
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), 0);
    glEnableVertexAttribArray(0);

    // Texture coordinate attribute.
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
}

puddle::Mesh::Mesh(float* vertices, unsigned int num_vertices, unsigned int* indices, unsigned int num_indices) : Mesh::Mesh(vertices, num_vertices) {

    // Create an index buffer object.
    glGenBuffers(1, &index_buffer_);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index_buffer_);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, num_indices, indices, GL_STATIC_DRAW);
}

puddle::Mesh::~Mesh() {
    glDeleteVertexArrays(1, &vertex_array_);
    glDeleteBuffers(1, &vertex_buffer_);
}
