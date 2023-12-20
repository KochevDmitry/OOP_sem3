#include <iostream>
#include <memory>
#include <chrono>
#include <list>
#include <map>
#include <utility>
#include "allocator.h"
#include "LinkedList.h"

struct SomeStruct
{
    char buffer[1024];
};

void test1()
{
    auto begin = std::chrono::high_resolution_clock::now();
    LinkedList<SomeStruct> my_list;
    for (int i = 0; i < 500000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 500000; i++)
        my_list.pop_back();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test1: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

void test2()
{
    auto begin = std::chrono::high_resolution_clock::now();
    LinkedList<SomeStruct, AllocatorList<SomeStruct>> my_list;
    for (int i = 0; i < 100000; i++)
        my_list.push_back(SomeStruct());
    for (int i = 0; i < 100000; i++)
        my_list.pop_back();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "test2: " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << std::endl;
}

int main(int argc, char **argv)
{
    test1();
    test2();

    std::map<int, int, std::less<int>, AllocatorList<std::pair<const int,int>>> my_map;

    my_map[1]=10;
    my_map[2]=20;
    my_map[3]=30;


    for(const auto& [k,v]: my_map)
        std::cout << k << "->" << v << std::endl;

    return 0;
}
