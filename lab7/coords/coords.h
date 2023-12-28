#pragma once

#include <iostream>
#include <string>

template <typename T>
concept Number = (std::integral<T> || std::floating_point<T>) 
                 && !std::same_as<T, bool>
                 && !std::same_as<T, char>;
template <Number T>
class Coords{
    template<class F>
    friend Coords<F> operator+(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend Coords<F> operator-(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator==(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator!=(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator>(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator<(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator>=(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend bool operator<=(const Coords<F>& left, const Coords<F>& right);
    template<class F>
    friend std::istream& operator>>(std::istream& is, Coords<F>& p);
    template<class F>
    friend std::ostream& operator<<(std::ostream& os, const Coords<F>& p);

public:
    Coords();
    Coords(T x_, T y_);
    Coords(const Coords<T>& other);

    ~Coords() = default;

    Coords<T>& operator=(const Coords<T>& right);

    T x;
    T y;
};

template<class T>
Coords<T>::Coords() : x{0}, y{0} {}

template<class T>
Coords<T>::Coords(T x_, T y_): x{x_}, y{y_} {}

template<class T>
Coords<T>::Coords(const Coords<T>& other) : x(other.x), y(other.y) {}

template<class T>
Coords<T> operator+(const Coords<T>& left, const Coords<T>& right){
    return Coords<T>(left.x + right.x, left.y + right.y);
}

template<class T>
Coords<T> operator-(const Coords<T>& left, const Coords<T>& right){
    return Coords<T>(left.x - right.x, left.y - right.y);
}

template<class T>
bool operator==(const Coords<T>& left, const Coords<T>& right){
    return (left.x == right.x) && (left.y == right.y);
}

template<class T>
bool operator!=(const Coords<T>& left, const Coords<T>& right){
    return (left.x != right.x) || (left.y != right.y);
}

template<class T>
Coords<T>& Coords<T>::operator=(const Coords<T>& right){
    if (this != &right) {
        x = right.x;
        y = right.y;
    }
    return *this;
}

template<class T>
bool operator<(const Coords<T>& left, const Coords<T>& right) {
    return (left.x < right.x) || ((left.x == right.x) && (left.y < right.y));
}

template<class T>
bool operator>(const Coords<T>& left, const Coords<T>& right) {
    return (left.x > right.x) || ((left.x == right.x) && (left.y > right.y));
}

template<class T>
bool operator<=(const Coords<T>& left, const Coords<T>& right) {
    return (left < right) || (left == right);
}

template<class T>
bool operator>=(const Coords<T>& left, const Coords<T>& right) {
    return (left > right) || (left == right);
}

template<class T>
std::istream& operator>>(std::istream& is, Coords<T>& p){
    T x, y;
    std::cout << "Write 'x' and 'y':" << std::endl;
    is >> x >> y;

    p.x = x;
    p.y = y;
    return is;
}

template<class T>
std::ostream& operator<<(std::ostream& os, const Coords<T>& p){
    os << "(x: " << p.x << "; y: " << p.y << ")";
    return os;
}