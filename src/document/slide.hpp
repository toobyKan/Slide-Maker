#ifndef SLIDE_HPP
#define SLIDE_HPP

#include <vector>
#include <memory>
#include "../graphics/shapes/shape.hpp"
#include "container.hpp"

namespace doc {
    class Slide : public Container<Shape> {
    public:
        Slide();
    };
}

#endif
