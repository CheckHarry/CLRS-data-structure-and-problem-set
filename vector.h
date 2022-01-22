#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include "Allocator/LinearAllocator.h"
#include <stdlib.h>
#include <iostream>

template<typename T>
class vector{
    private:
        T* raw_vector;
        std::size_t cur_element_capacity;
        std::size_t reserved_capacity;
    public:
        vector(){ 
            raw_vector = (T*) malloc( sizeof(T));
            cur_element_capacity = 0;
            reserved_capacity = 1;
        }
        vector(int size){
            raw_vector = (T*) malloc(size * sizeof(T));
            cur_element_capacity = size;
            reserved_capacity = size;
        };
        ~vector(){
            free(raw_vector);
        }
        T& operator[](std::size_t No){
            if (No >= cur_element_capacity) throw("Out bound!");
            return (raw_vector[No]);
        }

        void push_back(T obj){
            if (cur_element_capacity + 1 >= reserved_capacity){
                T* newptr = (T*) malloc(reserved_capacity * 2 * sizeof(T));
                memcpy(newptr , raw_vector , reserved_capacity*sizeof(T));
                free(raw_vector);
                raw_vector = newptr;
                reserved_capacity *= 2;
            }
            cur_element_capacity += 1;
            raw_vector[cur_element_capacity - 1] = obj;
        }

        int size(){
            return cur_element_capacity;
        }
};











#endif












