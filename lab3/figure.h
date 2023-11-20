#pragma once
#include <iostream>
#include <utility>
#include <math.h>

class Figure{

    friend std::istream& operator>>(std::istream& is, Figure& figure);
    friend std::ostream& operator<<(std::ostream& os, Figure* figure);

    public:
        virtual operator double() const = 0;
        //bool is_correct();
        virtual ~Figure() = default;
        std::pair<float, float> center();

        Figure& operator=(Figure& other);
        Figure& operator=(Figure&& other);
        bool operator==(const Figure& other);

    protected:
        int angles;
        std::pair<float, float>* points;
};
