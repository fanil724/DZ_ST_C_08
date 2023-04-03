#ifndef MY_PTR_H
#define MY_PTR_H

template<typename T>
class My_unique {
public:
    My_unique() : ptr(nullptr) {}

    My_unique(const My_unique<T> &ptr) = delete;

    My_unique(T *ptrr) {
        ptr = ptrr;
    }

    ~My_unique() {
        delete ptr;
    }

    T &operator*() {
        return *ptr;
    }

    T *get() {
        return ptr;
    }

    void reset() {
        delete ptr;
        ptr = nullptr;
    }

    void realese() {
        ptr = nullptr;
    }

    void swap(My_unique<T> &uptr) {
        std::swap(ptr, uptr.ptr);
    }

private:
    T *ptr;
};


template<typename T>
class My_shared {
public:
    My_shared() : ptr(nullptr), ptr_count(nullptr) {}

     My_shared(T *pt) {
        ptr = pt;
        ptr_count = new size_t (1);
    }
    My_shared(My_shared & ptrr) {
        ptr = ptrr.ptr;
        ptr_count = ptrr.ptr_count;
        ++(*ptr_count);
    }
    ~My_shared() {
        remove();
    }

     My_shared &operator=(My_shared<T> &ptrr) {
//        if (*ptr_count > 0) {
//            remove();
//        }

        if (this != &ptrr) {
            ptr = ptrr.ptr;
            ptr_count = ptrr.ptr_count;
            ++(*ptr_count);
        }

        return *this;
    }
    T* get() {
        return ptr;
    }
    T operator*() {
        return *ptr;
    }
    size_t use_count(){
        return *ptr_count;
    }

private:
    void remove() {
        if ((*ptr_count) > 1) {
            (*ptr_count)--;
            return;
        }
        delete ptr;
        delete ptr_count;
    }

    T *ptr;
    size_t *ptr_count;
};

#endif //MY_PTR_H