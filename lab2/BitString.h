#pragma once

#include <iostream>

class BitString{
    public:
         BitString();
         BitString(int valueLength);
         BitString(int valueLength, unsigned char* newArray);
         void SetStringAndLength(int valueLength, unsigned char* newArray);
         void SetBit(unsigned int index, unsigned char value);
         unsigned char* GetString();
         int GetLength();
         unsigned char GetBit(unsigned int index);
         BitString operator^(BitString& other);
         BitString operator&(BitString& other);
         BitString operator|(BitString& other);
         BitString operator~();
         void Print();
         ~BitString();
    
    private:
        unsigned char* array;
        int length;
};