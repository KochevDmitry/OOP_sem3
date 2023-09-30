#include <gtest/gtest.h>
#include "function.h"

TEST(test_01, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("Vader said: No, I am your father!", 2, 'a', 'o') == "Vader soid: No, I am your fother!");
}

TEST(test_02, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("aaaaaaaaa", 2, 'a', 'o') == "aoaoaoaoa");
}

TEST(test_03, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("aaaaaaaaa", -5, 'a', 'o') == "aaaaaaaaa");
}

TEST(test_04, basic_test_set) { 
    ASSERT_TRUE(replaceNthCharacter("aaaaaaaaa", 0, 'a', 'o') == "aaaaaaaaa");
}

TEST(test_05, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("a", 2, 'a', 'o') == "a");
}

TEST(test_06, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("aaaaaa", 7, 'a', 'o') == "aaaaaa");
}

TEST(test_07, basic_test_set) {
    ASSERT_TRUE(replaceNthCharacter("aaaaaaa", 7, 'a', 'o') == "aaaaaao");
}

TEST(test_08, basic_test_set) { 
    ASSERT_TRUE(replaceNthCharacter("hello my name is leonel", 1, 'l', 'p') == "heppo my name is peonep");
}

TEST(test_09, basic_test_set) { 
    ASSERT_TRUE(replaceNthCharacter("", 2, 'l', 'p') == "");
}

TEST(test_10, basic_test_set) { 
    ASSERT_TRUE(replaceNthCharacter("aaaa", 2, 'l', 'p') == "aaaa");
}

int main (int args, char **argv) {
    testing::InitGoogleTest(&args, argv);
    return RUN_ALL_TESTS();
}
