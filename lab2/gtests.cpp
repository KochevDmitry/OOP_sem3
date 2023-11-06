#include <gtest/gtest.h>
#include "BitString.h"

TEST(test_01, basic_test_set) {
    BitString first;
    ASSERT_TRUE(first.GetLength() == 0);
}

TEST(test_02, basic_test_set) {
    BitString second(10);
    int length = second.GetLength();
    unsigned char a = second.GetBit(0);
    unsigned char b = second.GetBit(3);
    unsigned char c = second.GetBit(9);
    bool answer = false;
    if (a == b && a == c && a == '0' && length == 10)
        answer = true;
    ASSERT_TRUE(answer);
}

TEST(test_03, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    bool answer = false;
    if (a.GetBit(0) == '1' && a.GetBit(1) == '1' && a.GetBit(2) == '1' && a.GetBit(3) == '0' &&
         a.GetBit(4) == '1' && a.GetBit(5) == '0' && a.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_04, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char* str2 = new unsigned char[8];
    str2[0] = '1';
    str2[1] = '0';
    str2[2] = '0';
    str2[3] = '1';
    str2[4] = '1';
    str2[5] = '0';
    str2[6] = '1';
    str2[7] = '1';
    BitString c(8, str2);
    BitString new_and = a&c;
    bool answer = false;
    if (new_and.GetBit(0) == '0' && new_and.GetBit(1) == '0' && new_and.GetBit(2) == '0' && new_and.GetBit(3) == '1' &&
         new_and.GetBit(4) == '1' && new_and.GetBit(5) == '0' && new_and.GetBit(6) == '1' && new_and.GetBit(7) == '0'
          && new_and.GetLength() == 8)
         answer = true;
    str1 = nullptr;
    str2 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_05, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char* str2 = new unsigned char[8];
    str2[0] = '1';
    str2[1] = '0';
    str2[2] = '0';
    str2[3] = '1';
    str2[4] = '1';
    str2[5] = '0';
    str2[6] = '1';
    str2[7] = '1';
    BitString c(8, str2);
    BitString new_or = a|c;
    bool answer = false;
    if (new_or.GetBit(0) == '1' && new_or.GetBit(1) == '0' && new_or.GetBit(2) == '1' && new_or.GetBit(3) == '1' &&
         new_or.GetBit(4) == '1' && new_or.GetBit(5) == '0' && new_or.GetBit(6) == '1' && new_or.GetBit(7) == '1'
          && new_or.GetLength() == 8)
         answer = true;
    str1 = nullptr;
    str2 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_06, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char* str2 = new unsigned char[8];
    str2[0] = '1';
    str2[1] = '0';
    str2[2] = '0';
    str2[3] = '1';
    str2[4] = '1';
    str2[5] = '0';
    str2[6] = '1';
    str2[7] = '1';
    BitString c(8, str2);
    BitString new_xor = a^c;
    bool answer = false;
    if (new_xor.GetBit(0) == '1' && new_xor.GetBit(1) == '0' && new_xor.GetBit(2) == '1' && new_xor.GetBit(3) == '0' &&
         new_xor.GetBit(4) == '0' && new_xor.GetBit(5) == '0' && new_xor.GetBit(6) == '0' && new_xor.GetBit(7) == '1'
          && new_xor.GetLength() == 8)
         answer = true;
    str1 = nullptr;
    str2 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_07, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    BitString new_no = ~a;
    bool answer = false;
    if (new_no.GetBit(0) == '0' && new_no.GetBit(1) == '0' && new_no.GetBit(2) == '0' && new_no.GetBit(3) == '1' &&
         new_no.GetBit(4) == '0' && new_no.GetBit(5) == '1' && new_no.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_08, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char * cop = a.GetString();
    bool answer = false;
    if (cop[0] == '1' && cop[1] == '1' && cop[2] == '1' && cop[3] == '0' &&
         cop[4] == '1' && cop[5] == '0')
         answer = true;
    cop = nullptr;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_09, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char* str2 = new unsigned char[6];
    str2[0] = '0';
    str2[1] = '0';
    str2[2] = '1';
    str2[3] = '0';
    str2[4] = '1';
    str2[5] = '1';
    a.SetStringAndLength(6, str2);
    bool answer = false;
    if (a.GetBit(0) == '0' && a.GetBit(1) == '0' && a.GetBit(2) == '1' && a.GetBit(3) == '0' &&
         a.GetBit(4) == '1' && a.GetBit(5) == '1' && a.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    str2 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_10, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    a.SetBit(0, '0');
    a.SetBit(5, '1');
    bool answer = false;
    if (a.GetBit(0) == '0' && a.GetBit(1) == '1' && a.GetBit(2) == '1' && a.GetBit(3) == '0' &&
         a.GetBit(4) == '1' && a.GetBit(5) == '1' && a.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_11, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    BitString c;
    BitString d = a&c;
    bool answer = false;
    if (d.GetBit(0) == '0' && d.GetBit(1) == '0' && d.GetBit(2) == '0' && d.GetBit(3) == '0' &&
         d.GetBit(4) == '0' && d.GetBit(5) == '0' && d.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}
TEST(test_12, basic_test_set) {
   unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    BitString c;
    BitString d = a^c;
    bool answer = false;
    if (d.GetBit(0) == '1' && d.GetBit(1) == '1' && d.GetBit(2) == '1' && d.GetBit(3) == '0' &&
         d.GetBit(4) == '1' && d.GetBit(5) == '0' && d.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}
TEST(test_13, basic_test_set) {
   unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    BitString c;
    BitString d = a|c;
    bool answer = false;
    if (d.GetBit(0) == '1' && d.GetBit(1) == '1' && d.GetBit(2) == '1' && d.GetBit(3) == '0' &&
         d.GetBit(4) == '1' && d.GetBit(5) == '0' && d.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}
TEST(test_14, basic_test_set) {
    BitString c;
    BitString d = ~c;
    bool answer = false;
    if (d.GetLength() == 0)
         answer = true;
    ASSERT_TRUE(answer);
}

TEST(test_15, basic_test_set) {
    BitString a;
    BitString c;
    BitString d = a&c;
    bool answer = false;
    if (d.GetLength() == 0)
         answer = true;
    ASSERT_TRUE(answer);
}

TEST(test_16, basic_test_set) {
    BitString a;
    BitString c;
    BitString d = a^c;
    bool answer = false;
    if (d.GetLength() == 0)
         answer = true;
    ASSERT_TRUE(answer);
}

TEST(test_17, basic_test_set) {
    BitString a;
    BitString c;
    BitString d = a|c;
    bool answer = false;
    if (d.GetLength() == 0)
         answer = true;
    ASSERT_TRUE(answer);
}

TEST(test_18, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    BitString c(a);
    bool answer = false;
    if (c.GetBit(0) == '1' && c.GetBit(1) == '1' && c.GetBit(2) == '1' && c.GetBit(3) == '0' &&
         c.GetBit(4) == '1' && c.GetBit(5) == '0' && c.GetLength() == 6)
         answer = true;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}



// TEST(test_19, basic_test_set) {
//     int* str1 = new int[6];
//     str1[0] = 1;
//     str1[1] = 1;
//     str1[2] = 1;
//     str1[3] = 0;
//     str1[4] = 1;
//     str1[5] = 0;
//     bool answer = false;
//     try{
//         BitString first(6, str1);
//     }
//     catch(std::exception &ex){
//         bool answer = true;
//     }
//     ASSERT_TRUE(answer);
// }

TEST(test_19, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = 'A';
    str1[1] = 'B';
    str1[2] = 'A';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        BitString first(6, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_20, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        BitString first(-1, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_21, basic_test_set) {
    bool answer = false;
    try{
        BitString first(-10);
    }
    catch(std::exception &ex){
        answer = true;
    }
    ASSERT_TRUE(answer);
}

TEST(test_22, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        BitString first(8, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_23, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString first(6, str1);
    bool answer = false;
    try{
        first.SetBit(10, '1');
    }
    catch(std::exception &ex){
        answer = true;
    }
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_24, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString first(6, str1);
    bool answer = false;
    try{
        first.SetBit(1, 'A');
    }
    catch(std::exception &ex){
        answer = true;
    }
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_25, basic_test_set) {
    BitString first;
    unsigned char* str1 = new unsigned char[6];
    str1[0] = 'A';
    str1[1] = 'B';
    str1[2] = 'A';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        first.SetStringAndLength(6, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_26, basic_test_set) {
    BitString first;
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        first.SetStringAndLength(-1, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_27, basic_test_set) {
    BitString first;
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        first.SetStringAndLength(10, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_28, basic_test_set) {
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        BitString first(4, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}

TEST(test_29, basic_test_set) {
    BitString first;
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '0';
    str1[2] = '0';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    bool answer = false;
    try{
        first.SetStringAndLength(5, str1);
    }
    catch(std::exception &ex){
        answer = true;
    }
    delete[] str1;
    str1 = nullptr;
    ASSERT_TRUE(answer);
}




int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
