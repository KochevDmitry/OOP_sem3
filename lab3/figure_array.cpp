
#include "figure_array.h"

FigureArray* create_arr() {
    FigureArray *strct = new FigureArray;
    strct->arr = new Figure* [10];
    strct->size = 0;
    strct->capacity = 10;
    return strct;
}

void increase_size(FigureArray *strct) {
    Figure **new_arr = new Figure* [strct->capacity + 10];
    for (int i = 0; i < strct->size; i++) {
        new_arr[i] = strct->arr[i];
    }
    delete [] strct->arr;
    strct->arr = new_arr;
    strct->capacity += 10;
}

void add_figure(FigureArray* strct, Figure* figure) {
    if (strct->size == strct->capacity) {
        increase_size(strct);
    }
    strct->arr[strct->size] = &(*figure);
    strct->size++;
}

double sum_area(FigureArray *strct) {
    float sum = 0;
    for (int i = 0; i < strct->size; i++) {
        sum += double(*(strct->arr[i]));
    }
    return sum;
}

// Figure* fg = &sqaure;

// Figure **rm_figure(FigureArray *strct, int index) {
//     Figure **new_arr = new Figure* [strct->capacity];
//     int flag = 0;
//     for (int i = 0; i < strct->size; i++) {
//         if (i == index) {
//             flag = 1;
//             continue;
//         }
//         new_arr[i - flag] = strct->arr[i];
//     }
//     delete [] strct->arr;
//     return new_arr;
// }

void rm_arr(FigureArray *strct) {
    strct->capacity = 0;
    strct->size = 0;
    delete [] strct->arr;
    strct->arr = nullptr;
    delete [] strct;
    strct = nullptr;
}
