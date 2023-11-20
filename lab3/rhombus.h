#pragma once
#include "figure.h"

class Rhombus: public Figure {
    public:
        Rhombus();
        Rhombus(std::pair<float, float>& p1, std::pair<float, float>& p2, 
                                std::pair<float, float>& p3, std::pair<float, float>& p4);

        virtual operator double() const override;

        ~Rhombus();
};