#ifndef CONTAINER_HPP
#define CONTAINER_HPP

namespace doc{
   template <class T>
    class Container {
            int add(std::shared_ptr<T> slidePtr);
            void insert(std::shared_ptr<T> slidePtr, size_t idx);
            void remove(size_t idx);
            std::shared_ptr<T> getAt(size_t idx) const;
            size_t getCount() const;
            Iterator begin();
            Iterator end();
        protected:
            std::vector<std::shared_ptr<T> > children_;
    };
}

#endif