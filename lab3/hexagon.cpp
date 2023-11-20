#include "hexagon.h"

        Hexagon::Hexagon(){
            angles = 6;
            points = new std::pair<float, float>[6];
        }

        Hexagon::Hexagon(std::pair<float, float>& p1, std::pair<float, float>& p2, 
                            std::pair<float, float>& p3, std::pair<float, float>& p4, 
                                    std::pair<float, float>& p5, std::pair<float, float>& p6){
            angles = 6;
            points = new std::pair<float, float>[6];
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;
            points[3] = p4;
            points[4] = p5;
            points[5] = p6;
        }

        Hexagon::~Hexagon(){
            angles = 0;
            delete[] points;
            points = nullptr;
        }

        Hexagon::operator double() const{
            if (angles == 0){
                return 0.0;
            }
            float area = 0;
            for (int i = 0; i < angles; i++) {
                area += points[i].first * points[(i + 1) % angles].second - points[(i + 1) % angles].first * points[i].second;
            }
            if (area < 0)
                area *= -1;
            return 0.5 * area;
        }

