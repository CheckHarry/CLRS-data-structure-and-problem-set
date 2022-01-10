#ifndef INCLUDE_VECTOR
#define INCLUDE_VECTOR

#include "Allocator/LinearAllocator.h"



template<typename T>
class vector{
    private:
        T* raw_vector;
        std::size_t elements_no;
        std::size_t cur_element_capacity;
        LinearAllocator Memory_allocator;
    public:
        T& operator[](std::size_t No){
            if (No >= cur_element_capacity) throw("Out bound!");
            return *(raw_vector + No);
        }

        void push_back(T obj){
            *(raw_vector + elements_no) = obj;
        }
};











#endif












