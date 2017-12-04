#include "../utils/fileio.h"
#include "shader.h"
#include <stdio.h>

// Create a shader given vertex and fragment shaders.
Shader::Shader(const char* vertex_shader_path, const char* fragment_shader_path) {

    // Compile both shaders.
    int vertex_shader_id = Compile(vertex_shader_path, GL_VERTEX_SHADER);
    int fragment_shader_id = Compile(fragment_shader_path, GL_FRAGMENT_SHADER);

    // Create and link the shader program.
    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader_id);
    glAttachShader(program_id, fragment_shader_id);
    glLinkProgram(program_id);

    // Check the status of the linked program.
    int success;
    char info_log[512];
    glGetProgramiv(program_id, GL_LINK_STATUS, &success);
    if(!success) {
        glGetProgramInfoLog(program_id, 512, NULL, info_log);
        fprintf(stderr, "Error linking shader prograg %i: %s\n", program_id, info_log);
    }

    // Delete the loose shaders.
    glDeleteShader(vertex_shader_id);
    glDeleteShader(fragment_shader_id);
}

// Use this shader for rendering.
void Shader::Use() {
    glUseProgram(program_id);
}

// Compile a shader and return its ID.
unsigned int Shader::Compile(const char* filepath, GLuint shader_type) {
    
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