#include "ClassicAllocator.h"
#include <stdlib.h>


ClassicAllocator::ClassicAllocator(){

}

ClassicAllocator::~ClassicAllocator(){
    
}


void* ClassicAllocator::Allocate(std::size_t size){
    return malloc(size);
}


void ClassicAllocator::Free(void* ptr){
    free(ptr);
}

void ClassicAllocator::Reset(){
    // Classic : not thing to do;
}