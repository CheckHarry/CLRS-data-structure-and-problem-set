#include "gtest/gtest.h"
#include "heap.h"
#include <vector>

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