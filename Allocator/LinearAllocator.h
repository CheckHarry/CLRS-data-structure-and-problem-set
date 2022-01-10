#ifndef INCLUDE_LINEARALLOCATOR_H

#define INCLUDE_LINEARALLOCATOR_H

#include "Allocator.h"

class LinearAllocator : public Allocator{
    private:
        void* ResourceBlock;
        void* CurrentPtr;
        std::size_t size;
        std::size_t cur_size = 0;
    public:
    LinearAllocator(std::size_t size);
    virtual ~LinearAllocator();
    virtual void* Allocate(std::size_t Size) override;
    virtual void Free(void *ptr) override;
    virtual void Reset() override;
};





#endif