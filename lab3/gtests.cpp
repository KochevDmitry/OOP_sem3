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

TEST(test_01, basic_test_set) {
    Rhombus a(a1, a2, a3, a4);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 4);
}

TEST(test_02, basic_test_set) {
    Rhombus a(a1, a2, a3, a4);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first == 2 && d.second == 1);
}

TEST(test_03, basic_test_set) {
    Pentagon a(a1, a2, a3, a4, a5);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 7);
}

TEST(test_04, basic_test_set) {
    Pentagon a(a1, a2, a3, a4, a5);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first <= 3.3 && d.first >= 3.2 && d.second >= 2.599 && d.second <= 2.63);
}

TEST(test_05, basic_test_set) {
    Hexagon a(a1, a2, a3, a4, a5, a6);
    float c;
    c = double(a);
    ASSERT_TRUE(c == 6);
}

TEST(test_06, basic_test_set) {
    Hexagon a(a1, a2, a3, a4, a5, a6);
    std::pair<float, float> d = a.center();
    ASSERT_TRUE(d.first >= 4.33 && d.first <= 4.34 && d.second == 4);
}

TEST(test_07, basic_test_set) {
    FigureArray *array = create_arr();
    Pentagon ppp(a1, a2, a3, a4, a5);
    Hexagon hhh(a1, a2, a3, a4, a5, a6);
    add_figure(array, &ppp);
    add_figure(array, &hhh);
    double c;
    c = sum_area(array);
    rm_arr(array);
    ASSERT_TRUE(c == 13);
}

TEST(test_08, basic_test_set) {
    FigureArray *array = create_arr();
    Pentagon ppp(a1, a2, a3, a4, a5);
    Hexagon hhh(a1, a2, a3, a4, a5, a6);
    add_figure(array, &ppp);
    add_figure(array, &hhh);
    rm_figure(array, 0);
    double c;
    c = sum_area(array);
    rm_arr(array);
    ASSERT_TRUE(c == 6);
}

TEST(test_09, basic_test_set) {
    Rhombus a(a1, a2, a3, a4);
    Rhombus a_2(a1, a2, a3, a4);
    bool answer = false;
    if (a == a_2){
        answer = true;
    }
    ASSERT_TRUE(answer);
}

TEST(test_10, basic_test_set) {
    Pentagon a(a1, a2, a3, a4, a5);
    Pentagon a_2(a1, a2, a3, a4, a5);
    bool answer = false;
    if (a == a_2){
        answer = true;
    }
    ASSERT_TRUE(answer);
}

TEST(test_11, basic_test_set) {
    Pentagon b;
    float c = double(b);
    ASSERT_TRUE(c == 0);
}

TEST(test_12, basic_test_set) {
    Pentagon a(a1, a2, a3, a4, a5);
    Pentagon a_2;
    a_2 = a;
    float c = double(a_2);
    ASSERT_TRUE(c == 7);
}

TEST(test_13, basic_test_set) {
    Pentagon b;
    std::pair<float, float> d = b.center();
    ASSERT_TRUE(d.first == 0 && d.second == 0);
}



int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}