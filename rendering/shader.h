#ifndef RENDERING_SHADER_H_
#define RENDERING_SHADER_H_

#include <GLFW/glfw3.h>

// Virtual interface for a GLSL shader.
class Shader {
public:
    Shader(const char* vertex_shader_path, const char* fragment_shader_path);
    void Use();
private:
    unsigned int program_id;
    unsigned int Compile(const char* filepath, GLuint shaderType);
};

#endif // RENDERING_SHADER_H_