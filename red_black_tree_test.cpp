#define _TEST_
#include "gtest/gtest.h"
#include "red_black_tree.h"





TEST(Red_black_tree_Test , RotateTest){
    Node<int>  *_2 = new Node(2) , *_3 = new Node(3) , *_4 = new Node(4) , *_5 = new Node(5);
    red_black_tree tree(1);
    Node<int> *_1 = tree.get_root();
    _1->set_left(_2);
    _1->set_right(_3);
    _3->set_left(_4);
    _3->set_right(_5);
    EXPECT_EQ(_1 -> parent ,nullptr);
    EXPECT_EQ(_3 -> parent ,_1);
    tree.rotate_left(_1);
    EXPECT_EQ( tree.get_root() , _3 ) ;
    EXPECT_EQ( _1 -> left , _2 ) ;
    EXPECT_EQ( _1 -> right , _4 ) ;
    EXPECT_EQ( _1 -> parent , _3);
    EXPECT_EQ( _3 -> left , _1 ) ;
    EXPECT_EQ( _3 -> right , _5);
    tree.rotate_right(tree.get_root());
    EXPECT_EQ(tree.get_root() , _1);
    EXPECT_EQ(_1 -> parent ,nullptr);
    EXPECT_EQ(_3 -> parent ,_1);
    EXPECT_EQ(_1 -> right , _3);
    EXPECT_EQ(_1 -> left , _2);
}