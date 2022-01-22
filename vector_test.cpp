#include "vector.h"
#include "gtest/gtest.h"
#include <iostream>



TEST(Vector_Test , SetTest){
    vector<int> test_vector(10);    
    test_vector[0] = 1;
    test_vector[5] = 4;
    test_vector.push_back(7);
    EXPECT_EQ(test_vector[0] , 1);
    EXPECT_EQ(test_vector[5] , 4);
    EXPECT_EQ(test_vector[10] , 7);
}

TEST(Vector_Test , SizeTest){
    vector<int> test_vector;    
    test_vector.push_back(6);
    test_vector.push_back(7);
    EXPECT_EQ(test_vector.size() , 2);
}

TEST(Vectors_Test , LoopTest){
    vector<int> test_vector(10);
    for (int x : test_vector){

    }
}