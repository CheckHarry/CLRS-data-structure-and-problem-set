#ifndef INCLUDE_STACK
#define INCLUDE_STACK
#include "vector.h"



template<typename T>
class stack{
private:
    vector<T> container;
public:
    stack();
    void push(T obj);
    void pop();
    int size();
};

template<typename T>
stack<T>::stack(): container() {}

template<typename T>
void stack<T>::push(T obj){
    container.push_back(obj);
}

template<typename T>
void stack<T>::pop(){
    container.pop_back();
}






#endif