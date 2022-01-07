
#ifndef INCLUDE_H

#define INCLUDE_H
template <typename T>
struct Node{
    T val;
    Node<T> * left = nullptr;
    Node<T> * right = nullptr;
    Node<T> * parent = nullptr;
    bool color ; // 0 black , 1 red
    Node(T value) : val(value){};
    void set_left(Node<T>* left_ptr){left = left_ptr ; left_ptr -> parent = this;}
    void set_right(Node<T>* right_ptr){right = right_ptr ; right_ptr -> parent = this;}
};


template <typename T>
class red_black_tree{
    Node<T>* root;
public:
    red_black_tree(T initial_value);//
    void insert(T val);
    void rotate_left(Node<T> *node);
    void rotate_right(Node<T> *node);
    void fix_red_black_tree();
    #ifdef _TEST_ // doesn't expose to lib user , only for testing purpose
    Node<T>* get_root();
    #endif
};

template<typename T>
red_black_tree<T>::red_black_tree(T initial_value){
    root = new Node<T>(initial_value);
    root -> color = 0;
}

template<typename T>
void red_black_tree<T>::rotate_left(Node<T> *node){
    Node<T> *y = node -> right;
    if (node -> parent != nullptr) {
        y -> parent = node -> parent;
        if (y -> parent -> left == node) y -> parent -> left = y;
        else y -> parent -> right = y;
    }
    else y -> parent = nullptr;
    node -> right = y -> left;
    y -> left = node;
    node -> parent = y;
    if (root == node) root = y;
}

template<typename T>
void red_black_tree<T>::rotate_right(Node<T> *node){
    Node<T> *y = node -> left;
    if (node -> parent != nullptr) {
        y -> parent = node -> parent;
        if (y -> parent -> left == node) y -> parent -> left = y;
        else y -> parent -> right = y;
    }
    else y -> parent = nullptr;
    node -> left = y -> right;
    y -> right = node;
    node -> parent = y;
    if (root == node) root = y;
}

template<typename T>
void red_black_tree<T>::insert(T value){
    Node<T>* new_node = new Node<T>(value);
    new_node -> color = 1;
}

template<typename T>
void red_black_tree<T>::fix_red_black_tree(){}    

#ifdef _TEST_
template<typename T>
Node<T>* red_black_tree<T>::get_root(){
    return root;
}
#endif
#endif