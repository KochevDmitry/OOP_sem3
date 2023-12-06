#pragma once
#include "figure.h"

template<Number T>
class Pentagon: public Figure<T> {
    public:
        Pentagon(){
            this->angles = 5;
            this->points.reset(new std::pair<T, T>[5]);
        }
        Pentagon(std::pair<T, T>& p1, std::pair<T, T>& p2, 
                                std::pair<T, T>& p3, std::pair<T, T>& p4,
                                        std::pair<T, T>& p5){
            this->angles = 5;
            this->points.reset(new std::pair<T, T>[5]);
            this->points[0] = p1;
            this->points[1] = p2;
            this->points[2] = p3;
            this->points[3] = p4;
            this->points[4] = p5;
        }

        virtual operator double() const override{
            if (this->angles == 0){
                return 0.0;
            }
            T area = 0;
            for (int i = 0; i < this->angles; i++) {
                area += this->points[i].first * this->points[(i + 1) % this->angles].second - this->points[(i + 1) % this->angles].first * this->points[i].second;
            }
            if (area < 0)
                area *= -1;
            return 0.5 * area;
        }


        ~Pentagon(){
            this->angles = 0;
            this->points = nullptr;
        }
};
