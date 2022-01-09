#ifndef INCLUDE_CLASSICALLOCATOR_H

#define INCLUDE_CLASSICALLOCATOR_H


#include "Allocator.h"

class ClassicAllocator : public Allocator{
    public:
    ClassicAllocator();
    virtual ~ClassicAllocator();
    virtual void* Allocate(std::size_t Size) override;
    virtual void Free(void *ptr) override;
    virtual void Reset() override;
};







#endif