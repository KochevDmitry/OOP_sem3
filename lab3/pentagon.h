#pragma once
#include "figure.h"

class Pentagon: public Figure {
    public:
        Pentagon();
        Pentagon(std::pair<float, float>& p1, std::pair<float, float>& p2, 
                                std::pair<float, float>& p3, std::pair<float, float>& p4,
                                        std::pair<float, float>& p5);

        virtual operator double() const override;

        ~Pentagon();
};
