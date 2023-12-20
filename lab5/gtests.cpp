#include <gtest/gtest.h>
#include "allocator.h"
#include "LinkedList.h"

TEST(test_01, basic_test_set) {
    LinkedList<int> my_list;
    for (int i = 0; i < 10; i++)
        my_list.push_back(i);
    bool c = true;
    int j = 0;
    for (auto it = my_list.begin(); it != my_list.end(); ++it){
        if (*it != j)
            c = false;
        j++;
    }
    ASSERT_TRUE(c);
}

TEST(test_02, basic_test_set) {
    LinkedList<int> my_list;
    for (int i = 0; i < 10; i++)
        my_list.push_back(i);
    my_list.pop_back();
    bool c = false;
    int j = 0;
    for (auto it = my_list.begin(); it != my_list.end(); ++it){
        j++;
    }
    if(j == 9)
        c = true;
    ASSERT_TRUE(c);
}

TEST(test_03, basic_test_set) {
    LinkedList<int, AllocatorList<int>> my_list;
    for (int i = 0; i < 10; i++)
        my_list.push_back(i);
    my_list.clear();
    bool c = false;
    int j = 0;
    for (auto it = my_list.begin(); it != my_list.end(); ++it){
        j++;
    }
    if(j == 0)
        c = true;
    ASSERT_TRUE(c);
}



int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}