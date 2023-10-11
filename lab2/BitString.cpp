#include "BitString.h"

        BitString::BitString(){
            length = 0;
            array = nullptr;
        }

        BitString::BitString(int valueLength){
            length = valueLength;
            array = new unsigned char[length];
            for (int i = 0; i < length; i++)
                array[i] = '0';
        }

        BitString::BitString(int valueLength, unsigned char* newArray){
            array = newArray;
            length = valueLength;
        }

        BitString::~BitString() {
            delete[] array;
            array = nullptr;
        }  

        void BitString::SetStringAndLength(int valueLength, unsigned char* newArray){
            delete[] array;
            array = newArray;
            length = valueLength;
        }

        void BitString::SetBit(unsigned int index, unsigned char value){
            if (index < length && (value == '0' || value == '1'))
                array[index] = value;
        }

        unsigned char* BitString::GetString(){
            return array;
        }

        int BitString::GetLength(){
            return length;
        }

        unsigned char BitString::GetBit(unsigned int index){
            if (index < length)
                return array[index];
        }

        BitString BitString::operator^(BitString& other){ //XOR
            int max_length = 0, min_length = 0;
            unsigned char *max_array;
            unsigned char *min_array;
            if (length >= other.GetLength()){
                max_length = length;
                max_array = array;
                min_length = other.GetLength();
                min_array = other.GetString();
            }
            else{
                max_length = other.GetLength();
                max_array = other.GetString();
                min_length = length;
                min_array = array;
            }
            int difference = max_length - min_length;
            unsigned char *array_new = new unsigned char[max_length];
            for (int i = max_length - 1; i >= 0; i--){
                if (i - difference >= 0){
                    if (max_array[i] == min_array[i-difference])
                        array_new[i] = '0';
                    else array_new[i] = '1';
                }
                else if (max_array[i] == '1')
                        array_new[i] = '1'; 
                    else array_new[i] = '0';    
            }
            return BitString(max_length, array_new);
        }

        
        BitString BitString::operator&(BitString& other){ //AND
            int max_length = 0, min_length = 0;
            unsigned char *max_array;
            unsigned char *min_array;
            if (length >= other.GetLength()){
                max_length = length;
                max_array = array;
                min_length = other.GetLength();
                min_array = other.GetString();
            }
            else{
                max_length = other.GetLength();
                max_array = other.GetString();
                min_length = length;
                min_array = array;
            }
            int difference = max_length - min_length;
            unsigned char *array_new = new unsigned char[max_length];
            for (int i = max_length - 1; i >= 0; i--){
                if (i - difference >= 0){
                    if (max_array[i] == min_array[i-difference] && max_array[i] == '1')
                        array_new[i] = '1';
                    else array_new[i] = '0';
                }
                else array_new[i] = '0';    
            }
            return BitString(max_length, array_new);
        }

        BitString BitString::operator|(BitString& other){ //OR
            int max_length = 0, min_length = 0;
            unsigned char *max_array;
            unsigned char *min_array;
            if (length >= other.GetLength()){
                max_length = length;
                max_array = array;
                min_length = other.GetLength();
                min_array = other.GetString();
            }
            else{
                max_length = other.GetLength();
                max_array = other.GetString();
                min_length = length;
                min_array = array;
            }
            int difference = max_length - min_length;
            unsigned char *array_new = new unsigned char[max_length];
            for (int i = max_length - 1; i >= 0; i--){
                if (i - difference >= 0){
                    if (max_array[i] == min_array[i-difference] && max_array[i] == '0')
                        array_new[i] = '0';
                    else array_new[i] = '1';
                }
                else if (max_array[i] == '1')
                        array_new[i] = '1'; 
                    else array_new[i] = '0';     
            }
            return BitString(max_length, array_new);
        }

        BitString BitString::operator~() { //NOT
           unsigned char* new_array = new unsigned char[length];
           for (int i = 0; i < length; i++){
                if (array[i] == '0')
                    new_array[i] = '1';
                else new_array[i] = '0';
           }

            return BitString(length, new_array);
        }
        
        void BitString::Print() {
            for (int i = 0; i < length; i++)
                std::cout<<array[i]<<" ";
            std::cout<<std::endl;
        }