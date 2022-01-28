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
    T& top();
    int size();
    bool empty();
};

template<typename T>
stack<T>::stack(): container() {}

template<typename T>
void stack<T>::push(T obj){
    container.push_back(obj);
}

template<typename T>
void stack<T>::pop(){
    if(size() > 0) container.pop_back();
    else throw "stack is empty!";
}

template<typename T>
T& stack<T>::top(){
    return container[size() - 1];
}


template<typename T>
int stack<T>::size(){
    return container.size();
}


template<typename T>
bool stack<T>::empty(){
    return size() == 0;
}


#endif