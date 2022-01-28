#include <vector>
#include <iostream>
#include "heap.h"



int main(){
    std::vector<int> x({2,3,1,4,5,6,-5});
    heap Heap(x);
   
    std::cout << "max:" << Heap.extract_max() << '\n';
  
    std::cout << "max:" << Heap.extract_max() << '\n';

    std::cout << "max:" << Heap.extract_max() << '\n';

}




