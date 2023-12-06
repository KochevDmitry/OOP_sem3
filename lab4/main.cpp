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
    Rhombus<float> a(a1, a2, a3, a4);
    std::cout<< &a <<std::endl;
    float c;
    c = double(a);
    std::cout<< c <<std::endl;
    std::pair<float, float> d = a.center();
    std::cout<< d.first << " "<< d.second <<std::endl;
    Rhombus<float> b;
    // std::cin>>b;
    // std::cout<< &b <<std::endl;
    Pentagon<float> ppp(a1, a2, a3, a4, a5);
    d = ppp.center();
    std::cout<< d.first << " "<< d.second <<std::endl;
    Hexagon<float> hhh(a1, a2, a3, a4, a5, a6);
    d = hhh.center();
    std::cout<< d.first << " "<< d.second <<std::endl;
    // Rhombus<float> k;
    // k = a;
    // std::cout<<k<<std::endl;
    // bool flag = (k == a);
    // std::cout<<flag<<std::endl;

    // Pentagon<float>* PPP = &ppp;
    // Hexagon<float>* HHH = &hhh;
    std::shared_ptr<Pentagon<float>> smartppp = std::make_shared<Pentagon<float>>(a1, a2, a3, a4, a5);
    std::shared_ptr<Hexagon<float>> smarthhh = std::make_shared<Hexagon<float>>(a1, a2, a3, a4, a5, a6);
    std::cout<<"ВОТ тут\n"<<smartppp;

    FigureArray<float> *array = create_arr<float>();
    add_figure(array, smartppp);
    add_figure(array, smarthhh);
    std::cout<<double(ppp)<<std::endl;
    std::cout<<double(hhh)<<std::endl;
    std::cout<<"Сумма_площадей!!: "<<sum_area(array)<<std::endl;

    rm_figure(array, 0);
    std::cout<<"\nСумма_площадей: "<<sum_area(array)<<std::endl;
    rm_arr(array);

    // Rhombus<float> new_romb;
    // std::cin >> new_romb;
    // std::cout<<&new_romb;

}
