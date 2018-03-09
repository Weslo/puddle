#ifndef PUDDLE_TEXTURE_H_
#define PUDDLE_TEXTURE_H_

namespace puddle {
class Texture {
public:
    Texture(const char* img_path);
    ~Texture();
private:
    unsigned int texture_id_;
    int width_;
    int height_;
};
}

#endif
