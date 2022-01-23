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

TEST(Vector_Test , CopyConstructorTest){
    vector<int> test_vector ;
    test_vector.push_back(0);
    test_vector.push_back(1);
    test_vector.push_back(2);
    test_vector.push_back(3);
    vector<int> test_vector2 = test_vector;
    EXPECT_EQ(test_vector2[0] , 0);
    EXPECT_EQ(test_vector2.size() , 4);
}

TEST(Vector_Test , MoveConstructorTest){
    vector<int> test_vector ;
    test_vector.push_back(0);
    test_vector.push_back(1);
    test_vector.push_back(2);
    test_vector.push_back(3);
    vector<int> test_vector2 = std::move(test_vector);
    EXPECT_EQ(test_vector2[0] , 0);
    EXPECT_EQ(test_vector2.size() , 4);
}