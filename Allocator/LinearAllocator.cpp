#include "LinearAllocator.h"
#include <stdlib.h>
#include <exception>
#include <iostream>

// Initial a large block of memory and manage it .

LinearAllocator::LinearAllocator(std::size_t Size){
    ResourceBlock = malloc(Size);
    size = Size;
};



LinearAllocator::~LinearAllocator(){

};

void* LinearAllocator::Allocate(std::size_t Size){
    int previous_size = cur_size;
    cur_size += Size ;
    if (cur_size > size) throw ("bad Allocation");
    char* to_return = (char*) ResourceBlock;
    return to_return + previous_size;
};

void LinearAllocator::Free(void *ptr) {
    throw ("Please use Reset.");
};

void LinearAllocator::Reset(){
    free(ResourceBlock);
    cur_size = 0;
}