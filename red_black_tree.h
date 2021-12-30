
#ifndef INCLUDE_H

#define INCLUDE_H
template <typename T>
struct Node{
    T val;
    bool color ;
    Node<T> * left ;
    Node<T> * right ;
    Node<T> * parent;
};


template <typename T>
class red_black_tree{
private:
    Node<T>* root;
public:
    red_black_tree();
    red_black_tree(T initial_value);
    red_black_tree(Node<T>* Node);
    void insert(T val);
    void rotate_left();
    void rotate_right();
    void fix_red_black_tree();
};

#endif