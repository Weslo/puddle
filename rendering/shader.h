#ifndef PUDDLE_SHADER_H_
#define PUDDLE_SHADER_H_

#include "GLFW/glfw3.h"
#include "../math/glm/mat4x4.hpp"
#include "../math/glm/gtc/type_ptr.hpp"

// Virtual interface for a GLSL shader.
namespace puddle {
class Shader {
public:
    Shader(const char* vertex_shader_path, const char* fragment_shader_path);
    void Use();
    void SetInt(const char* name, int value);
    void SetMatrix4x4(const char* name, glm::mat4x4 matrix);
private:
    unsigned int program_id_;
    unsigned int Compile(const char* filepath, GLuint shaderType);
};
}

#endif
