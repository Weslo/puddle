#include "../math/vector2.h";

namespace input {
class Mouse {
public:

    static const math::Vector2& screen_pos();
    static void screen_pos(float x, float y);

private:

    Mouse();
    Mouse(const Mouse&) = delete;
    Mouse& operator=(const Mouse&) = delete;

    static Mouse& instance();

    math::Vector2 screen_pos_;
};
}
