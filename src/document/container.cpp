#include "container.hpp"
#include <memory>

namespace doc {

    template <class T>
    int Container<T>::add(std::shared_ptr<T> item) {
        if (!item) return -1;
        children_.push_back(item);
        return getCount() - 1;
    }

    template <class T>
    void Container<T>::insert(std::shared_ptr<T> item, size_t idx) {
        if (idx > getCount()) return;
        children_.insert(children_.begin() + idx, item);
    }

    template <class T>
    void Container<T>::remove(size_t idx) {
        if (idx < getCount()) {
            children_.erase(children_.begin() + idx);
        }
    }

    template <class T>
    std::shared_ptr<T> Container<T>::getAt(size_t idx) const {
        if (idx < getCount()) {
            return children_[idx];
        }
        return nullptr;
    }

    template <class T>
    size_t Container<T>::getCount() const {
        return children_.size();
    }
}
