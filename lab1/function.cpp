#include <iostream>
#include <string>

std::string replaceNthCharacter(std::string text, int n, char old_value, char new_value) {
    if (n <= 0 || n > text.length()) {
        return text;
    }

    int s = 0;

    for (int i = 0; i < text.length(); i += 1) {
        if (text[i] == old_value ) {
            s += 1;
            if (s % n == 0) {
                text[i] = new_value;
            }
        }
    }

    return text;
}