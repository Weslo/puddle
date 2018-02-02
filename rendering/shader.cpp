#include <stdio.h>
#include "shader.h"
#include "../utils/fileio.h"

// Create a shader given vertex and fragment shaders.
rendering::Shader::Shader(const char* vertex_shader_path, const char* fragment_shader_path) {

    // Compile both shaders.
    int vertex_shader_id = Compile(vertex_shader_path, GL_VERTEX_SHADER);
    int fragment_shader_id = Compile(fragment_shader_path, GL_FRAGMENT_SHADER);

    // Create and link the shader program.
    program_id_ = glCreateProgram();
    glAttachShader(program_id_, vertex_shader_id);
    glAttachShader(program_id_, fragment_shader_id);
    glLinkProgram(program_id_);

    // Check the status of the linked program.
    int success;
    char info_log[512];
    glGetProgramiv(program_id_, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program_id_, 512, NULL, info_log);
        fprintf(stderr, "Error linking shader program %i: %s\n", program_id_, info_log);
    }

    // Delete the loose shaders.
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

// Use this shader for rendering.
void rendering::Shader::Use() {
    glUseProgram(program_id_);
}

// Set an integer uniform in the shader.
void rendering::Shader::SetInt(const char* name, int value) {
    glUniform1i(glGetUniformLocation(program_id_, name), value);
}

// Compile a shader and return its ID.
unsigned int rendering::Shader::Compile(const char* filepath, GLuint shader_type) {
    
    // Parse the file before we start allocating the shader.
    char* file_content;
    unsigned long file_length;
    int parse_result = utils::ParseFile(filepath, &file_content, &file_length);
    if(parse_result < 0) {
        fprintf(stderr, "Error parsing shader at %s\n", filepath);
    }

    // Compile the shader.
    unsigned int shader_id = glCreateShader(shader_type);
    glShaderSource(shader_id, 1, &file_content, NULL);
    glCompileShader(shader_id);

    // Check the status of the compiled shader.
    int success;
    char info_log[512];
    glGetShaderiv(shader_id, GL_COMPILE_STATUS, &success);
    if(!success) {
        glGetShaderInfoLog(shader_id, 512, NULL, info_log);
        fprintf(stderr, "Error compiling shader at %s: %s\n", filepath, info_log);
    }

    return shader_id;
}