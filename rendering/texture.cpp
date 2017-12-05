#define STB_IMAGE_IMPLEMENTATION
#include "../glad/glad.h"
#include <GLFW/glfw3.h>
#include "../utils/stb_image.h"

#include "texture.h"

Texture::Texture(const char* img_path) {

    // Load the texture from the file.
    int numChannels;
    unsigned char* data = stbi_load(img_path, &width_, &height_, &numChannels, 0);
    if(data) {

        // Generate the texture.
        glGenTextures(1, &texture_id_);
        glBindTexture(GL_TEXTURE_2D, texture_id_);

        // Set texture wrap options.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

        // Set filtering options.
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

        // Fill texture data.
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width_, height_, 0, GL_RGB, GL_UNSIGNED_BYTE, data);

        // Create mipmaps.
        glGenerateMipmap(GL_TEXTURE_2D);

        // Free load data.
        stbi_image_free(data);
    }
    else {
        fprintf(stderr, "Error loading texture at: %s\n", img_path);
    }
}