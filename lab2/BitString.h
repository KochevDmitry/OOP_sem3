#pragma once

#include <iostream>
#include <exception>
#include <cstring>

class BitString{
    public:
         BitString();
         BitString(int valueLength);
         BitString(int valueLength, unsigned char* newArray);
         BitString(BitString& other);
         void SetStringAndLength(int valueLength, unsigned char* newArray);
         void SetBit(unsigned int index, unsigned char value);
         unsigned char* GetString();
         int GetLength();
         unsigned char GetBit(unsigned int index);
         BitString operator^(BitString& other);
         BitString operator&(BitString& other);
         BitString operator|(BitString& other);
         BitString operator~();
         //  void Print(); //пример из гитхаб
         std::ostream &Print(std::ostream &os);
         ~BitString();
    
    private:
        unsigned char* array;
        int length;
};
