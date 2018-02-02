#ifndef TEXTURE_H_
#define TEXTURE_H_

namespace rendering {
class Texture {
public:
    Texture(const char* img_path);
private:
    unsigned int texture_id_;
    int width_;
    int height_;
};
}

#endif