#include "Allocator/ClassicAllocator.h"
#include "Allocator/LinearAllocator.h"
#include <chrono>
#include <iostream>
#include "vector.h"
using namespace std::chrono;
using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::chrono::nanoseconds;

void Classic(){
    auto start = high_resolution_clock::now();
    ClassicAllocator AL;
    for (int i = 0 ; i < 1000000 ; i ++){
        static_cast<int*>(AL.Allocate(sizeof(int)));
    }
    auto end  = high_resolution_clock::now();
    auto ms_int = duration_cast<nanoseconds>(end - start);
    std::cout << ms_int.count() << '\n';
}

void Linear(){
    auto clock = high_resolution_clock();
    auto start = clock.now();
    LinearAllocator LAL(1000001*4);
    for (int i = 0 ; i < 1000000 ; i ++){
        static_cast<int*>(LAL.Allocate(sizeof(int)));
    }
    LAL.Reset();
    auto end = clock.now();
    auto ms_int = duration_cast<nanoseconds>(end - start);
    std::cout << ms_int.count() << '\n';
    
}

int main(){
    Classic();
    Linear();
}