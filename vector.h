#ifndef INCLUDE_VECTOR_H
#define INCLUDE_VECTOR_H

#include "Allocator/LinearAllocator.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <type_traits>
template<typename T>
class vector{
    private:
        T* raw_vector;
        std::size_t cur_element_capacity;
        std::size_t reserved_capacity;
    public:
        vector();
        vector(const vector<T> &rhs); // copy
        vector(vector<T> &&rhs); // move
        vector(int size);
        ~vector();
        T& operator[](std::size_t No);
        void push_back(T obj);
        void pop_back();
        int size() {return cur_element_capacity;}
    
};


template<typename T>
vector<T>::vector(){ 
    raw_vector = (T*) malloc(sizeof(T));
    cur_element_capacity = 0;
    reserved_capacity = 1;
}

template<typename T>
vector<T>::vector(const vector<T> &rhs){
    cur_element_capacity = rhs.cur_element_capacity;
    reserved_capacity = rhs.reserved_capacity;
    raw_vector = (T*) malloc(reserved_capacity * sizeof(T));
    memcpy(raw_vector , rhs.raw_vector , reserved_capacity*sizeof(T));
}

template<typename T>
vector<T>::vector(vector<T> &&rhs){
    cur_element_capacity = rhs.cur_element_capacity;
    reserved_capacity = rhs.reserved_capacity;
    raw_vector = rhs.raw_vector;
    rhs.raw_vector = nullptr;
}

template<typename T>
vector<T>::vector(int size){
    raw_vector = (T*) malloc(size * sizeof(T));
    cur_element_capacity = size;
    reserved_capacity = size;
}

template<typename T>
vector<T>::~vector(){
    free(raw_vector);
}

template<typename T>
T& vector<T>::operator[](std::size_t No){
    if (No >= cur_element_capacity) throw("Out bound!");
    return (raw_vector[No]);
}


template<typename T>
void vector<T>::push_back(T obj){
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

template<typename T>
void vector<T>::pop_back(){
    if constexpr (std::is_fundamental<T>::value != true) raw_vector[cur_element_capacity - 1].~T();
    cur_element_capacity --;
}


#endif












