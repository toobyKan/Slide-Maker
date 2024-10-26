#ifndef CONTAINER_HPP
#define CONTAINER_HPP

#include <vector>
#include <memory>

namespace doc {
    template <class T>
    class Container {
    public:
        int add(std::shared_ptr<T> item);
        void insert(std::shared_ptr<T> item, size_t idx);
        void remove(size_t idx);
        std::shared_ptr<T> getAt(size_t idx) const;
        size_t getCount() const;

        using Iterator = typename std::vector<std::shared_ptr<T>>::iterator;
        Iterator begin() { return children_.begin(); }
        Iterator end() { return children_.end(); }

    protected:
        std::vector<std::shared_ptr<T>> children_;
    };
}

#endif