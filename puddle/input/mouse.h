#ifndef PUDDLE_INPUT_MOUSE_H_
#define PUDDLE_INPUT_MOUSE_H_

#include "../math/vector2.h"

namespace puddle {
namespace input {
class Mouse {
public:

    static const puddle::Vector2& screen_pos();
    static const puddle::Vector2& delta_screen_pos();
    static void screen_pos(float x, float y);

private:

    Mouse();
    Mouse(const Mouse&) = delete;
    Mouse& operator=(const Mouse&) = delete;

    static Mouse& instance();

    puddle::Vector2 screen_pos_;
    puddle::Vector2 delta_screen_pos_;
};
}
}

#endif
