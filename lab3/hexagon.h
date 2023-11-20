#pragma once
#include "figure.h"

class Hexagon: public Figure {
    public:
        Hexagon();
        Hexagon(std::pair<float, float>& p1, std::pair<float, float>& p2, 
                                std::pair<float, float>& p3, std::pair<float, float>& p4,
                                        std::pair<float, float>& p5, std::pair<float, float>& p6);
                                        
        virtual operator double() const override;

        ~Hexagon();
};
