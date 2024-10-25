#include "document.hpp"

doc::Document::Document {
    children_.push_back(std::make_shared<Slide>());
}

int Document::addSlide(std::shared_ptr<Slide> slidePtr) {
    children_.push_back(slidePtr);
}

void Document::insertSlide(std::shared_ptr<Slide> slidePtr, int idx) {
    children_.insert(children_.begin(), slidePtr);
}

void Document::removeSlide(int idx) {
    children_.erase(children_.begin() + idx);
}

std::shared_ptr<Slide> Document::getSlide(int idx) const {
    if (idx < children_.size()) {
        return children_.at(idx);
    }
    return {};
}

size_t Document::getSlideCount() const {
    return children_.size() - 1;
}

Document::SlideIterator Document::begin() {
    return children_.begin();
}

Document::SlideIterator Document::end() {
    return children_.end();
}