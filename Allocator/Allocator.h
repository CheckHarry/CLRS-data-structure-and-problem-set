#ifndef INCLUDE_ALLOCATOR_H

#define INCLUDE_ALLOCATOR_H
#include <cstddef>
// Here is a toy model for practicing memory allocation in C++
// abstract class
class Allocator{
    public:
    Allocator(){};
    ~Allocator(){};
    virtual void* Allocate(std::size_t Size) = 0;
    virtual void Free(void *ptr) = 0;
    virtual void Reset() = 0;
};
















#endif