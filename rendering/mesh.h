#ifndef RENDERING_MESH_H_
#define RENDERING_MESH_H_

class Mesh {
public:
    Mesh(float* vertices, unsigned int num_vertices);
    Mesh(float* vertices, unsigned int num_vertices, unsigned int* indices, unsigned int num_indices);
    ~Mesh();
private:
    unsigned int vertex_array_;
    unsigned int vertex_buffer_;
    unsigned int index_buffer_;
};

#endif
