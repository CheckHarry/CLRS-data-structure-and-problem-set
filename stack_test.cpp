#include "stack.h"
#include "gtest/gtest.h"
#include <iostream>



TEST(Stack_test , push_pop_test){
    stack<int> test_stack;
    test_stack.push(5);
    test_stack.push(3);
    EXPECT_EQ(test_stack.top() , 3);
    test_stack.top() = 7;
    EXPECT_EQ(test_stack.top() , 7);
    test_stack.pop();
    EXPECT_EQ(test_stack.top() , 5);
    test_stack.push(4);
    EXPECT_EQ(test_stack.size() , 2);
}