#include <iostream>
#include <utility>
#include "rhombus.h"
#include "pentagon.h"
#include "hexagon.h"
#include "figure.h"
#include "figure_array.h"


int main(){
    std::pair<float, float> a1(1, 1);
    std::pair<float, float> a2(2, 3);
    std::pair<float, float> a3(3, 1);
    std::pair<float, float> a4(2, -1);
    std::pair<float, float> a5(8, 9);
    std::pair<float, float> a6(10, 11);
    Rhombus a(a1, a2, a3, a4);
    std::cout<< &a <<std::endl;
    float c;
    c = double(a);
    std::cout<< c <<std::endl;
    std::pair<float, float> d = a.center();
    std::cout<< d.first << " "<< d.second <<std::endl;
    Rhombus b;
    // std::cin>>b;
    // std::cout<< &b <<std::endl;
    Pentagon ppp(a1, a2, a3, a4, a5);
    std::cout<<&ppp<<std::endl;
    Hexagon hhh(a1, a2, a3, a4, a5, a6);
    std::cout<<&hhh<<std::endl;
    Rhombus k;
    k = a;
    std::cout<<k<<std::endl;
    bool flag = (k == a);
    std::cout<<flag<<std::endl;

    FigureArray *array = create_arr();
    add_figure(array, &ppp);
    add_figure(array, &hhh);
    std::cout<<double(ppp)<<std::endl;
    std::cout<<double(hhh)<<std::endl;
    std::cout<<sum_area(array)<<std::endl;

}
