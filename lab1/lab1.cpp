#include <iostream>
#include "function.h"
#include <string>

int main() {
    int n;
    char old_value;
    char new_value;
    std::string text;
    std::cin>>n>>old_value>>new_value;
    std::cin.ignore();
    std::getline(std::cin, text);
    std::string result = replaceNthCharacter(text, n, old_value, new_value);
    std::cout << result << std::endl;

    return 0;
}
