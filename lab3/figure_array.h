#pragma once
#include "rhombus.h"
#include "hexagon.h"
#include "pentagon.h"
#include "figure.h"

typedef struct {
    Figure **arr;
    int size;
    int capacity;
} FigureArray;

FigureArray *create_arr();
void add_figure(FigureArray *arr, Figure* figure);
double sum_area(FigureArray *arr);
void increase_size(FigureArray *arr);
Figure **rm_figure(FigureArray *arr, int index);
void rm_arr(FigureArray *arr);