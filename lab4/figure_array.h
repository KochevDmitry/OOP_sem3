#pragma once
#include "rhombus.h"
#include "hexagon.h"
#include "pentagon.h"
#include <vector>
#include "figure.h"

template<Number T>
struct FigureArray{
    std::shared_ptr<Figure<T>>* arr;
    int size;
    int capacity;
};

template <Number T>
FigureArray<T>* create_arr() {
    FigureArray<T>* strct = new FigureArray<T>;
    strct->arr = new std::shared_ptr<Figure<T>>[10];
    strct->size = 0;
    strct->capacity = 10;
    return strct;
}

template <Number T>
double sum_area(FigureArray<T>* strct) {
    double sum = 0;
    for (size_t i = 0; i < strct->size; i++) {
        sum += double(*(strct->arr[i]));
    }
    return sum;
}

template <Number T>
void increase_size(FigureArray<T>* strct) {
    std::shared_ptr<Figure<T>[]> new_arr(new Figure<T>[strct->capacity + 10], std::default_delete<Figure<T>[]>{});
    for (size_t i = 0; i < strct->size; i++) {
        new_arr[i] = strct->arr[i];
    }
    strct->capacity += 10;
}

template <Number T>
void add_figure(FigureArray<T>* strct, std::shared_ptr<Figure<T>> figure) {
    if (strct->size == strct->capacity) {
        increase_size(strct);
    }
    strct->arr[strct->size] = &(*figure);
    strct->size++;
}

template <Number T>
void rm_arr(FigureArray<T>* strct) {
// Умные указатели сами управляют памятью, не нужно явно удалять
    strct->size = 0;
    strct->capacity = 0;
    delete strct;
}