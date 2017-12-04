#ifndef RENDERING_MESH_H_
#define RENDERING_MESH_H_

class Mesh {
public:
    Mesh(float* vertices);
    ~Mesh();
private:
    unsigned int vertex_array;
    unsigned int vertex_buffer;
};

#endif