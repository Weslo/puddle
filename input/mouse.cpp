#include "mouse.h"

input::Mouse::Mouse() {

}

input::Mouse& input::Mouse::instance() {
    static Mouse instance;
    return instance;
}

const math::Vector2& input::Mouse::screen_pos() {
    return instance().screen_pos_;
}

void input::Mouse::screen_pos(float x, float y) {
    instance().screen_pos_.set(x, y);
}
