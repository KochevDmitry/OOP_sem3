#include "rhombus.h"

        Rhombus::Rhombus(){
            angles = 4;
            points = new std::pair<float, float>[4];
        }

        Rhombus::Rhombus(std::pair<float, float>& p1, std::pair<float, float>& p2, 
                            std::pair<float, float>& p3, std::pair<float, float>& p4){
            angles = 4;
            points = new std::pair<float, float>[4];
            points[0] = p1;
            points[1] = p2;
            points[2] = p3;
            points[3] = p4;
        }

        Rhombus::~Rhombus(){
            angles = 0;
            delete[] points;
            points = nullptr;
        }

        Rhombus::operator double() const {
            if (angles == 0){
                return 0.0;
            }
            float d1_start = (points[0].first - points[2].first)*(points[0].first - points[2].first)+
                            (points[0].second - points[2].second)*(points[0].second - points[2].second);
            if (d1_start < 0) 
                d1_start *= -1;
            float d1 = sqrt(d1_start);
            float d2_start = (points[1].first - points[3].first)*(points[1].first - points[3].first)+
                            (points[1].second - points[3].second)*(points[1].second - points[3].second);
            if (d2_start < 0) 
                d2_start *= -1;
            float d2 = sqrt(d2_start);
            float result = 0.5 * d1 * d2;
            return result;
        }
        

