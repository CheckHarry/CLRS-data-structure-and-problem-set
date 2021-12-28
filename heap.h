#ifndef INCLUDE_H

#define INCLUDE_H
#include <vector>







template<typename T>
class heap{

private:
    std::vector<T> heap_vec;
    int vec_size;
public:
    heap(std::vector<T> heap_vec_to_insert);
    void print_heap();
    void heapify(int index);
    void build_heap();
    const T& get_max();
    T extract_max();
};
#endif