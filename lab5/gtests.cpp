#include <gtest/gtest.h>
#include "allocator.h"
#include "LinkedList.h"
#include <map>

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

TEST(test_04, basic_test_set) {
    LinkedList<int, AllocatorList<int>> my_list;
    my_list.push_back(1);
    LinkedList<int, AllocatorList<int> >::Iterator it(my_list.begin());
    bool c = false;
    if( *it == 1)
        c = true;
    ASSERT_TRUE(c);
}

TEST(test_05, basic_test_set) {
    LinkedList<int, AllocatorList<int> > my_list;
    my_list.push_back(1);
    my_list.push_back(2);
    LinkedList<int, AllocatorList<int> >::Iterator it1 = my_list.begin();
    LinkedList<int, AllocatorList<int> >::Iterator it2 = ++it1;
    bool c = false;
    if( *it2 == 2)
        c = true;
    ASSERT_TRUE(c);
}

TEST(test_06, basic_test_set) {
    LinkedList<int, AllocatorList<int> > my_list;
    auto it1 = my_list.begin();
    bool c = false;
    if(it1 == my_list.end())
        c = true;
    ASSERT_TRUE(c);
}


TEST(test_07, basic_test_set) {
    std::map<int, int, std::less<int>, AllocatorList<std::pair<const int,int>>> my_map;
    for (int i = 0; i < 10; i ++)
        my_map[i] = i;
    bool c = true;
    for (int i = 0; i < 10; i ++)
        if (my_map[i] != i)
            c = false;

    ASSERT_TRUE(c);
}

TEST(test_08, basic_test_set) {
    AllocatorList<int> alloc;
    int c = 1;
    int * b = &c;
     ASSERT_THROW(alloc.deallocate(b, 1), std::invalid_argument);
}

TEST(test_09, basic_test_set) {
    AllocatorList<int> alloc;
    int* ptr = alloc.allocate(1);
    ASSERT_NO_THROW(alloc.deallocate(ptr, 1));
}

TEST(test_10, basic_test_set) {
    AllocatorList<int> alloc;
    int* ptr = alloc.allocate(1);
    alloc.deallocate(ptr, 1);
    ASSERT_THROW(alloc.deallocate(nullptr, 1), std::invalid_argument);
}

TEST(test_11, basic_test_set) {
    LinkedList<int, AllocatorList<int>> my_list;
    for (int i = 0; i < 10; i++)
        my_list.push_back(i);
    my_list.clear();
    bool c = false;
    if(my_list.begin() == my_list.end())
        c = true;
    ASSERT_TRUE(c);
}

int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
