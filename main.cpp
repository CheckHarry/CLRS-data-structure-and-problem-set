#include <vector>
#include <iostream>
#include "heap.h"



int main(){
    std::vector<int> x({2,3,1,4,5,6,-5});
    heap Heap(x);
    Heap.print_heap();
    std::cout << "max:" << Heap.extract_max() << '\n';
    Heap.print_heap();
    std::cout << "max:" << Heap.extract_max() << '\n';
    Heap.print_heap();
    std::cout << "max:" << Heap.extract_max() << '\n';
    Heap.print_heap();
}




