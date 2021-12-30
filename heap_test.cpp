#include "gtest/gtest.h"
#include "heap.h"
#include <vector>
#include <string>

TEST(HeapTest , ExtractMaxTest){
    std::vector<int> testing_vec({2,5,-4,3,10,7});
    heap testing_heap(testing_vec);
    int max;
    max = testing_heap.extract_max();
    EXPECT_EQ(max , 10);
    max = testing_heap.extract_max();
    EXPECT_EQ(max , 7);
    max = testing_heap.extract_max();
    EXPECT_EQ(max, 5);
}

TEST(HeapTest ,HeapSortTest){
    std::vector<int> testing_vec({2,5,-4,3,10,7});
    std::vector<int> testing_vec_aim({-4 , 2 , 3 , 5 , 7 ,10});
    heap testing_heap(testing_vec);
    std::vector sorted_vec = testing_heap.get_sorted_vec();
    ASSERT_EQ(sorted_vec.size() , testing_vec_aim.size());
    for (int i = 0 ; i < sorted_vec.size() ; i++){
        EXPECT_EQ(sorted_vec[i] , testing_vec_aim[i]);
    }
}

TEST(HeapTest , EdgeCaseTest){
    std::vector<int> testing_vec_empty({});
    std::vector<int> testing_vec_single({1});
    heap testing_heap_empty(testing_vec_empty);
    heap testing_heap_single(testing_vec_single);
}

TEST(HeapTest , ExtractMaxTest_string){
    std::vector<std::string> testing_vec({"abc","bbc","cbc","dbc" , "ebc"});
    heap testing_heap(testing_vec);
    std::string max;
    max = testing_heap.extract_max();
    EXPECT_EQ(max , "ebc");
    max = testing_heap.extract_max();
    EXPECT_EQ(max , "dbc");
    max = testing_heap.extract_max();
    EXPECT_EQ(max, "cbc");
}