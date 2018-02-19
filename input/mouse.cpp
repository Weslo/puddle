#include "mouse.h"

puddle::input::Mouse::Mouse() {

}

puddle::input::Mouse& puddle::input::Mouse::instance() {
    static Mouse instance;
    return instance;
}

const puddle::Vector2& puddle::input::Mouse::screen_pos() {
    return instance().screen_pos_;
}

const puddle::Vector2& puddle::input::Mouse::delta_screen_pos() {
    return instance().delta_screen_pos_;
}

void puddle::input::Mouse::screen_pos(float x, float y) {
    instance().delta_screen_pos_.set(
        x - instance().screen_pos_.x(),
        y - instance().screen_pos_.y()
    );
    instance().screen_pos_.set(x, y);
}
