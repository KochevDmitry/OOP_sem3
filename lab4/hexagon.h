#pragma once
#include "figure.h"

template<Number T>
class Hexagon: public Figure<T> {
    public:
        Hexagon(){
            this->angles = 6;
            this->points.reset(new std::pair<T, T>[6]);
        }

        Hexagon(std::pair<T, T>& p1, std::pair<T, T>& p2, 
                                std::pair<T, T>& p3, std::pair<T, T>& p4,
                                        std::pair<T, T>& p5, std::pair<T, T>& p6){
            this->angles = 6;
            this->points.reset(new std::pair<T, T>[6]);
            this->points[0] = p1;
            this->points[1] = p2;
            this->points[2] = p3;
            this->points[3] = p4;
            this->points[4] = p5;
            this->points[5] = p6;
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

        ~Hexagon(){
            this->angles = 0;
            this->points = nullptr;
        }
};
