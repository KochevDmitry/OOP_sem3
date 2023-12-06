#include <gtest/gtest.h>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"
#include "figure.h"
#include "figure_array.h"
#include "string"

std::pair<float, float> a1(1, 1);
std::pair<float, float> a2(2, 3);
std::pair<float, float> a3(3, 1);
std::pair<float, float> a4(2, -1);
std::pair<float, float> a5(8, 9);
std::pair<float, float> a6(10, 11);

std::pair<int, int> b1(1, 1);
std::pair<int, int> b2(2, 3);
std::pair<int, int> b3(3, 1);
std::pair<int, int> b4(2, -1);
std::pair<int, int> b5(8, 9);
std::pair<int, int> b6(10, 11);

TEST(test_01, basic_test_set) {
    Rhombus<float> a(a1, a2, a3, a4);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 4);
}

TEST(test_02, basic_test_set) {
    Rhombus<float> a(a1, a2, a3, a4);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first == 2 && d.second == 1);
}

TEST(test_03, basic_test_set) {
    Pentagon<float> a(a1, a2, a3, a4, a5);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 7);
}

TEST(test_04, basic_test_set) {
    Pentagon<float> a(a1, a2, a3, a4, a5);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first <= 3.3 && d.first >= 3.2 && d.second >= 2.599 && d.second <= 2.63);
}

TEST(test_05, basic_test_set) {
    Hexagon<float> a(a1, a2, a3, a4, a5, a6);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 6);
}

TEST(test_06, basic_test_set) {
    Hexagon<float> a(a1, a2, a3, a4, a5, a6);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first >= 4.33 && d.first <= 4.34 && d.second == 4);
}

TEST(test_07, basic_test_set) {
    Hexagon<int> b(b1, b2, b3, b4, b5, b6);
    float c;
    c = double(b);
    ASSERT_TRUE(c == 6);
}

TEST(test_08, basic_test_set) {
    Hexagon<int> b(b1, b2, b3, b4, b5, b6);
    float c;
    c = double(b);
    std::pair<int, int> d = b.center();
    ASSERT_TRUE(d.first == 4 && d.second == 4);
}

TEST(test_09, basic_test_set) {
    Pentagon<int> b(b1, b2, b3, b4, b5);
    float c;
    c = double(b);
    ASSERT_TRUE(c == 7);
}

TEST(test_10, basic_test_set) {
    Pentagon<int> b(b1, b2, b3, b4, b5);
    std::pair<int, int> d = b.center();
    ASSERT_TRUE(d.first == 3 && d.second == 2);
}

TEST(test_11, basic_test_set) {
    Rhombus<int> b(b1, b2, b3, b4);
    float c;
    c = double(b);
    ASSERT_TRUE(c == 4);
}

TEST(test_12, basic_test_set) {
    Rhombus<int> b(b1, b2, b3, b4);
    std::pair<int, int> d = b.center();
    ASSERT_TRUE(d.first == 2 && d.second == 1);
}

TEST(test_13, basic_test_set) {
    FigureArray<int> *array = create_arr<int>();
    std::shared_ptr<Pentagon<int>> smartppp = std::make_shared<Pentagon<int>>(b1, b2, b3, b4, b5);
    std::shared_ptr<Hexagon<int>> smarthhh = std::make_shared<Hexagon<int>>(b1, b2, b3, b4, b5, b6);
    add_figure(array, smartppp);
    add_figure(array, smarthhh);
    double c;
    c = sum_area(array);
    rm_arr(array);
    ASSERT_TRUE(c == 13);
}

TEST(test_14, basic_test_set) {
    FigureArray<int> *array = create_arr<int>();
    std::shared_ptr<Pentagon<int>> smartppp = std::make_shared<Pentagon<int>>(b1, b2, b3, b4, b5);
    std::shared_ptr<Hexagon<int>> smarthhh = std::make_shared<Hexagon<int>>(b1, b2, b3, b4, b5, b6);
    add_figure(array, smartppp);
    add_figure(array, smarthhh);
    rm_figure(array, 0);
    double c;
    c = sum_area(array);
    rm_arr(array);
    ASSERT_TRUE(c == 6);
}

TEST(test_15, basic_test_set) {
    Rhombus<int> b(b1, b2, b3, b4);
    Rhombus<int> b_2(b1, b2, b3, b4);
    bool answer = false;
    if (b == b_2){
        answer = true;
    }
    ASSERT_TRUE(answer);
}

TEST(test_16, basic_test_set) {
    Pentagon<int> b(b1, b2, b3, b4, b5);
    Pentagon<int> b_2(b1, b2, b3, b4, b5);
    bool answer = false;
    if (b == b_2){
        answer = true;
    }
    ASSERT_TRUE(answer);
}

TEST(test_17, basic_test_set) {
    Pentagon<int> b;
    float c = double(b);
    ASSERT_TRUE(c == 0);
}

TEST(test_18, basic_test_set) {
    Pentagon<int> b(b1, b2, b3, b4, b5);
    Pentagon<int> b_2;
    b_2 = b;
    float c = double(b_2);
    ASSERT_TRUE(c == 7);
}

TEST(test_19, basic_test_set) {
    Pentagon<int> b;
    std::pair<int, int> d = b.center();
    ASSERT_TRUE(d.first == 0 && d.second == 0);
}

TEST(test_20, basic_test_set) {
    std::shared_ptr<Rhombus<int>> smartppp = std::make_shared<Rhombus<int>>(b1, b2, b3, b4);
    std::pair<int, int> d = smartppp.get()->center();
    ASSERT_TRUE(d.first == 2 && d.second == 1);
}


TEST(test_21, basic_test_set) {
     FigureArray<int> *array = create_arr<int>();
    std::shared_ptr<Pentagon<int>> smartppp = std::make_shared<Pentagon<int>>(b1, b2, b3, b4, b5);
    std::shared_ptr<Hexagon<int>> smarthhh = std::make_shared<Hexagon<int>>(b1, b2, b3, b4, b5, b6);
    add_figure(array, smartppp);
    add_figure(array, smarthhh);
    bool answer = false;
    try{
        rm_figure(array, 100);
    }
    catch(std::exception &ex){
        answer = true;
    }
    ASSERT_TRUE(answer);
}




int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}