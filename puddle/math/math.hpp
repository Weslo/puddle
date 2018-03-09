#ifndef PUDDLE_MATH_MATH_HPP_
#define PUDDLE_MATH_MATH_HPP_

#include <math.h>

namespace puddle {
namespace math {

    // Return radians to degrees conversion.
    inline float radians_to_degrees(float radians) {
        return radians * 180 / M_PI;
    }

    // Return degrees to radians conversion.
    inline float degrees_to_radians(float degrees) {
        return degrees * M_PI / 180;
    }
}
}

#endif
