#ifndef HEAP_SET_H
#define HEAP_SET_H

#include <vector>

template <typename T> class heap_set: public std::vector<T> {
public:
    heap_set(void) { size = 0; };
    void insert(T element) {  };
    void remove(T element) {  };
    virtual ~heap_set() {};
private:
    unsigned size;
};
#endif //HEAP_SET_H
