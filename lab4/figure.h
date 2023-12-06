#pragma once
#include <iostream>
#include <utility>
#include <math.h>
#include <concepts>
#include <memory>
#include <exception>
#include <cstring>

template <typename T>
concept Number = std::is_arithmetic_v<T>;

template<Number T>
class Figure{
    template <Number F>
    friend std::istream& operator>>(std::istream& is, Figure<F>& figure);
    template <Number F>
    friend std::ostream& operator<<(std::ostream& os, Figure<F>* figure);

    public:
        virtual operator double() const = 0;
        //bool is_correct();
        virtual ~Figure() = default;
        
        std::pair<T, T> center(){
            T x_sum = 0, y_sum = 0;
            for (int i = 0; i < angles; i++) {
                x_sum += points[i].first;
                y_sum += points[i].second;
            }
            std::pair<T, T> cnt(x_sum / angles, y_sum / angles);
            return cnt;
        }

        Figure<T>& operator=(Figure<T>& other){
            if (!(this == &other)) {
                for (int i = 0; i < angles; i++) {
                    this->points[i] = other.points[i];
                }
                this->angles = other.angles;
            }
            return *this;                      
        }

        Figure<T>& operator=(Figure<T>&& other){
            if (!(this == &other)) {
                for (int i = 0; i < angles; i++) {
                    this->points[i] = std::move(other.points[i]);
                }
                this->angles = other.angles;
                delete[] points;
            }
            return *this;
        }

        bool operator==(const Figure<T>& other){
            return static_cast<T>(*this) == static_cast<T>(other);
        }

    protected:
        int angles;
        std::shared_ptr<std::pair<T, T>[]> points;
};

template <Number T>
std::istream& operator>>(std::istream& is, Figure<T>& figure) { // inline
            for (int i = 0; i < figure.angles; i++) {
                is >> figure.points[i].first >> figure.points[i].second;
            }
            return is;
        }

template <Number T>
std::ostream& operator<<(std::ostream& os, Figure<T> *figure) { // inline
    for (int i = 0; i < figure -> angles; i++) {
        os << i + 1 << ": " << figure -> points[i].first << " "<<  figure -> points[i].second <<std::endl;
    }
    return os;
}


// g++ -std=c++20 main.cpp