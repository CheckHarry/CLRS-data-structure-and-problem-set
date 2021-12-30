#ifndef INCLUDE_H

#define INCLUDE_H
#include <vector>
#include <algorithm>
#include <iostream>



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
    std::vector<T> get_sorted_vec();
};


template<typename T>
void heap<T>::print_heap(){
    for (int i = 0 ; i < vec_size ; i ++){
        std::cout << heap_vec[i] << '\n';
    }
}


template<typename T>
void heap<T>::heapify(int index){
    int l = index * 2 , r = index * 2 + 1 , max_index = index;
    if (l < vec_size && heap_vec[l] > heap_vec[index])  max_index = l; 
    else  max_index = index; 
    if (r < vec_size && heap_vec[max_index] < heap_vec[r]) max_index = r;

    if (max_index != index){
        std::swap(heap_vec[max_index] , heap_vec[index]);
        heapify(max_index);
    }
}


template<typename T>
void heap<T>::build_heap(){
    for (int i = vec_size / 2 ; 0 <= i ; i -- ) heapify(i);
}


template<typename T>
heap<T>::heap(std::vector<T> heap_vec_to_insert) : heap_vec(heap_vec_to_insert){
    vec_size = heap_vec.size();
    build_heap();
}

template<typename T>
const T& heap<T>::get_max(){
    return heap_vec[0];
}
template<typename T>
T heap<T>::extract_max(){
        if (vec_size == 0) throw "Error!";
        T temp = heap_vec[0];
        heap_vec[0] = heap_vec[vec_size - 1];
        vec_size --;
        heapify(0);
        return temp;
    }

template<typename T>
std::vector<T> heap<T>::get_sorted_vec(){
    while(vec_size > 0){
        std::swap(heap_vec[0] , heap_vec[vec_size - 1]);
        vec_size --;
        heapify(0);
    }    
    return heap_vec;
}
#endif