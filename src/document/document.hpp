#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <vector>
#include <memory>

#include "slide.hpp"
#include "container.hpp"

namespace doc {
    class Document : public Container<Slide> {
        public:
            using SlideIterator = std::vector<std::shared_ptr<Slide>>::iterator;

            Document();
    };

}

#endif