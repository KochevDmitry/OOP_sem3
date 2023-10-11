#include "BitString.h"

int main(){
    BitString first;
    std::cout<<first.GetLength()<<std::endl;
    first.Print();
    BitString second(10);
    std::cout<<second.GetLength()<<std::endl;
    second.Print();
    unsigned char* str1 = new unsigned char[6];
    str1[0] = '1';
    str1[1] = '1';
    str1[2] = '1';
    str1[3] = '0';
    str1[4] = '1';
    str1[5] = '0';
    BitString a(6, str1);
    unsigned char* str2 = new unsigned char[6];
    str2[0] = '1';
    str2[1] = '0';
    str2[2] = '0';
    str2[3] = '1';
    str2[4] = '1';
    str2[5] = '0';
    BitString c(6, str2);
    a.Print();
    c.Print();
    BitString Band = a&c;
    BitString Bor = a|c;
    BitString Bxor = a^c;
    BitString Bno = ~a;
    Band.Print();
    Bor.Print();
    Bxor.Print();
    Bno.Print();
    BitString new_string(10);
    new_string.SetBit(0, '1');
    new_string.SetBit(9, '1');
    new_string.Print();
    unsigned char bit = new_string.GetBit(9);
    std::cout<<bit<<std::endl;
}