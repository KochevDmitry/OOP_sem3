#pragma once
#include "figure.h"

template<Number T>
class Rhombus: public Figure<T> {
    public:
        Rhombus(){
            this->angles = 4;
            this->points.reset(new std::pair<T, T>[4]);
        }

        Rhombus(std::pair<T, T>& p1, std::pair<T, T>& p2, 
                                std::pair<T, T>& p3, std::pair<T, T>& p4){
            this->angles = 4;
            this->points.reset(new std::pair<T, T>[4]);
            this->points[0] = p1;
            this->points[1] = p2;
            this->points[2] = p3;
            this->points[3] = p4;
        }

        virtual operator double() const override{
            if (this->angles == 0){
                return 0.0;
            }
            T d1_start = (this->points[0].first - this->points[2].first)*(this->points[0].first - this->points[2].first)+
                            (this->points[0].second - this->points[2].second)*(this->points[0].second - this->points[2].second);
            if (d1_start < 0) 
                d1_start *= -1;
            T d1 = sqrt(d1_start);
            T d2_start = (this->points[1].first - this->points[3].first)*(this->points[1].first - this->points[3].first)+
                            (this->points[1].second - this->points[3].second)*(this->points[1].second - this->points[3].second);
            if (d2_start < 0) 
                d2_start *= -1;
            T d2 = sqrt(d2_start);
            T result = 0.5 * d1 * d2;
            return result;
        }

        ~Rhombus(){
            this->angles = 0;
            this->points = nullptr;
        }
};